# Getting Started with Arduino Development

## What is an Arduino?
Arduino is a microcontroller on a circuit board which makes it easy to receive inputs and drive outputs. 
A microcontroller is an integrated computer on a chip.

## Initial Setup

First thing's first: we need to tell the program what chip we're using. Click on "Tools > Board" and make
sure that "Arduino Uno" is selected.

## Hello Wor... err I mean Blink!

The programs you write for your Arduino are known as **sketches**, written in the **C++** programming language.
Every sketch needs two `void` type functions, `setup()` and `loop()`. (A `void` type function doesn’t return any 
value.)
The `setup()` method is run when the Arduino is powered up or reset and the `loop()` method is run continuously 
afterwards. `setup()` is where you want to do any initialisation steps. `loop()` will usually contain most
of your program and includes things like reading sensor values and giving output, which are done repeatedly.
So, the absolute bare minimum sketch looks like this:

```
void setup() {

}

void loop() {

}
```

Now that we have the basic skeleton in place, we can write the microcontroller's version of a traditional
**"Hello, World"** program - a blinking LED. 
Around the edges of the board, there are several black rectangles with square holes on top. 
These are called **headers**. Headers make it easy to connect components to the Arduino chip's **pins**.
Understanding each type of pin's functionality is essential for programming an Arduino.

The pin numbers are listed next to the headers on the board in white. Pin 13 is a special pin that's connected
to an led built into the actual Arduino board. We're going to write a program to make it blink!

Let's start by creating a variable called `ledPin` at the very top of our sketch. In C++ we need to state what 
type our variable is when we declare it; in this case it’s an integer (a positive or negative whole number), so 
it’s of type `int`.

```
int ledPin = 13;

void setup() {

}

void loop() {

}
```

**Note that most normal lines end with a semicolon `;` in C++**

In the `setup()` function we want to set the `ledPin` to the output mode. We do this by calling a special function
called `pinMode()` and telling it the pin number and whether it's an input or output. Since we want to output
a signal to our led, we set it to be an `OUTPUT`. If you were working with a sensor or switch that you wanted
to read from, it would be an `INPUT`.

```
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

}
```

**Since "ledPin" is a variable, writing its name in the code is the same as referencing its value. In
this case, we could achieve the same effect by using `pinMode(13, OUTPUT)`.**

In our loop we are going to first switch off the LED to make sure our program is actually being written to the
chip and overriding the default on state.
We do this by calling another special method called `digitalWrite()`. This also takes two values, the pin number and the level, `HIGH` the 'on' state or `LOW`, the 'off' state.

```
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, LOW);
}
```

Next we want to compile the code and upload it to the Arduino. Sound scary? The IDE does all the work!

## Compiling the Code

If this is your first time you’ve ever compiled code to your Arduino, you should do the following before plugging it in to the computer:

1. Click on "Tools > Serial Port" and take note of what appears there.

2. Plug your Arduino UNO into your computer with the USB cable. Now go back to the "Tools > Serial 
Port" menu and you should see at least 1 new option. 

3. On Windows, you should see a new **COM** port (probably "COM1"). The Arduino likely appears as a
**/dev/tty.usbserial** type port on a Mac or as **/dev/ttyUSB0** on Linux. Regardless, select the new one 
that appears after plugging your Arduino in.

4. Once you have selected your serial port, you can then press the 'Upload' button on the IDE (it looks
like an arrow pointing right). You should see a couple LEDs on the board begin flashing - this means there's 
communication going on between the computer and the Arduino. 

5. In a few seconds, your IDE should show the message "Done Uploading", and your program should now be running on
the Arduino. Check if the **L** LED turned off (it's near the Arduino logo).

Now, let’s try and switch it on using the `HIGH` constant.

```
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
}
```

Press **Upload** again and you should see your LED is now on!

How about we make our program a little more interesting now? We’re going to use another method called `delay()`. 
It takes an integer representing the number of milliseconds to delay for (i.e. `delay(1000)` means to pause
the program for 1 second).
After the line where we switch the LED on, let’s add `delay(2000)` (2 seconds), then `digitalWrite(ledPin, LOW)`
to switch it off, followed by another `delay(2000)`.

```
int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(2000);
  digitalWrite(ledPin, LOW);
  delay(2000);
}
```

Do you understand what this should do? Upload it to your Arduino and take a look!

## Getting to know your gear

### Breadboard
<br><img src="https://cloud.githubusercontent.com/assets/6520974/9215320/c8b31792-4076-11e5-9242-183ab9b44ddd.png" height="300px">

Solderless breadboards are an important tool in your quest for electronics mastery. They allow you to make quick 
circuits to test out ideas without having to make a more permanent Printed Circuit Board (PCB). They're 
also inexpensive and reusable.

Basically, a chunk of plastic with a bunch of holes. However, something special is going on inside the breadboard! Although you can't see it, inside the breadboard are many strips of metal that connect the rows (and certain 
columns) together. The metal strips are springy so that when you poke a wire into the hole, the clips grab onto 
it to form a solid connection.

This diagram shows how the connections are being made inside the breadboard:

<img src="http://www.seeedstudio.com/wiki/images/thumb/4/4c/Arduino_Sidekick_Breadboard_Internal_Connections.jpg/300px-Arduino_Sidekick_Breadboard_Internal_Connections.jpg" height="200px">

The long columns are called *rails*, and the short rows are called, well, *rows*. Breadboards are almost always 
made so that they have two sets of 5-hole rows, with a pair of rails on either side. 

**Notice that the rows aren't connected across the center gap, and that, in our breadboards, the rails are actually split into four different groups on each side (notice how the coloured lines stop halfway down?)**

### Jumper Wires
<br><img src="https://cloud.githubusercontent.com/assets/6520974/9215338/0bc474cc-4077-11e5-9a08-2a4470efc822.jpg" width="400px">

Jumper wires are pretty simple, but they're what make all of this possible. They're essential for working with 
your breadboard because they let you make connections between different components and your Arduino.

### Resistors
<br><img src="https://cloud.githubusercontent.com/assets/6520974/9215626/f39196ec-407a-11e5-98c0-0a82f690669e.png" width="400px">

The resistor is the most basic and also most common electronic part. A simple electronic gadget, such as an mp3 
player, easily has a thousand resistors inside of it!

Resistors have one job to do, and that is to resist the flow of electricity (otherwise known as current). 
Resistance is measured in **ohms**, often written as the symbol **Ω**. The bigger the resistance value (in ohms) 
the more it - you guessed it - resists. Most resistors you'll see range between 100 ohms and 1 megaohm (1.0 MΩ). 
The coloured stripes on the body of the resistor tell you what its resistance value is - this is known as the 
**resistor color code**. (We'll be showing pictures of all the resistors you need, so don't feel you have to
memorize this - even experienced engineers can't remember the less common colour values!)

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9215672/cccd87ae-407b-11e5-8b83-e2409dfab094.jpg" width="400px">

### LED

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9216097/18c12dfe-4082-11e5-9d5d-17ebe1c4f74e.png" width="40px">

The word LED stands for Light Emitting Diode. A diode is a one-way street for current in the sense that it only
allows current to flow from the positive side to the negative side. The **positive** leg on an LED is usually 
slightly longer, but not always. To be sure, hold your LED up to the light so you can see inside. The **negative**
leg has the larger piece of metal (it looks like a little flag) - this is the end that should be closer to your
'ground' pin in most circuits you make. If an LED isn't lighting up, try flipping it around.

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9216227/a02ad352-4083-11e5-8e9d-6b350c2fe8da.jpg" width="400px">

## Schematics

Now that you've built your first circuit, let's say you want to send that to a friend. Sure, you could take a picture of it and perhaps post it on Instagram but a much better method would be to create a **wiring diagram** or a **schematic**. Schematics are the standard method used to describe how to build a circuit. 

Each electronic component has a schematic symbol, which is a simplified drawing of the part. For resistors the symbol looks like this:

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9216754/4162ff26-408c-11e5-82a8-ada27dff2715.jpg" width="400px">

And the symbol for LEDs look like this:

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9216757/416635b0-408c-11e5-83d2-21a1bf3c9f31.jpg" width="400px">

You can see that the resistor symbol is symmetrical, just like resistors themselves. The LED symbol, however, has 
an arrow showing the direction in which it allows current to flow. The little arrows that are coming out of the 
symbol indicate that this is a diode that emits light.

Power and ground also have symbols:

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9216755/41631eb6-408c-11e5-9bc8-869550dc4eb2.jpg" width="200px">

The only thing we need to do now is indicate how the LED and resistor are hooked up and show the 5V and ground connections. Next to symbols, we often write important information like what the resistor value is, what color and size the LED should be, and the voltage associated with the power supply.

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9216756/416389a0-408c-11e5-9151-9b5a8d4cd338.jpg" width="200px">

## Series vs Parallel

When there are two or more electrical devices present in a circuit with an energy source, there are a couple of basic means by which to connect them. They can be connected in **series** or connected in **parallel**. Suppose that there are three light bulbs connected together in the same circuit. If connected in series, then they are connected in such a way that an individual charge would pass through each one of the light bulbs in consecutive fashion. When in series, charge passes through every light bulb. 
 
<br><img src="https://cloud.githubusercontent.com/assets/6520974/9240455/a3e3f3d2-4134-11e5-9d0d-93784a876981.png" width="400px">
 
If connected in parallel, a single charge passing through the external circuit would only pass through one of the light bulbs. The light bulbs are placed within a separate branch line, and a charge traversing the external circuit will pass through only one of the branches during its path back to the low potential terminal. The means by which the resistors are connected will have a major effect upon the overall resistance of the circuit, the total current in the circuit, and the current in each resistor. 

<br><img src="https://cloud.githubusercontent.com/assets/6520974/9240454/a3e2d574-4134-11e5-9a05-982149d99f67.png" width="400px">

## Some Precautions

While you're experimenting with things later in the day, there's very little you can do that's actually dangerous.
However, try to watch out for these things, which might permanently damage some of your electronic components:

* Make sure **not to connect the +5V pin directly to the ground** without some kind of resistance in
between. This will *short out* the Arduino (letting current flow straight from + to -), which is **BAD**

* Extending this, **always unplug your Arduino** before moving around wires or components - it's way too
easy to accidentally brush something against a place where it really shouldn't be.

* Your little LEDs are one of the easiest components to burn out. Always make sure there is a resistor
of at least 470Ω between every LED and +5V or ground.

This was a very brief runthrough of just some of the basics of circuits and Arduino programming. If you don't
have much experience in either area, don't worry! There will be mentors floating around all day who will take an arrow to the knee *just to help you*, so don't be shy about asking questions! 
