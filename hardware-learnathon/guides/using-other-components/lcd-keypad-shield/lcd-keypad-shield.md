#LCD Keypad Shield

The LCD shield includes a Liquid Crystal Display and a number of pushbuttons. It solves the issue of
user input/output in a microcontroller system by providing both a convenient, albeit minmial, text
display, and intuitively labelled button inputs.

##How To Use It

The LCD display has 16 columns and two rows of characters. Each cell has enough pixels to display
every standard ASCII character (English letters, numbers, and symbols). The Arduino is able to use just
a few pins to send commands that tell the display where to position the cursor and what text to output where.

Look at the [`lcd_display_example.ino`](lcd_display_example.ino) sketch. It shows how to set up the
LCD display with proper pins and sizing, as well as how to actually display text, using the convenient
`LiquidDisplay` library by Arduino.

After reading through that (and making some modifications!) check out [`lcd_shield_buttons.ino`](lcd_shield_buttons.ino).
It's a slightly more complicated example released by the manufacturer which includes a function that
checks which button is pressed. It may look quite long, but it is actually fairly simple! Every loop, it
just calls the function to see which button is pressed and prints to the display the button's corresponding label.
Upload it to your Arduino and try it out!

##What It's Used For

LCD screens are incredibly useful in microcontroller systems for the reasons described. You could use one to
monitor a robot, showing the temperatures of the motors, battery voltage, and what command it's executing. You
could build a mobile weather station, displaying the current temperature, humidity, barometric pressure, and
more, and even use the buttons to cycle back to see highs for previous days.

Unfortunately, we might have to scale back a bit for the scope of this event. Some of the more
interesting applications we could think of are:

######Twenty(ish) Questions
Have you ever played the word guessing game Twenty Questions with a friend, or even used the old
[20Q](https://en.wikipedia.org/wiki/20Q) toy? Did you know that, even with a sequence of just twenty
questions, it can lead to over 1 million unique answers? With a bit of clever design, you can guess almost
every common word! You could try programming a similar game (but maybe with just a few questions).

######Text-Based Adventure
Have you ever played any old 
[text-based adventure games?](http://www.web-adventures.org/cgi-bin/webfrotz?s=Adventure) 
Usually you explore rooms (by moving up/down/left/right), read descriptions of your surroundings,
and pick up and use items to solve puzzles. You should be able to make a simple text-based adventure
game using just the LCD shield!

######Mockup Electronic Lock
Design a display for an electronic lock. The user must input a specific sequence of buttons
to change the device from "LOCKED" to "UNLOCKED", or maybe answer some security questions. It's a little
more complicated, but see if you can figure out how the user might be able to use the buttons to 
input their own text!
