#include "Particle.h"
#include "RFID.h"

SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(SEMI_AUTOMATIC);

// SERVO FOR LOCK IS D2
// SERVO FOR DOOR IS D3
// POTENTIOMETER ON PIN A1

/* Define the pins used for the SS (SDA) and RST (reset) pins for BOTH hardware and software SPI */
/* Change as required */
#define SS_PIN A2  // Same pin used as hardware SPI (SS)
#define RST_PIN D4

/* Define the pins used for the DATA OUT (MOSI), DATA IN (MISO) and CLOCK (SCK) pins for SOFTWARE SPI ONLY */
/* Change as required and may be same as hardware SPI as listed in comments */
#define MOSI_PIN A5 // D3 // hardware SPI: A5
#define MISO_PIN A4 // D4 //     "     " : A4
#define SCK_PIN A3  // D5 //     "     " : A3

/* Create an instance of the RFID library */
#if defined(_USE_SOFT_SPI_)
RFID RC522(SS_PIN, RST_PIN, MOSI_PIN, MISO_PIN, SCK_PIN); // Software SPI
#else
RFID RC522(SS_PIN, RST_PIN); // Hardware SPI
#endif

int doorClosePos = 48, doorOpenPos = 134;

//-------------------------------------------

// Class declaration here because multi-file importing was not working
class Lock
{

public:
    Lock(unsigned int closedPOS, unsigned int openPOS);
    void begin(int servoPin);
    void secure();
    void unlock();
    bool getLockState();
    int servoRead();

protected:
    bool isLocked = false; // true locked, false unlocked
    unsigned int lockedPOS, unlockedPOS;
    Servo lockServo;
};

Lock::Lock(unsigned int closedPOS, unsigned int openPOS)
{
    lockedPOS = closedPOS;
    unlockedPOS = openPOS;
}

void Lock::begin(int servoPin)
{
    Lock::lockServo.attach(servoPin);
}

void Lock::secure()
{
    if (isLocked == false)
    {
        Lock::lockServo.write(lockedPOS);
        isLocked = true;
    }
}

void Lock::unlock()
{
    if (isLocked == true)
    {
        Lock::lockServo.write(unlockedPOS);
        isLocked = false;
    }
}

bool Lock::getLockState()
{
    return isLocked;
}

int Lock::servoRead()
{
    return lockServo.read();
}

//-------------------------------------------

Lock lock1(90, 180);
bool handicapMode = false;
int potentiometerReading;
Servo doorServo;

String Password = "testPassword";
uint8_t keyCard[5] = {234, 199, 97, 191, 243};

bool LockState, doorState;
uint32_t lastReadTime = 0;
uint32_t timeSinceLastCardUpdate = 0;

//-------------------------------------------

int checkIOTPassword(String inputString)
{
    // If password matches:
    if (inputString == Password)
    {
        // Lock if unlocked
        if (lock1.getLockState() == false)
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
    return 1;
}

//-------------------------------------------

void setup()
{
    LockState = lock1.getLockState();
    Particle.variable("cV_isDoorOpen", doorState);
    Particle.variable("cV_isLocked", LockState);
    Particle.function("cF_lockForm", checkIOTPassword);
    Particle.connect();

    lock1.begin(D2);
    doorServo.attach(D3);

    // Potentiometer
    pinMode(A1, INPUT);

    // For MFRC
#if !defined(_USE_SOFT_SPI_)
    /* Enable the HW SPI interface */
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    SPI.begin();
#endif

    /* Initialise the RFID reader */
    RC522.init();

    lock1.unlock();
}

void loop()
{
    if (Particle.connected() == false)
    {
        Particle.connect();
    }

    LockState = lock1.getLockState();

    //-----------------
    /* Has a card been detected? */

    if ((millis() - lastReadTime) > 250)
    {
        // Analog read of potentiometer for auto-door opening mode
        if (analogRead(A1) > 512)
        {
            handicapMode = true;
        }
        else
        {
            handicapMode = false;
        }

        // --------------------
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

    Particle.process();
}
