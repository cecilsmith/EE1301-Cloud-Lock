# EE1301-Cloud-Lock

## Team Members

* Nathanael Smith - *smi02356*
* Rejat Krishnan - *krish354*
* Sam Chea - *chea0073*


## Project Overview

Our project is to make an IOT enabled lock that could be controlled by a smartphone. A user would be able to scan an RFID keycard or enter a password on their (cloud-connected) cell phone to unlock the lock. The advantage of this is that a user can unlock their door without a physical key or lock the door if they forgot to after he/she has left the house. There are two actuators used in the form of a two servo motors, two sensors in the form of an RFID reader and a potentiometer for a more accessible door, and the Particle Photon as the microcontroller. The user can use a web application along with Particle cloud functions to send signals from a phone to the Cloud to the door. IFTTT functionality would allow the Photon to communicate with the user (if the device loses connectivity with the cloud, the lock is unlocked/locked, etc.). However, it should be noted that, the IFTTT functionality is not documented comprehensively on this GitHub page.

## Project Files

The project has been split into three main groups [CAD](/CAD), [Code](/Code), and [Hardware](/Hardware). Each group has its own sub-directory.

1. [CAD](/CAD) contains all the 3D models and physical designs
2. [Code](/Code) contains all the code for the project.
    * [/Photon](/Code/Photon) contains the code for the Particle Photon
    * [/Web](/Code/Web) contains the HTML code for Cloud connectivity from one's device to communicate with the Photon.
3. [Hardware](/Hardware) contains the circuit diagram and specifications of each sensor and actuator when applicable. 

## Hardware Overview

### Parts (with Amazon links when applicable) 

* [MFRC-522 RFID](https://www.amazon.com/HiLetgo-3pcs-RFID-Kit-Raspberry/dp/B07VLDSYRW/ref=sr_1_4?crid=18DCORKSJPHS6&keywords=mfrc522&qid=1682445511&sprefix=mfrc522%2Caps%2C181&sr=8-4) sensor: Used to read/write to keycards
* [Servos](https://www.amazon.com/Micro-Servos-Helicopter-Airplane-Controls/dp/B07MLR1498/ref=sr_1_9?crid=22NEKGHONQT6A&keywords=servo&qid=1682445555&sprefix=servo%2Caps%2C169&sr=8-9&th=1) (x2): Used to lock/unlock the lock and open/close the door
* [Potentiometer](https://www.amazon.com/MCIGICM-Breadboard-Trim-Potentiometer-Arduino/dp/B07S69443J/ref=sr_1_5?crid=3V138KBELQCXL&keywords=potentiometer&qid=1682445588&sprefix=potentiometer%2Caps%2C226&sr=8-5): Used to control the state of the door operations
* [Particle Photon](https://docs.particle.io/photon/): Embedded deviced used to control all functions and send/recieve Cloud data

### Circuit Diagram

TBA

## Project Usage and Download

For information on how to download/use this repository, visit our [Git Manual](/GitManual.md).
