int sensorPin = A9;
int sensorValue = 0;
int mappedValue = 0;
long counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}


void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(500);
}
