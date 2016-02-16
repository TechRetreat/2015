int i = 0;
const int WIDTH = 50;
int pos = 0;
int delta = 1;

void setup() {
  Serial.begin(115200); // notice the high baud rate!
}

void loop() {
  cls();
  if (pos < 0 || pos >= WIDTH - 1) delta = -delta; // change direction when it hits the side
  pos += delta;

  for (i = 0; i < WIDTH; i++) Serial.print("=");
  Serial.println(); // end the line to let SerialPrint.cpp know it's the end of this message
  
  // print an "o" with spaces to move it to the right position
  for (i = 0; i < pos; i++) Serial.print(" ");
  Serial.println("o");
  
  for (i = 0; i < WIDTH; i++) Serial.print("=");
  Serial.println();
  delay(30);
}

// sends a special sequence of ASCII characters that clears the screen
void cls() {
  Serial.print((char) 27);
  Serial.print("[2J");
  Serial.print((char) 27);
  Serial.print("[;H\n");
}


