# Code

## [MFRC522](./RC522)

The card reader that we are using is of the MFRC522 chipset. Currently, there is not a native solution for the Particle family to use this sensor. Thus, a custom library has been made to interface it with the Spark Core: [RC522 Library](https://github.com/pkourany/RC522_RFID)

The MFRC522 datasheet can be found [here](https://pdf1.alldatasheet.com/datasheet-pdf/view/227840/NXP/RC522.html).

More information on the SPI interface for the Particle boards can be found here [on DigiKey](https://www.digikey.com/en/maker/blogs/2019/how-to-use-spi-on-the-particle-photon) and [on Particle.io](https://docs.particle.io/reference/device-os/api/spi/spi/).

Particle also has a handy manual for porting libraries found [here](https://docs.particle.io/firmware/best-practices/libraries/).

## 

