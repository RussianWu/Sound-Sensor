int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
float sensorValue = 0; // variable to store the value coming from the sensor
float preValue = 0;
float baseValue = 0;
float a = 0;
float Total = 0;
int counter = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  // pinMode(ledPin, OUTPUT);
  Serial.begin (9600);
}

void loop() {
  Total = 0;
  a = 0;
  for(int i=0; i<50; i++) {
    sensorValue = analogRead(sensorPin);
    
    if(preValue == sensorValue)
    {
      counter++;
    }
    if(counter > 20)
    {
      baseValue = sensorValue;
      counter = 0;
    }
    preValue = sensorValue;
    
    a = abs(sensorValue - baseValue);
    Total = Total + a;
  }
  a = Total/50;
  
  Serial.println(a);
}
