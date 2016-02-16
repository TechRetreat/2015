const int numLeds = 4;
const int patternLength = 5;

//arrays for the button & led pins
int buttonPins[numLeds] = {8, 9, 10, 11};
int ledPins[numLeds] = {2, 3, 4, 5};

// store the Simon Says pattern of leds
int pattern[patternLength];

boolean lost = false;
int count = 0;

void setup() {
  Serial.begin(9600);
  
  // set up all pins with a for loop
  for (int i=0; i < numLeds; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], HIGH);
  }
  
  randomSeed(analogRead(A0)); // add randomness!! (only if A0 is disconnected)
}

void loop() {
  lost = false;
  count = 0;
  
  // construct a random pattern of leds
  for (int i=0; i < patternLength; i++) {
    int randomLed = random(0, numLeds);
    pattern[i] = randomLed;
    
    // flash each led for half a second
    digitalWrite(ledPins[randomLed], LOW);
    delay(500);
    digitalWrite(ledPins[randomLed], HIGH);
    delay(500);
  }
  
  // the game lasts as long as you haven't lost
  // and you haven't gotten through the whole pattern
  while (!lost && count < numLeds) {
    // for loop through each button
    for (int i=0; i < numLeds; i++) {
      // check if button i is pressed
      if (digitalRead(buttonPins[i]) == LOW) {
        Serial.print("Button #");
        Serial.print(i);
        Serial.println(" pressed.");

        // wait for the button to be released
        while (digitalRead(buttonPins[i]) == LOW) {
          delay(10);
        }
        
        // if it's the right button, go to the next one
        if (pattern[count] == i) {
          count++;
        // otherwise, the player lost
        } else {
          lost = true;
          break;  // break out of the for loop
        }
      }
    }
    delay(10);
  }
  
  if (lost) {
    Serial.println("You lost."); 
  } else {
    Serial.println("You won!!!"); 
  }
  
  // wait for a while and then start again!
  delay(1000);
}
