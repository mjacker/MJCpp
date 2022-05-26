#include <iostream>
//import Example;


// https://theasciicode.com.ar/extended-ascii-code/box-drawings-double-vertical-line-character-ascii-code-186.html

using namespace std;

int main()
{
    char option;
    bool running = true;

    while (running){
        // Only it works with chcp 65001 or Region Settings with Beta: Use Unicode UTF-8 for worldwide language support
        // need to run intl.cpl
       /* cout << "╔════════════════════════╦═════════════════╗" << endl;
        cout << "║        JAIiME COLMAN   ║    MAIN PROGRAM ║ " << endl;
        cout << "╠════════════════════════╩═════════════════╣" << endl;
        cout << "║   1) Hello world.                        ║ " << endl;
        cout << "╠══════════════════════════════════════════╣" << endl;
        cout << "║   2) Arrays.                             ║ " << endl;
        cout << "╠══════════════════════════════════════════╣" << endl;
        cout << "║   0) Exit.                               ║ " << endl;
        cout << "╚══════════════════════════════════════════╝" << endl;*/
        cout << "                  Main                       ";
        cout << "---------------------------------------------";
        cout << " 1) Hello world." << endl;
        cout << " 2) Arrays." << endl;
        cout << "    >> "; cin >> option;

        if (option == '0')
            running = false;
        else if (option == '1'){
            cout << "CALL hello.cpp" << endl;
        }
    }   
    return 0;
}