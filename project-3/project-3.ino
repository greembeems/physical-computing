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

// Speaker
unsigned int speakerPin = 0;

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
  else
  {
    noTone(speakerPin);
  }

  delay(3);
}

// Calculate delta time
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
    tone(speakerPin, NOTE_B0);
  }
  else if (key == 'w')
  {
    tone(speakerPin, NOTE_C1);
  }
  else if (key == 'e')
  {
    tone(speakerPin, NOTE_D1);
  }
  else if (key == 'r')
  {
    tone(speakerPin, NOTE_E1);
  }
  else if (key == 't')
  {
    tone(speakerPin, NOTE_F1);
  }
  else if (key == 'y')
  {
    tone(speakerPin, NOTE_G1);
  }
  else if (key == 'u')
  {
    tone(speakerPin, NOTE_A1);
  }
  else if (key == 'i')
  {
    tone(speakerPin, NOTE_B1);
  }
  else if (key == 'o')
  {
    tone(speakerPin, NOTE_C2);
  }
  else if (key == 'p')
  {
    tone(speakerPin, NOTE_D2);
  }
  // Line 2
  else if (key == 'a')
  {
    tone(speakerPin, NOTE_E2);
  }
  else if (key == 's')
  {
    tone(speakerPin, NOTE_F2);
  }
  else if (key == 'd')
  {
    tone(speakerPin, NOTE_G2);
  }
  else if (key == 'f')
  {
    tone(speakerPin, NOTE_A2);
  }
  else if (key == 'g')
  {
    tone(speakerPin, NOTE_B2);
  }
  else if (key == 'h')
  {
    tone(speakerPin, NOTE_C3);
  }
  else if (key == 'j')
  {
    tone(speakerPin, NOTE_D3);
  }
  else if (key == 'k')
  {
    tone(speakerPin, NOTE_E3);
  }
  else if (key == 'l')
  {
    tone(speakerPin, NOTE_F3);
  }
  // Line 3
  else if (key == 'z')
  {
    tone(speakerPin, NOTE_G3);
  }
  else if (key == 'x')
  {
    tone(speakerPin, NOTE_A3);
  }
  else if (key == 'c')
  {
    tone(speakerPin, NOTE_B3);
  }
  else if (key == 'v')
  {
    tone(speakerPin, NOTE_C4);
  }
  else if (key == 'b')
  {
    tone(speakerPin, NOTE_D4);
  }
  else if (key == 'n')
  {
    tone(speakerPin, NOTE_F4);
  }
  else if (key == 'm')
  {
    tone(speakerPin, NOTE_G4);
  }
}
