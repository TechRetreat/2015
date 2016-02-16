const int WIDTH = 80;  // 80 columns is a standard console width

const int sensorPin = A0;

int pos = 0;

void setup() {
  Serial.begin(57600);  // note the higher baud rate (for smoother animation)
  pinMode(sensorPin, INPUT);
}

void loop() {
  pos = map(analogRead(sensorPin), 0, 1023, 0, WIDTH);  // map the input onto a column position
  for (int i = 0; i < pos; i++) {
    Serial.print(" ");
  }
  Serial.println("o");  // output an "o" after the proper number of spaces
  delay(20);
}
