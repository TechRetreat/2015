#Potentiometer Runner

Long before touchscreens, motion detection, and voice commands, many pieces of computer and electronics 
equipment used knobs for precise user input. How exactly do you read the position of a knob? Use a 
[potentiometer](https://www.arduino.cc/en/Tutorial/Potentiometer), of course! It's a small metal component with 
three pins and a twistable shaft. This simple project shows you how to use the potentiometer by building
a simple interactive 'runner' animation.

##What We Need

* 1x Potentiometer

<img src="https://www.futurlec.com/Pictures/D_Shaft_Potentiometer.jpg" height="100px">
&nbsp;<img src="http://farasbee.com/blog/wp-content/uploads/2012/02/potentiometer.png" height="100px">

* Arduino Uno
* 3 Wires
* Breadboard (optional)


##How To Make It

1. This circuit is very straightforward - just connect the three pins of the potentiometer to the
Arduino like in the diagram. If you're using a breadboard, you might have to bend the metal bracket underneath 
the potentiometer to get it into the holes. Otherwise, just insert the wires into the legs and tape them on, 
making sure they don't touch.
<br><img src="https://cloud.githubusercontent.com/assets/3172103/9155886/a2e0d0be-3e95-11e5-9e4b-9eb8482deeff.png" width="400px">
&nbsp;<img src="https://cloud.githubusercontent.com/assets/3172103/9155883/7f28309a-3e95-11e5-857a-748bf3658fdc.png" width="400px">

2. Start by opening the AnalogReadSerial example sketch (Open > 01.Basics), which reads an analog input on
pin A0 and outputs it to console. See how twisting the potentiometer changes the value - at one extreme it should
drop to 0, and at the other it should hit the max value of 1023.

3. The goal of this project is to translate the input from the potentiometer into a column position on screen
(remember the `map()` function??). Delete the `Serial.println()` call in the example and 
make the program continuously print a line containing a single character at the
column position you calculate from the sensor value. Give it a shot, and then 
check out our code at [`potentiometer_runner.ino`](potentiometer_runner.ino) to see how we did it! 
It should look something like this:
<br><img src="https://cloud.githubusercontent.com/assets/3172103/9155900/14d2374e-3e96-11e5-8933-973a3d51eac3.png" height="300px"><br>
*You might want to use a baud rate higher than 9600 for faster writing to console (just remember to
change it in the Serial Monitor), and a slightly higher delay than before for less flickery animation.*


##How It Works

The schematic symbol for a potentiometer gives a pretty good idea of how it works - a fixed resistor with
a third 'wiper' pin coming out of the middle. The resistance across the two outer pins is about 2kΩ in the
potentiometers we gave you. When the shaft is turned, it physically moves the wiper across the resistive
material, changing the resistance between the middle pin and each of the two outer pins from 0 to a maximum
of 2kΩ. This changes the voltage on the middle pin, which is then read as your input value.
