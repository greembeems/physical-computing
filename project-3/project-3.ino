// Holly Allen & Spencer Betze
// Project 3: Squawk
// 12/13/2022

#include <Servo.h>
#include "pitches.h"

// Input values
String inputValue;

// Motor
int turnDegrees = 0;
int currentDegrees = 0;
long speed = 0.2;
int maxDegrees = 90;
int minDegrees = 0; 
Servo servo;
bool notePlaying = false;

// Speaker
unsigned int speakerPin = 9;

// Time
unsigned long deltaTime = 0;
unsigned long pastTime = 0;

void setup() {
  // Attach the two motors
  servo.attach(3, 530, 2600);

  Serial.begin(9600);
}

void loop() {
  deltaTime = DeltaTime();
  
  while (Serial.available() == 0) {}

    inputValue = Serial.readString();

    notePlaying = PlayNote(inputValue);

    // If there is a note playing right now
    if (notePlaying)
    {
      // Reverse speed if out of range
      if (currentDegrees >= maxDegrees || currentDegrees <= minDegrees)
      {
        speed = -speed;
      }
  
      currentDegrees = currentDegrees + speed * deltaTime; // Something is going wrong here and we need to solve what that is
      servo.write(currentDegrees);
    }

  delay(0.02);
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
bool PlayNote(String key)
{
  Serial.print(key);
  // Line 1
  if (key == "q\n")
  {
    tone(speakerPin, NOTE_B0);
    return true;
  }
  else if (key == "w\n")
  {
    tone(speakerPin, NOTE_C1);
    return true;
  }
  else if (key == "e\n")
  {
    tone(speakerPin, NOTE_D1);
    return true;
  }
  else if (key == "r\n")
  {
    tone(speakerPin, NOTE_E1);
    return true;
  }
  else if (key == "t\n")
  {
    tone(speakerPin, NOTE_F1);
    return true;
  }
  else if (key == "y\n")
  {
    tone(speakerPin, NOTE_G1);
    return true;
  }
  else if (key == "u\n")
  {
    tone(speakerPin, NOTE_A1);
    return true;
  }
  else if (key == "i\n")
  {
    tone(speakerPin, NOTE_B1);
    return true;
  }
  else if (key == "o\n")
  {
    tone(speakerPin, NOTE_C2);
    return true;
  }
  else if (key == "p\n")
  {
    tone(speakerPin, NOTE_D2);
    return true;
  }
  // Line 2
  else if (key == "a\n")
  {
    tone(speakerPin, NOTE_E2);
    return true;
  }
  else if (key == "s\n")
  {
    tone(speakerPin, NOTE_F2);
    return true;
  }
  else if (key == "d\n")
  {
    tone(speakerPin, NOTE_G2);
    return true;
  }
  else if (key == "f\n")
  {
    tone(speakerPin, NOTE_A2);
    return true;
  }
  else if (key == "g\n")
  {
    tone(speakerPin, NOTE_B2);
    return true;
  }
  else if (key == "h\n")
  {
    tone(speakerPin, NOTE_C3);
    return true;
  }
  else if (key == "j\n")
  {
    tone(speakerPin, NOTE_D3);
    return true;
  }
  else if (key == "k\n")
  {
    tone(speakerPin, NOTE_E3);
    return true;
  }
  else if (key == "l\n")
  {
    tone(speakerPin, NOTE_F3);
    return true;
  }
  // Line 3
  else if (key == "z\n")
  {
    tone(speakerPin, NOTE_G3);
    return true;
  }
  else if (key == "x\n")
  {
    tone(speakerPin, NOTE_A3);
    return true;
  }
  else if (key == "c\n")
  {
    tone(speakerPin, NOTE_B3);
    return true;
  }
  else if (key == "v\n")
  {
    tone(speakerPin, NOTE_C4);
    return true;
  }
  else if (key == "b\n")
  {
    tone(speakerPin, NOTE_D4);
    return true;
  }
  else if (key == "n\n")
  {
    tone(speakerPin, NOTE_F4);
    return true;
  }
  else if (key == "m\n")
  {
    tone(speakerPin, NOTE_G4);
    return true;
  }
  else 
  {
    noTone(speakerPin);
    return false;
  }
  return false;
}
