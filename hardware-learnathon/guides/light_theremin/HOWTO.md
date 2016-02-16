#Light Theremin

A [theremin](https://youtu.be/w5qf9O6c20o?t=13s) is an electronic musical instrument developed by Russian inventor Leon Theremin in 1920. It’s well known for being the only instrument that is played without any physical contact; the pitch changes depending on how close your hand is to the antenna. We can create a similar effect very simply by using light and a photoresistor.

##What We Need

* 1x Photoresistor

<img src="http://p.globalsources.com/IMAGES/PDT/B1059413054/CDS-Photoresistor-LDR.jpg" height="100px">
* 1x 10kΩ Resistor

<img src="http://media.nkcelectronics.com/img/res_10k.jpg" height="100px">
* 1x Piezo speaker

<img src="https://content.solarbotics.com/products/photos/93c51bd69dcc15a0f60bb6bb4c96d4df/lrg/17855-dscn3894.JPG" height="100">
* Arduino Uno
* Wires (at least 4)
* Breadboard


##How To Make It

####Let There Be Light!

A **photoresistor** is a special kind of *variable resistor* - the more light there is shining on it, the lower its resistance value is. By covering the photoresistor with your hand, you decrease the amount of light shining on it; the closer your hand, the less light it receives (try to get your shadow to fall on it).

1. Build the simple circuit shown in the diagram, making sure to plug the *Analog 0* input pin into the same row of the breadboard connecting the resistor and photoresistor.
<br><img src="https://cloud.githubusercontent.com/assets/3172103/9149063/ffd76702-3d63-11e5-8d6a-c6991a9d9cf7.png" width="400px">&nbsp;<img src="https://cloud.githubusercontent.com/assets/3172103/9149062/ffd68986-3d63-11e5-84c6-df7e8d98d21c.png" width="400px">

2. We’re going to write code that reads the analog sensor value on pin A0 and outputs it to console. Remember to include a small delay to give your sensor time to get a new reading. Give it a shot if you feel comfortable, and then check out our code in `photoresistor.ino`

3. You’ll notice that our code contains two constants at the top for upper and lower input values (go ahead and add these to your own code if you’d rather use that). Look at the range sensor values that your Arduino prints, and try to pick values just within this range. For example, our value maxed out at around 570 when uncovered and dropped to 290 when covered fully, so we set our upper and lower values to 550 and 300. Your values will probably be different from your neighbour’s, depending on your photoresistor and where in the room you’re sitting. You’ll use the values later.

####Music To My Ears

Next, we’re going to connect and test out the Piezo speaker.

1. Connect the speaker a little further down the breadboard, one end to ground and the other to pin 4 (or whichever
your favourite may be).
<br><img src="https://cloud.githubusercontent.com/assets/3172103/9149060/ffd35446-3d63-11e5-9f50-5de922654e4f.png" width="400px">&nbsp;<img src="https://cloud.githubusercontent.com/assets/3172103/9149061/ffd53fea-3d63-11e5-9942-d2799b83fa62.png" width="400px">

2. We’re going to use Arduino’s `tone()` function to play a sound on pin 4. Create a new sketch and write code that calls either `tone(pin, frequency)` or `tone(pin, frequency, duration)` and experiment with different frequency values.

3. Check out our code in `speaker.ino` and, again, notice the upper and lower frequency constants at the top. Copy these values into your code and set them to the highest frequency that doesn’t hurt your ears (or ours!!) and the lowest frequency that doesn’t sound too buzzy.

####Putting It All Together

Almost there! Remember, the goal is to make a theremin-type instrument - the frequency of sound you output on the speaker should change depending on how close your hand is to the photoresistor.

*Hint: the Arduino* `map()` *function may come in handy. You can call it using* `map(value, lowerA, upperA, lowerB, upperB)` *and it returns the value ‘mapped’ from range A onto range B. If you like math, go ahead and write this simple calculation yourself!*

1. Start by combining what you’ve written so far into one file - believe it or not, you’re almost done!

2. You probably want to ignore any values outside your input range, this way it won’t play if you leave it uncovered or cover it completely. *Hint: look up the Arduino* `noTone()` *function.*

3. If the sensor reading is good, find a way to convert it into a corresponding frequency value to output to the speaker.

4. Hopefully you managed to make it here and have spent some time playing with your creation. If not, don’t fret! Read through our final implementation in `light_theremin.ino` and see if it makes sense.

####Extension

The easiest way to improve the project is to play more with the constants until you find some optimal values.
There are, however, many broader improvements you can make - maybe you could try your hand at allowing
the user to calibrate the sensor instead of hardcoding in upper and lower values?

[Building a real, purely electronic theremin](http://www.cs.nmsu.edu/~rth/EMTheremin.pdf) can take some time
(way longer than a one-day hackathon!), but we can improve this project to more closely resemble one. For
example, a theremin has two antennas; one controls pitch, while the other controls volume. There are also
knobs that let you control things like timbre and brightness. You have three more photoresistors to
experiment with, and you can hook them up the same way - just keep track of which analog pin you
connect each one to.

##How It Works

Those of you who are interested in physics might want to know how photoresistors work. The simple answer is that the surface contains a semiconducting material that’s sensitive to light. If photons fall on this material, they excite the electrons to a point where they are able to flow more freely and carry a current, thereby lowering the resistance. For a more in-depth explanation, [Wikipedia is your friend!](https://en.wikipedia.org/wiki/Photoresistor)

The varying resistance causes a change in the voltage drop across the photoresistor. When the Arduino reads analog inputs, what it’s actually doing is reading a voltage and converting the value from (by default) 0 to 5V to a useable integer between 0 and 1024. Common applications include energy saving night lights, light seeking robots, and laser tripwires.
