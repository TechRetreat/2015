#Importing Libraries Tutorial

Often when working with a new sensor or chip, you'll find that somebody else has already
done all the hard low-level work. There are tons of open-source libraries for Arduino on the internet
that you can import into your program, saving you a lot of effort. Just follow this process:

1. Download the library you want to use, usually as a zip file. For example, check out the 
CapacitiveSensor library mentioned in [touch_sensor_example](touch_sensor_example/HOWTO.md).

2. There should be an Arduino folder in your home directory (if not, go ahead and make one). Extract
the zip into `Arduino/libraries/<name_of_library>`, where the folder name matches the name of the library's
code file. For example, `CapacitiveSensor.h` and `CapacitiveSensor.cpp` should now be in the folder
`Arduino/libraries/CapacitiveSensor`.

3. In your Arduino IDE, click on "Sketch > Import Library... > Add Library..." and select the **folder** containing
your library file (not the actual .cpp file!). There should be a message at the bottom of the window letting 
you know it imported successfully.

4. Create the new sketch that you plan to use the library in. Click on "Sketch > Import Library..."
and select the library you just imported. If it doesn't appear, try closing and reopening the Arduino program.

5. You're ready to go! Look for example Arduino programs included in the zip file that showcase how to use it.
