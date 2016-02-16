int inputPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int tones[] = { 1060, 1175, 1319, 1397, 1568, 1760, 1976, 2093};
int speakerPin = 10;

int duration = 100;

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(inputPin[0], INPUT);
  pinMode(inputPin[1], INPUT);
  pinMode(inputPin[2], INPUT);
  pinMode(inputPin[3], INPUT);
  pinMode(inputPin[4], INPUT);
  pinMode(inputPin[5], INPUT);
  pinMode(inputPin[6], INPUT);
  pinMode(inputPin[7], INPUT);
}

void loop() {
  if (digitalRead(inputPin[0]) == LOW) {
    tone(speakerPin, tones[0], duration);
  } else if (digitalRead(inputPin[1]) == LOW) {
    tone(speakerPin, tones[1], duration);
  } else if (digitalRead(inputPin[2]) == LOW) {
    tone(speakerPin, tones[2], duration);
  } else if (digitalRead(inputPin[3]) == LOW) {
    tone(speakerPin, tones[3], duration);
  } else if (digitalRead(inputPin[4]) == LOW) {
    tone(speakerPin, tones[4], duration);
  } else if (digitalRead(inputPin[5]) == LOW) {
    tone(speakerPin, tones[5], duration);
  } else if (digitalRead(inputPin[6]) == LOW) {
    tone(speakerPin, tones[6], duration);
  } else if (digitalRead(inputPin[7]) == LOW) {
    tone(speakerPin, tones[7], duration);
  } else {
    noTone(speakerPin);
  }
}
