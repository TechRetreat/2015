# Push Button Piano

Let's try to build everybody's favorite instrument, the piano! However, instead of keys we'll be using push buttons. 

## What We Need

* 9 x 470 kΩ Resistor

<img src="https://upload.wikimedia.org/wikipedia/commons/4/4c/470_ohms_5%25_axial_resistor.jpg" height="100px">

* 8 x Push button

<img src="https://electrosome.com/wp-content/uploads/2012/12/Push-Button-Switch.jpg" height="100px">

* 1x Piezo speaker

<img src="https://content.solarbotics.com/products/photos/93c51bd69dcc15a0f60bb6bb4c96d4df/lrg/17855-dscn3894.JPG" height="100">
* Arduino Uno
* Wires (at least 18)
* Breadboard


## How To Make It

#### Push It to the Limit

A **push button** is a component that connects two points in a circuit when you press it. 

1. Build the following circuit with 8 push buttons (1 for each note in a scale). Make sure that the negative end of the Piezo speaker is connected to GND while the positive end is connected to the 10 pin

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9244952/0e8d38fe-416e-11e5-9532-9dba61211fec.png" width="400px">&nbsp;<img src="https://cloud.githubusercontent.com/assets/6520974/9245075/f2b72102-416e-11e5-981f-581d45e41f99.png" width="400px">

2. To make a functioning digital piano, we'll now need to write the code to support our circuit. To help you break it down, here are the different sections you'll need to complete:
    - Initialize all the input and output pins
    - Identify all the notes the piano will be emitting
    - Write a procedure to emit a tone (*HINT: A musical note is produced when a tone is played at a specific frequency*)
    - Write a procedure to identify which note is being requested when a push button is pressed
    - Write a proper loop procedure to listen for when buttons are pressed and handle it appropriately

3. Here is some values that might be useful for you! 
    * c = 1060 Hz
    * d = 1175 Hz
    * e = 1319 Hz
    * f = 1397 Hz
    * g = 1568 Hz 	
    * a = 1760 Hz 	
    * b = 1976 Hz	
    * C	= 2093 Hz

#### Creating a Masterpiece

Awesome job so far! Now that you've got yourself a functioning piano, it's time to put those musical muscles to use! Although this is a tech event, I'm 99.99% sure you've all heard some simple songs such as "Twinkle Twinkle Little Star" or "Marry Had a Little Lamb". You now have the chance to finally impress your mother with your vastly superior musical talents through the power of the Arduino!

#### Extension

A cool way to improve on this project is to try to emulate a piano one step further, by making keys! Well... not exactly but you can add capacitive-touch functionality to your digital keyboard to eliminate the need for push buttons! We wrote a simple guide [here](https://github.com/TechRetreat/hardware-learnathon/blob/master/guides/touch_sensor_example/HOWTO.md).
