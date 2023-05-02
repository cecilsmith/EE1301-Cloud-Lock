# Hardware

## Schematic

![image](https://github.com/cecilsmith/EE1301-Cloud-Lock/blob/main/Hardware/EE1301-CloudLock-Schematic.tiff)

## Parts (with Amazon links when applicable) 

* [MFRC-522 RFID](https://www.amazon.com/HiLetgo-3pcs-RFID-Kit-Raspberry/dp/B07VLDSYRW/ref=sr_1_4?crid=18DCORKSJPHS6&keywords=mfrc522&qid=1682445511&sprefix=mfrc522%2Caps%2C181&sr=8-4) sensor: Used to read/write to keycards
* [Servos](https://www.amazon.com/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=sr_1_9?crid=22NEKGHONQT6A&keywords=servo&qid=1682445555&sprefix=servo%2Caps%2C169&sr=8-9&th=1) (x2): Used to lock/unlock the lock and open/close the door
* [Potentiometer](https://www.amazon.com/MCIGICM-Breadboard-Trim-Potentiometer-Arduino/dp/B07S69443J/ref=sr_1_5?crid=3V138KBELQCXL&keywords=potentiometer&qid=1682445588&sprefix=potentiometer%2Caps%2C226&sr=8-5): Used to control the state of the door operations
* [Particle Photon](https://docs.particle.io/photon/): Embedded deviced used to control all functions and send/recieve Cloud data

## Libraries Used for Schematic

* [Digi-Key KiCad Library](https://github.com/Digi-Key/digikey-kicad-library/tree/master) by [Digi-Key](https://github.com/Digi-Key) for the Particle Photon board
* [some-kicad-components](https://github.com/DAlexis/some-kicad-components/blob/master/lib/rfid-rc522-module.lib) by [DAlexis](https://github.com/DAlexis) for the MFRC522 component
* Standard KiCad Library for servos and the potentiometer
