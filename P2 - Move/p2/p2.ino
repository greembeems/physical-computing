// Holly Allen & Spencer Betze
// Project 2: Move
// 10/27/2022

#include <Servo.h>

// On pin 2
Servo servo;

// Piezo vibration sensor
int sensorValue = 0; // Determines rate of revolutions for motor

// Time it takes for the program to assume no one is interacting
unsigned long noInteract = 15000; 

// Change in time
unsigned long pastTime = 0;

// Degrees the motor will turn
int degreesToTurn = 0;
int currentDegrees = 0;

void setup() {
  servo.attach(2, 530, 2600);
  randomSeed(analogRead(0));
}

void loop() {
  // Update deltaTime
  unsigned long deltaTime = DeltaTime();
  
  // Read input value
  sensorValue = analogRead(A0);
  
  // If the sensor is displaying a value
  if (sensorValue > 0)
  {
    // Calculate the number of revolutions taken this update
    degreesToTurn = sensorValue * (int)deltaTime / 100;
    // Reset interaction timer
    noInteract = 15000;
  }
  
  // If the system is not being interacted with for 15 seconds
  else if (noInteract <= 0 && sensorValue <= 0)
  {
    // Set a random rate of revolution
    degreesToTurn = random(1, 8) * (int)deltaTime;
    // Reset interaction timer to keep revolution rate consistent
    noInteract = 15000;
  }

  // Turn motors certain number of degrees either determined by calculation or random
//  if (degreesToTurn <= 140)
//  {
//    for (; degreesToTurn <= 150; degreesToTurn++)
//    {
//      servo.write(degreesToTurn);
//      delay(15);
//    }
//  }
//  else if (degreesToTurn >= 150)
//  {
//    for(; degreesToTurn >= 140; degreesToTurn--)
//    {
//      servo.write(degreesToTurn);
//      delay(15);
//    }
//  }
  currentDegrees = currentDegrees + degreesToTurn;
  if (currentDegrees > 180)
  {
    currentDegrees = currentDegrees - 180;
    servo.write(180);
    delay(10);
  }
  servo.write(currentDegrees);

  // Lower interaction timer
  noInteract = noInteract - deltaTime;
  Serial.println(currentDegrees);
//  delay(500);
}

unsigned long DeltaTime()
{
  unsigned long currentTime = millis();
  unsigned long deltaTime = currentTime - pastTime;
  pastTime = currentTime;
  return deltaTime;
}
