# Arduino Set-Up guide

# Drivers
For the event we will be giving you an Arduino Uno and if you can set up the drivers before the event it would save a lot of time!

**Mac:**

1. Download the [driver](CH341SER_MAC.ZIP?raw=true)

2. Double click the ZIP file and unzip it

3. Open the folder ~/Downloads/CH341SER_MAC

4. Run installer found in that folder

5. If asked to restart, do not restart just yet.

6. This next step is only needed if you are on OS-X Yosemite. For older versions of OS-X you do not need it:

  a. Open Terminal Application (it's located in /Application/Utilities) and type this command once you see a prompt:
`sudo nvram boot-args="kext-dev-mode=1"`

  b. See [this post](https://www.cindori.org/enabling-trim-on-os-x-yosemite/) if you wish to know why we need to run this command. I believe you need to do this because the driver is not signed properly, or is simply too old for Yosemite. Hopefully newer versions won't require this step and will automatically become enabled.
7. Now restart your Mac

**Windows:**

1. Download the [driver](CH341SER_WIN.ZIP?raw=true)

2. Double click the ZIP file and unzip it

3. Open the folder and run the installer 

4. Select INSTALL

5. Now restart your PC

**Linux:**

No drivers needed! Just plug and play.

# Arduino IDE

**Windows/Mac:**

Please download & install the Arduino IDE from [the official site](https://www.arduino.cc/en/Main/Software). This is the program that we will be using during the day of the event to program our circuit!

**Linux (Debian derivatives):**

Enter `sudo apt-get update && sudo apt-get install arduino arduino-core` in a terminal.
To run Arduino IDE, you have to run it as root: `sudo arduino`
<br>*For other distros, see http://playground.arduino.cc/Learning/Linux*

# Questions?

Please message Yu Chen at me@yuchen.io or on Slack if you are stuck somewhere!
