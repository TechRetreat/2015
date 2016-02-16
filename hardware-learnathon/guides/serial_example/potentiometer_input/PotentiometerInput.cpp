#include <iostream>
#include <stdlib.h>
#include "serialib.h"


#if defined (_WIN32) || defined( _WIN64)
#define         DEVICE_PORT             "COM1"          // COM1 for windows
#endif

#ifdef __linux__
#define         DEVICE_PORT             "/dev/ttyUSB0"  // ttyUSB0 for linux
#endif

using namespace std;

/* Use this function to turn a serial message of the form
 * "label:value" into its label and (integer) value components
 * Returns true if the message was successfully read.
*/
bool getValues (char const *const message, int const &numChars, char *label, int &value) {
    int labelLen = 0;
    int valStart = 0;
    int valLen = 0;

    for (int i=0; i<numChars; i++) {
        if (message[i] == ':') {
            labelLen = i;
            valStart = i+1;
            valLen = numChars - valStart;
        }
    }

    if (!labelLen || !valLen) return false;

    strncpy(label, message, labelLen);
    label[labelLen] = '\0';

    char valStr[valLen + 1] = "";
    strncpy(valStr, message+valStart, valLen);
    value = atoi(valStr);

    return true;
}

int main()
{
    serialib serialPort;
    char buffer[128], label[128];
    int numChars, retVal, pos;

    // Open serial port
    retVal = serialPort.Open(DEVICE_PORT,115200);
    if (retVal!=1) {
        cout << "Error while opening port. Permission problem?" << endl;
        return retVal;
    }
    cout << "Serial port opened successfully!" << endl;

    while (true) {
        // Read a series of bytes from the serial device
        numChars = serialPort.ReadString(buffer,'\n',128,5000);

        if (numChars>0) {
            // this call to getValues tries to take a message of the
            // form 'label:value' and load the values into 'label' and 'pos'
            if (getValues(buffer, numChars, label, pos) 
                    && !strcmp(label, "pos")) { // check if label is "pos"
                // clear the screen from this end
                system("cls"); // uncomment for Windows style clear screen
                //system("clear"); // uncomment for Mac/Linux style
                cout << string(80, '=') << endl;
                cout << string(pos, ' ') << 'O' << endl;
                cout << string(80, '=') << endl;
            }
        }
    } 


    // Close the connection with the device

    serialPort.Close();

    return 0;
}

