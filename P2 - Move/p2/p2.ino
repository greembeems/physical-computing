#include <Servo.h>

// On pin 2
Servo servo;

// Piezo vibration sensor
int sensorValue = 0; // Determines rate of revolutions for motor

double noInteract = 15; // Time it takes for the program to assume no one is interacting

void setup() {
  servo.attach(2, 530, 2600);
}

void loop() {
  // If the sensor is displaying a value
  if (sensorValue > 0) // Don't bother running calculations if there's no input
  {
    
    servo.write();
  }

}
