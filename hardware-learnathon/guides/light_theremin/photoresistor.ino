// constants for the largest and smallest input values
const int UPPER_INPUT = 550;
const int LOWER_INPUT = 300;

const int sensorPin = A0;  // input pin for the photoresistor

int sensorValue;  // variable to store the value coming from the sensor

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);   // set up the sensor pin as an input
}

void loop() {
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(sensorValue);         // print the value to console
  delay(5); // enter a small delay
}
