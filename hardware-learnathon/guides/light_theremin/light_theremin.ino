// constants defining ranges of inputs and outputs
const int UPPER_INPUT = 550;
const int LOWER_INPUT = 300;
const int LOWER_FREQ = 250;
const int UPPER_FREQ = 1050;

const int sensorPin = A0;
const int speakerPin = 4;

int sensorValue;
int frequency;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if (sensorValue < LOWER_INPUT || sensorValue > UPPER_INPUT) {
    // if the sensor value is out of range, stop the tone
    noTone(speakerPin); 
  } else {
    // 'map' the input value onto the output value
    frequency = map(sensorValue, LOWER_INPUT, UPPER_INPUT, LOWER_FREQ, UPPER_FREQ);
    // output the calculated frequency on the speaker pin
    tone(speakerPin, frequency);
  }
  delay(5);
}
