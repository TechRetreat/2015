#Simon Says

This guide shows you how to make a simple version of the game Simon Says using leds and pushbuttons.

##What We Need

* 4x LED

<img src="http://www.tandyonline.co.uk/media/catalog/product/cache/1/image/9df78eab33525d08d6e5fb8d27136e95/c/l/clear-led.png" height="100px">
* 4x 470Ω Resistor

<img src="http://media.digikey.com/Renders/Yageo%20Renders/CFR-12JR-470R.jpg" height="100px">

* 4x Pushbutton

<img src="https://cdn.sparkfun.com//assets/parts/9/0/00097-03-L.jpg" height="100px">
* Arduino Uno
* Wires
* Breadboard


##How To Make It

1. This project uses buttons similar to the pushbutton piano, but without pullup resistors (it takes
advantage of the pullup resistors built into the Arduino board). On top of that, you need to add
four LEDs in series with resistors further down the board. Pay special attention to which way you put them in!
<br><img src="https://cloud.githubusercontent.com/assets/3172103/9215903/1045a9aa-407f-11e5-977f-71481d37e3b3.png" width="600px">

2. The code for this project is a little bit more involved. First, you need to set up your button and
LED pins. Next, you need to create some kind of pattern that the LEDs will flash in. Finally, you have to
check if the user pushes the buttons in the same order as the LEDs flashed. If it seems a bit overwhelming,
start with small, incremental steps, and use `Serial.print()` often for debugging. 
*To use the built-in pullup resistors, set the pinMode of the button input pins to `INPUT_PULLUP`*

3. Once you've given it a shot, check out our implementation in [`simon_says.ino`](simon_says.ino).

##Extension

This is a very minimalistic implementation of Simon Says. First of all, it's the same game all the time;
it can never increase in difficulty and doesn't keep track of score. Next, almost all user
feedback is limited to Serial print statements. This is fine for debugging, but doesn't make for a great
user experience. Try to think of ways to use flashing LEDs, speakers, or something else to represent
wins or losses. I'm sure there are many other ways to improve on the idea as well, like a potentiometer that
is used to select difficulty - be creative!
