const int WIDTH = 79;
const int sensorPin = A0;
int pos = 0;

void setup() {
  Serial.begin(115200);
  pinMode(sensorPin, INPUT);
}

void loop() {
  pos = map(analogRead(sensorPin), 0, 1023, 0, WIDTH); // map the input onto a column position
  Serial.print("pos:");
  Serial.println(pos); // send the position value as a label:value pair
  delay(30);
}

