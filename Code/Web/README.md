# Web
<a href="https://ee1301-cloud-lock.pages.dev">
<img alt="QR Code to the Webpage" src="https://user-images.githubusercontent.com/19243227/234263369-41c31e79-d60b-4de8-b06b-b4c7a5888636.png"></img>
</a>

A working [prototype](https://ee1301-cloud-lock.pages.dev).

## Overview

This folder contains the elements of the web application. To run, download the folder and open `index.html` in the browser of your choice.

<img src="https://user-images.githubusercontent.com/19243227/234357485-01e98943-4a46-47be-8bce-d8a0f58fe6df.png">


A JSON request is made each second to the Particle Cloud to get the `LockState` variable. A form is below it to submit a password that to toggle lock/unlock states. The password entered is checked locally on the Photon board through a comparison of strings. 

Future revisons could include a way to update/reset the password on the Photon board--and store that password in non-volatile memory (EEPROM). Further improvements could be made to the website and to firmware to update EEPROM to store accepted MFRC serial numbers. 

## Content

* [`index.html`](index.html) contains the HTML code for the webpage
* [`styles.css`](styles.css) contains the CSS for the webpage

