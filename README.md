# Make-A-Pede
Arduino library for the [Make-A-Pede](http://makeapede.com)

[Make-A-Pede Android App](https://github.com/Make-A-Pede/Make-A-Pede-Android-App)

# Usage
## Getting Started
Download all three files in this directory and place them in a folder named "MakeAPede". Open MakeAPede.ino in the Arduino IDE and upload the sketch to the robot.

**If using the Arduino 101, the "Intel Curie Boards" package must be installed using the Boards Manager (Tools->Board->Boards Manager) and "Arduino/Genuino 101" must be selected in the Tools->Board menu.**

## User code
Place any code you want to run repeatedly (code that you would typically place in ```loop()```) inside the ```userCode()``` function.

## Ultrasonic sensor
To initialize the ultrasonic sensor, call ```usSetup(triggerPin, echoPin)``` inside ```setup()```. To read the distance from the sensor, call ```usReadDistance()``` or ```usReadDistance(units)```.

To enable/disable obstacle avoidance with the ultrasonic sensor, call ```enableObstacleAvoid(enable)``` in ```setup()```. This will prevent the robot from driving forwards if there is an object within 10 inches of the sensor.

# Documentation
See the [wiki](https://github.com/Automata-Development/Make-A-Pede/wiki) for complete documentation.
