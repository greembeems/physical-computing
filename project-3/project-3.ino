// Holly Allen & Spencer Betze
// Project 3: Squawk
// 12/13/2022

#include <Servo.h>
#include "pitches.h"

// Input values
char inputValue;

// Motor degrees
int turnDegrees = 0;
int currentDegrees = 0;
long speed = 0.2;
int maxDegrees = 90;
int minDegrees = 0; 

// Time
unsigned long deltaTime = 0;
unsigned long pastTime = 0;

void setup() {
  // Attach the two motors
  //servo.attach(2, 530, 2600);

  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0)
  {
    inputValue = Serial.read();
    
    // Reverse speed if out of range
    if (currentDegrees >= maxDegrees || currentDegrees <= minDegrees)
    {
      speed = -speed;
    }

    currentDegrees = currentDegrees + speed * deltaTime;
    //servo.write(currentDegrees);
    PlayNote(inputValue);
  }

  delay(3);
}

unsigned long DeltaTime()
{
  unsigned long currentTime = millis();
  unsigned long temp = currentTime - pastTime;
  pastTime = currentTime;
  // Return the delta time value
  return temp;
  
}

// Play associated note for all 26 letters
// I could think of a smarter way to do this
void PlayNote(char key)
{
  // Line 1
  if (key == 'q')
  {
    
  }
  else if (key == 'w')
  {
    
  }
  else if (key == 'e')
  {
    
  }
  else if (key == 'r')
  {
    
  }
  else if (key == 't')
  {
    
  }
  else if (key == 'y')
  {
    
  }
  else if (key == 'u')
  {
    
  }
  else if (key == 'i')
  {
    
  }
  else if (key == 'o')
  {
    
  }
  else if (key == 'p')
  {
    
  }
  // Line 2
  else if (key == 'a')
  {
    
  }
  else if (key == 's')
  {
    
  }
  else if (key == 'd')
  {
    
  }
  else if (key == 'f')
  {
    
  }
  else if (key == 'g')
  {
    
  }
  else if (key == 'h')
  {
    
  }
  else if (key == 'j')
  {
    
  }
  else if (key == 'k')
  {
    
  }
  else if (key == 'l')
  {
    
  }
  // Line 3
  else if (key == 'z')
  {
    
  }
  else if (key == 'x')
  {
    
  }
  else if (key == 'c')
  {
    
  }
  else if (key == 'v')
  {
    
  }
  else if (key == 'b')
  {
    
  }
  else if (key == 'n')
  {
    
  }
  else if (key == 'm')
  {
    
  }
}
