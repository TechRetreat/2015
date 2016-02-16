#Serial Communication Example

Normally when we use `Serial.print()`, we open the Arduino IDE's built in Serial Monitor and read the output 
strings. However, you can easily write your own computer program that can read this serial output and act on it.
This isn't so much a single project as a starting point for your own - it includes a useful library and an
example of interfacing with your Arduino in a more versatile way.

*This is a somewhat more advanced topic and assumes some previous programming knowledge. We encourage you 
to give this a read regardless!*

##What We Need
* Arduino UNO & USB Cable
* serialib serial communication library for C++
* C++ compiler

##How To Use It

####Downloading a C++ Compiler

######Windows

1. Download the [mingw installer](http://sourceforge.net/projects/mingw/files/latest/download?source=files)
and run it. 

2. You will want to install base and g++ at a minimum. Click on the checkbox and "Mark for Installation".
Then, click "Installation > Apply Changes > Apply".

3. You will need to add `;C:\MinGW` to the end of your PATH 
[environment variable](http://www.computerhope.com/issues/ch000549.htm).

######Linux (Debian derivatives)
1. Enter `sudo apt-get install gcc g++`

2. Laugh at all the Windows users who are still struggling with installing mingw.

*If you don't know C++ and would much rather not work with it, ask one of the Mentors for help setting up
a serial library in another language.*

####Setting Up Communication

Start by 
[downloading our zip file](https://github.com/TechRetreat/hardware-learnathon/raw/master/serial_example/serial_example_code.zip),
which contains the serialib library and an example file `SerialPrint.cpp` 
(confirmed to work on Windows and Linux).You might need to change the port - see the Troubleshooting section.
To compile the files and output an executable, open a terminal window, navigate to the directory, and enter 
`g++ serialib.cpp SerialPrint.cpp -o SerialPrint.exe`. You might see some strange warnings, you can probably ignore
them. Now, run the executable from the terminal by entering `SerialPrint.exe` (`./SerialPrint.exe` in Linux).

If you're interested, quickly read through `SerialPrint.cpp` - you'll see that it's rather straightforward.
A serial port is opened and its output is read & printed directly to console, one line at a time.
If you're on Windows, some of the line breaks may not show up in notepad. Try using a different text
editor, like [Sublime Text](http://www.sublimetext.com/) or 
[Notepad++](https://notepad-plus-plus.org/download/v6.8.1.html).

Take a look at our `serial_example.ino` sketch - it displays an animation of an "o" moving back and forth,
and includes a command that clears the console screen. Make sure to stop `SerialPrint.exe` before uploading (hit
ctrl+c in the console window). (Although it has a bit of flicker (this isn't really the best way to implement
animation), it shows how you can do some pretty fancy stuff!

*You might not want to leave the Arduino plugged in for longer than 30-60 minutes. This program sends data
to your computer at a high rate and can cause it to overheat.*

####Adding User Input

Alright, so we proved that it can be done, but we can definitely make it much better.
Take a look at the code inside [`potentiometer_input`](potentiometer_input/), it's a modified version of
the potentiometer runner project that does serial outpout. You can build the .cpp
file the same way as `SerialPrint.cpp`, just make sure you copy it into the same folder as `serialib.cpp`.

This boosts efficiency by only sending a minimial amount of information (the position value as calculated
from the potentiometer's voltage reading) and offloading all the hard processing and printing work to the C++ 
program on the computer.

The C++ program includes a useful function called `getValues`, which extracts the variables in "label:value"
strings sent by the Arduino.
This example doesn't really  use it it to its full capacity - it just makes sure we actually received a "pos"
labeled position value. *(Maybe a logical next step would be to replace "pos" with "player1" or "player2"??)*

####Extension

This is the part where you come in - you now have the power to make your C++ applications interface with the
real world through your Arduino, so let your imagination run free! You should be able to write 
to the Arduino as well (see serialib's `Example1.cpp` and the Arduino example sketch under 
04.Communication > SerialEvent). Once again, if you're not comfortable writing C++ or you can't 
get the library to work on your computer, let one of the Mentors know - we'll be happy to help you get set 
up with a different serial communication library.

Some project ideas:
* Classic pong with potentiometer inputs (build knobs out of cardboard for better grip)
  * It's outside the scope of this tutorial, but check out 
    [ncurses](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/) for a way to have more control over
    what you can display to the console for ASCII games
* Upgrade your piano - make it play through your computer speakers, or team up with someone great at 
software and connect it to the Internet
* Use Visual C++/GTK+ to make a fancy GUI that displays sensor data for any of your previous projects

*If you don't feel comfortable learning C++ and would rather use python, check out [this great tutorial]
(https://learn.adafruit.com/arduino-lesson-17-email-sending-movement-detector/installing-python-and-pyserial)
by Adafruit that details how to install and use the pyserial library with your Arduino.*

##Troubleshooting

| Symptom          | Solution |
| --------         |--------- |
| "Problem uploading to board." | Make sure you didn't leave a program running that's using the USB port. |
| g++ not found | Do you have a C++ compiler installed? See above. |
| SerialPrint.exe unable to connect to port | It's possible that your Arduino is using a differently named port than usual. Try changing the value of DEVICE_PORT near the top of the SerialPrint.cpp to whatever's being used by your Arduino IDE (under Tools > SerialPort) |
| Something else | Yell for help! |

##How It Works

Communication protocols have been in development for decades, since the earliest computers. 
Even though it's somewhat slower,
[serial communication](https://learn.sparkfun.com/tutorials/serial-communication),
has won out over parallel when interfacing between devices because it can use as few as 2 wires. Imagine 
having to use eight of the pins on your Arduino just to send data to your computer!

Instead, many microcontroller chips, including yours, contain a 
[UART](https://en.wikipedia.org/wiki/Universal_asynchronous_receiver/transmitter) that "translates" between
the faster 8-bit parallel protocol used internally and the serial protocol that USB uses. It does this by
temporarily storing each byte of information, outputting a start bit, iterating through your message one bit at a 
time, and ending with a stop bit.
