/**
 * ObstacleAvoidAutonomous.ino - Software library for the Make-A-Pede
 * (makeapede.com) Copyright (C) 2017 Automata-Development
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MakeAPede.h"

#define OBSTACLE_LEFT (getLeftAntennae() == HIGH)
#define OBSTACLE_RIGHT (getRightAntennae() == HIGH)

// Define Sensor Pins
int leftSpeedPin = 5;
int leftDirPin = 4;

int rightSpeedPin = 6;
int rightDirPin = 7;

int leftAntennaePin = 12;
int rightAntennaePin = 13;

void setup() {
  setupMaP(leftSpeedPin, leftDirPin, rightSpeedPin, rightDirPin, leftAntennaePin, rightAntennaePin);

   // Initialize the serial connection
  Serial.begin(9600);
  
  // Wait for an antenna to be triggered to start the program
  Serial.println("Press either antenna to start program");
  while (!OBSTACLE_LEFT && !OBSTACLE_RIGHT);

  delay(2000);
}

void loop() {
  // Set the motors to run forwards
  setLeftDirection(LOW);
  setRightDirection(LOW);
  
  // Run the motors at 160 power
  setLeftSpeed(160);
  setRightSpeed(160);
  
  // Wait for an obstacle to be detected
  while (!OBSTACLE_LEFT && !OBSTACLE_RIGHT);
  
  // Stop
  setLeftSpeed(0);
  setRightSpeed(0);
  
  delay(250);
  
  // Reverse the motors
  setLeftDirection(HIGH);
  setRightDirection(HIGH);
  
  // Back up straight
  setLeftSpeed(255);
  setRightSpeed(255);
  
  // Wait for the sensor to be released
  while (OBSTACLE_LEFT || OBSTACLE_RIGHT);
  
  // Wait an additional 0.5 seconds
  delay(500);
  
  // Back up left or right depending on which antenna was triggered
  if (OBSTACLE_LEFT) {
    setLeftSpeed(90);
    setRightSpeed(200);
  } else if (OBSTACLE_RIGHT) {
    setLeftSpeed(200);
    setRightSpeed(90);
  }
  
  // Wait for 1.0 seconds
  delay(1000);
  
  // Stop
  setLeftSpeed(0);
  setRightSpeed(0);
  
  delay(250);
}

void userCode() {}
