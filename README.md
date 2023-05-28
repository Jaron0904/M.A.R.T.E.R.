# M.A.R.T.E.R.
This repository contains all code used for the development of the M.A.R.T.E.R. tool. All code was written in C++ with the intention on being used with Arduino Nano microcontrollers. The system itself is designed to test electrical wiring in a construction setting. The workflow that was initially intended to be built on the OLED-screen can be found on ProtoPie: https://cloud.protopie.io/p/e0336c8a9235a06a891ad1d0?ui=true&scaleToFit=true&enableHotspotHints=true&cursorType=touch&mockup=true&bgColor=%23F5F5F5&playSpeed=1&playerAppPopup=true

This repository contains the following iterations:

## M.A.R.M.O.T. 
This is the first version and was only meant to navigate a rudimentairy menu using four buttons. Aditionally two LED's were added to provide feedback about the system status

## M.A.R.T.E.R.
This second iteration is already functional but still requires the user to manually start tests.

Bugs:
- quickly repeating the test results in errors
- deducting cables is delayed in comparison to the addition

## S-M.A.R.T.E.R.
The third iteration automatically checks how many cables are connected and only updates the screen when a change has been made

Bugs:
- deducting cables is delayed in comparison to the addition

## N.E.R.T.S.
A variation on S-M.A.R.T.E.R. that gives feedback to the user with LED's. This variation doesn't need an OLED display to display how many cables are working correctly. 
This means that a corresponding amount of LEDs has to be added to the arduino according to the amount of cables that have to be tested.

Bugs:
- Sometimes faulty feedback is returned due to poor soldering connections or badly insulated cables.

## FINALE
Final tweaks and updates to both the software and hardware to be implimented in the final prototype. 
The power supply has been changed to a replaceable 9V battery.
An LED has also been added so that the head as well so it can also be used as a flashlight.

#### Author | Jaron Igodt - senior programmer at M.A.R.T.E.R. 




