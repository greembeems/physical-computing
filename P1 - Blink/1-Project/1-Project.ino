// Holly Allen
// Project 1: Blink
// 9/27/2022

// Pins
// Switch
const int switchPin = 9;

// LEDs
const int ledPin1 = 5;
const int ledPin2 = 6;
const int ledPin3 = 7;

// Time between flashes
long timeBetween = 1000;
long timeElapsed = 0;
long lastMilSec = 0;

// States
int switchState = 0;

void setup() {
  // LEDs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  // Switch
  pinMode(switchPin, INPUT);
  

  Serial.begin(9600);
  //delay(100);

  randomSeed(analogRead(0));
}

void loop() {
  switchState = digitalRead(switchPin);
  long currentMilSec = millis();


  // If switch on, modify time randomly
  if (switchState == HIGH)
  {
    long newTime = random(50, 500);
    if (newTime != timeBetween)
    {
      timeBetween == newTime;
    }
  }

  // Check the time
  // LED 1 Flash
  if (timeElapsed >= timeBetween)
  {
    digitalWrite(ledPin1, HIGH);
  }
  // LED 2 Flash
  if (timeElapsed >= timeBetween * 2)
  {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
  }
  // LED 3 Flash
  if (timeElapsed >= timeBetween * 3)
  {
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin2, LOW);
  }
  if (timeElapsed >= timeBetween * 4)
  {
    digitalWrite(ledPin3, LOW);
    timeElapsed = 0;
  }

  // Increment the time
  timeElapsed += currentMilSec - lastMilSec;
  lastMilSec = currentMilSec;
}
