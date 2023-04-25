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

### Parts

TBA

### Circuit Diagram

TBA

## Project Usage and Download

For information on how to download/use this repository, visit our [Git Manual](/GitManual.md).
