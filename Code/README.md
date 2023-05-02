# Code

This folder contains all the code for our project. 

* [/Web](/Code/Web) contains the code for the static webpage.
* [/Photon](/Code/Photon) contians all the firmare code, in C++, for the Particle Photon board.

## Web Code

The webpage was written in HTML with a JQuery plugin. API calls to the Particle Cloud are used to fetch data and push new data to the Cloud. 

The following section of code makes an request to the Particle Cloud to get the lock/unlock state every 1 second.
``` javascript
var deviceID = "YOUR_DEVICE_ID";
var accessToken = "YOUR_ACCESS_TOKEN";
var baseURL = "https://api.particle.io/v1/devices/"

var lockedVar = "cV_isLocked"; // your cloud variable name goes here

window.setInterval(function() {
    requestURL = "https://api.particle.io/v1/devices/" + deviceID + "/" + lockedVar + "/?access_token=" + accessToken;
    $.getJSON(requestURL, function(json) {
        if (json.result == true) {
            document.getElementById("lock_state").innerHTML = " Locked";
        } else {
            document.getElementById("lock_state").innerHTML = " Unlocked";
        }
    });
}, 1000);
```

## Photon Code

The firmware on the Photon board is responsible for checking cards read by the MFRC module. 
When a card is read, or the Cloud variable is updated, then a control flow segment of code is run to determine whether to open/close or unlock/lock the door.

The following code is used for reading serial numbers from RFID chips. This is then used to lock/unlock the door.

``` C++
if (RC522.isCard())
        {
            /* If so then get its serial number */
            RC522.readCardSerial();

            Serial.println("Card detected:");

            /* Output the serial number to the UART */
            uint8_t i;
            // Set initial condition of CardReader to have a match
            // If not matching, boolean will be set to false
            bool match = true;
            // Loop through the 5 serial bytes of the RFID Card, if not matching, skip
            for (i = 0; i <= 4; i++)
            {
                Serial.print(RC522.serNum[i]);
                Serial.print(" ");
                if (RC522.serNum[i] != keyCard[i])
                {
                    match = false;
                    return;
                }
            }
            Serial.println();
            // If there is a match and the time has passed
            if (match && ((millis() - timeSinceLastCardUpdate) > 2500))
            {
                // Update time
                timeSinceLastCardUpdate = millis();
                // Lock if unlocked
                if (LockState == false)
                {
                    if (doorServo.read() != doorClosePos)
                    {
                        doorServo.write(doorClosePos);
                    }
                    delay(250);
                    lock1.secure();
                }
                else
                {
                    lock1.unlock();
                    if (handicapMode)
                    {
                        delay(250);
                        doorServo.write(doorOpenPos);
                    }
                }
            }
        }
        else
            Serial.println("Card NOT detected:");
        lastReadTime = millis();
    }
```
