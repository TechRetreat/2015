#Hall Effect Sensors

Hall effect sensors are used to detect the presence of magnetic fields. When the south pole of a magnet
is brought near the front face of the sensor, it closes the connection between the ground (middle) and
output(right) pins. *Note: the 'front' face is the smaller side.*

<img src="http://bildr.org/blog/wp-content/uploads/2011/04/a1321.png" height="400px">

##How To Use It

1. Connect the sensor to your Arduino like the picture above shows. When there's no magnetic field detected,
the the output pin is held at +5V, so you will read a number close to 1023. Bringing a magnet nearby will
cause the analog input pin to drop near 0.

2. You can get (and even take home!) some small neodymium magnets from us. Be careful, though! They're
very strong for their size, so keep them well away from credit cards and electronics. On top of this, they
are **very fragile.** If you drop one, or even let it go near another magnet or metal surface it's attracted to,
it will very likely shatter. 

3. Test it out by performing a digitalRead (inside of `loop()`) and printing the value to console. Upload
this simple program and bring the magnet nearby - you should see the input state change! *Note that only
one face of the magnet will work.*

##What It's Used For

Hall effect sensors are pretty versatile, and used in many position and orientation sensing applications.
Some examples are to sense the position of the gear shift lever and as liquid level sensors in gas tanks in cars,
to activate an electronic lock when a door is closed, and to sense the rotation speed of a motor or gear.
Some more ideas 
[can be found here.](http://www.allegromicro.com/en/Design-Center/Technical-Documents/Hall-Effect-Sensor-IC-Publications/Position-and-Level-Sensing-Using-Hall-Effect-Sensing-Technology.aspx)

You could try making a wheel encoder that calculates the *rpm* of a rotating object or an alarm that goes off
when a "door" is opened; get creative with some of the crafts materials we have available.
