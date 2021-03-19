int switchPin = 0;              // switch is connected to pin 0
bool isPush;
unsigned long startTime = 0;
unsigned long StopTime = 0;

void setup() {
  pinMode(switchPin, INPUT);    // Set the switch pin as input
  Serial.begin(115200);           // Set up serial communication at 115200bps
}

void loop() {
  if (digitalRead(switchPin) == LOW)
  {
    if (isPush == false)
    {
      startTime = millis();
    }
    isPush = true;
  }
  else
  {
    if (isPush == true)
    {
      StopTime = millis();
      Serial.print("Pustbutton ");
      Serial.print(StopTime - startTime);
      Serial.println(" Millis Second");
      startTime = StopTime;
      isPush = false;
    }
  }
}
