// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"

HANDLE consoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
COORD CurrentCursorPosition;

class packMan {
  char Sign;
public:
  packMan () :Sign ('$') {};
  //packMan (//userchoice) :Sign () {};

  COORD GetPackerCursorPosition (HANDLE hConsoleOutput) {
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBinfo;
    if (GetConsoleScreenBufferInfo (hConsoleOutput, &consoleScreenBinfo)) {
      return consoleScreenBinfo.dwCursorPosition;
    }
    else {
      // call GetLastError() for detail
      COORD invalid {0,0};
      return invalid;
    }
  }
};

class Area {
  int rows;
  int columns;
  struct materials {
    char hWalls {char (205)};
    char vWalls {char (186)};
    char edges[4] {char (201),char (200),char (188),char (187)};
    char pack {char (05)};
  } stuff;
public:
  Area () :rows (20), columns (90) {
    for (int i = 2; i<=22; i++) {
      for (int j = 10; j<=100; j++) {
        gotoXY (i, j);

        // first horizontal wall
        if (i==2&&j!=100) {

          // left top edge
          if (i==2&&j==10)
            std::cout<<stuff.edges[0];
          std::cout<<stuff.hWalls;
        }

        // right top edge
        if (i==2&&j==100)
          std::cout<<stuff.edges[3];

        // left bottom edge
        if (i==22&&j==10)
          std::cout<<stuff.edges[1];

        // second horizontal wall
        if (i==22&&j!=100)
          std::cout<<stuff.hWalls;
        else
          // right bottom edge
          if (i==22&&j==100)
            std::cout<<stuff.edges[2];
          else

            // vertical walls
            if (j==10||j==100)
              if (i!=2)
                std::cout<<stuff.vWalls;

        // packs
        if (i!=2&&i!=22)
          if (j!=10&&j!=100)
            if (j!=11&&j!=99)
              std::cout<<stuff.pack;
      }
      std::cout<<"\n";
    }



  };
  //Area(//userchoice) :rows (),columns() {};
  void gotoXY (int y, int x) {
    COORD CursorPosition;
    CursorPosition.Y = y;
    CursorPosition.X = x;
    SetConsoleCursorPosition (consoleHandle, CursorPosition);
  }


};
void aBigChange (void) {
  HANDLE consoleOutput = GetStdHandle (STD_OUTPUT_HANDLE); // for simplification (constant calls to the function)
  CONSOLE_SCREEN_BUFFER_INFOEX screenBinfoEX; // <windows.h>
  COLORREF BGcolor {RGB (100,100,100)}; // the same
  CONSOLE_FONT_INFOEX fontInfoEX; // the same
  HWND consoleWindow = GetConsoleWindow ();

  screenBinfoEX.cbSize = sizeof (screenBinfoEX); // the right size is important for many structures in the windows API
  GetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  screenBinfoEX.srWindow.Left = 0;
  screenBinfoEX.srWindow.Right = 110;
  screenBinfoEX.srWindow.Top = 0;
  screenBinfoEX.srWindow.Bottom = 32;
  screenBinfoEX.ColorTable[0] = BGcolor; // background colour
  SetConsoleScreenBufferInfoEx (consoleOutput, &screenBinfoEX);
  SetConsoleWindowInfo (consoleOutput, false, &screenBinfoEX.srWindow);

  fontInfoEX.cbSize = sizeof (fontInfoEX); // the right size is important for many structures in the windows API
  GetCurrentConsoleFontEx (consoleOutput, false, &fontInfoEX);
  //font.dwFontSize.X = 10; // for not true type fonts
  fontInfoEX.dwFontSize.Y = 20; // Y is enough for true type fonts
  lstrcpyW (fontInfoEX.FaceName, L"Consolas"); // copying the properties of wished font to the suitable field
  SetCurrentConsoleFontEx (consoleOutput, false, &fontInfoEX);

  SetConsoleTextAttribute (consoleOutput, 0x09); // octal (0 for not filling, 9 for a beautiful blue) third number also possible which reminds of old system without proper graphic driver.

  SetWindowPos (consoleWindow, HWND_TOP, 15, 15, 0, 0, SWP_NOSIZE);
}

int main () {

  bool running = true;
  int a {1}, b {1}, c {1};
  aBigChange ();

  packMan Packer1;
  Area area1;

  area1.gotoXY (1, 10);
  std::cout<<"Feel free to take control over one of the packers toward becoming an advanced packer... :)";


  area1.gotoXY (24, 13); std::cout<<"Packing speed:";
  area1.gotoXY (25, 13); std::cout<<"  Stone age.";
  area1.gotoXY (26, 13); std::cout<<"  Middle age..";
  area1.gotoXY (27, 13); std::cout<<"  Industry age....";
  area1.gotoXY (28, 13); std::cout<<"  Advanced age...........";
  area1.gotoXY (29, 13); std::cout<<"  Hollow age..     .          .";
  area1.gotoXY (24, 50); std::cout<<"Charachter Choices:";
  area1.gotoXY (25, 50); std::cout<<"  "<<char (1);
  area1.gotoXY (26, 50); std::cout<<"  "<<char (2);
  area1.gotoXY (26, 75); std::cout<<"  Involve me!";
  area1.gotoXY (26, 74); std::cout<<"->";
  area1.gotoXY (27, 75); std::cout<<"  Let me furnish! :)";





  while (running) {
    system ("pause>nul");
    if (GetAsyncKeyState (VK_DOWN)) {
      if (a!=2) {
        area1.gotoXY (26, 74); std::cout<<"  ";
        area1.gotoXY (27, 74); std::cout<<"->";
        ++a;
      }
    }
    if (GetAsyncKeyState (VK_UP)) {
      if (a!=1) {
        area1.gotoXY (26, 74); std::cout<<"->";
        area1.gotoXY (27, 74); std::cout<<"  ";
        --a;
      }
    }
    if (GetAsyncKeyState (VK_LEFT)) {

    }
    if (GetAsyncKeyState (VK_RIGHT)) {

    }


  }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
