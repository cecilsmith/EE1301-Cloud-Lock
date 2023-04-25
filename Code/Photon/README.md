# Code

## Overview

The code in this project utilizes a `Lock` class to create a `Lock` object to control the state of our lock without changing the local variables in an unsafe way. There are few (more complex) functions that are necessary to take into account the automated door, but the code is set up in such a way that it would be relatively easy to contol multiple `Lock` objects. 

Particle Cloud variables and functions were also used to passthrough the password and update the visible state of the lock for the user.

An MFRC522 sensor was also used to have a local way of unlocking/locking the lock through a keycard. 

## Servos

Two servos were used in the project. One to control the door and one to control the lock. When `handicapMode` is active, the door servo will actuate after the lock mechanism. Otherwise, the lock will be the only component that actuates. 

To view the CAD design of the device in its final form, refer to the [CAD folder](../../CAD).

*NOTE: `handicapMode` is controlled by a potentiometer that looks for +/- half of the range, acting as a switch since we did not have access to one when the device was constructed.*


## [MFRC522](./RC522)

The card reader that we are using is of the MFRC522 chipset. Currently, there is not a native solution for the Particle family to use this sensor. Thus, a custom library has been made to interface it with the Spark Core: [RC522 Library](https://github.com/pkourany/RC522_RFID)

The MFRC522 datasheet can be found [here](https://pdf1.alldatasheet.com/datasheet-pdf/view/227840/NXP/RC522.html).

*For troubleshooting, refer to these links:*

 * More information on the SPI interface for the Particle boards can be found here [on DigiKey](https://www.digikey.com/en/maker/blogs/2019/how-to-use-spi-on-the-particle-photon) and [on Particle.io](https://docs.particle.io/reference/device-os/api/spi/spi/).

 * Particle also has a handy manual for porting libraries found [here](https://docs.particle.io/firmware/best-practices/libraries/).

* Others have run into this issue as well, the forum post and answers are [here](https://community.particle.io/t/getting-the-rfid-rc522-to-work-solved/3571/22).


