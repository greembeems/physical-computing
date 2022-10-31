// Holly Allen & Spencer Betze
// Project 2: Move
// 11/1/2022

// Fan
int fan = 3;
int fanSpeed = 0;

// Piezo vibration sensor
int sensorValue = 0; // Determines rate of revolutions for fan (speed)

// Time it takes for the program to assume no one is interacting
unsigned long noInteract = 15000; 

// Delta time
unsigned long pastTime = 0;

void setup() {
  pinMode(fan, OUTPUT);

  // Random
  randomSeed(analogRead(0));
}

void loop() {
  // Update deltaTime
  unsigned long deltaTime = DeltaTime();
  
  // Read input value
  sensorValue = analogRead(A0);
  
  // If the sensor is displaying a value
  if (sensorValue >= 255)
  {
    // Set fan speed
    fanSpeed = sensorValue;
    
    // Reset interaction timer
    noInteract = 15000;
  }
  
  // If the system is not being interacted with for 15 seconds
  else if (noInteract <= 0 && sensorValue < 255)
  {
    // Set random fan speed
    fanSpeed = random(255, 500);
    
    // Reset interaction timer to keep revolution rate consistent
    noInteract = 15000;
  }
  else if (sensorValue < 255)
  {
    fanSpeed = 0;
  }
    // Set fan speed as either determined by calculation or random
    analogWrite(fan, fanSpeed);
    
  Serial.println(fanSpeed);

  // Lower no interaction timer
  noInteract = noInteract - deltaTime;
  delay(100);
}

unsigned long DeltaTime()
{
  unsigned long currentTime = millis();
  unsigned long deltaTime = currentTime - pastTime;
  pastTime = currentTime;
  return deltaTime;
}
