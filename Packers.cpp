// Packers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once

#include "pch.h"
#include "ConsoleAdjustments.h"
#include "Shared.h"
#include "Area.h"
#include "Packer.h"


//bool protectedSetCursor;


bool running = true;
unsigned char menu[] { 1,1,1 };
bool flag = false;


int main () {
  // font
  COORD fontS { 10,20 };
  ConsoleFont_SizeColour (fontS, L"Consolas", 0x09);
  // screen
  COORD leftANDtop { 15,15 };
  COORD widthANDheight { 107,28 };
  COLORREF backColour { RGB (50,50,50) };
  ConsoleScreen_SizeColourPosition (leftANDtop, widthANDheight, backColour);
  // codec
  UINT consoleOutputCPstorage;
  consoleOutputCPstorage = GetConsoleOutputCP (); // for later use
  SetConsoleOutputCP (CP_UTF8); // https://docs.microsoft.com/de-de/windows/desktop/Intl/code-page-identifiers
  // cursor
  ConsoleCursor_State (false);


  Area area1 (1);




  //area1.yellow (Packer1.position);
  //area1.yellow (Packer2.position);
  //area1.yellow (Packer3.position);
  //area1.red (Packer4.position);
  //area1.red (Packer5.position);
  //area1.red (Packer6.position);



  gotoXY (7, 0);
  std::cout << u8"Feel free to way in as a packer toward becoming an advanced packer ♥♥♥♥♥ :)";


  gotoXY (3, 20); ColourCout (u8"Packing speed:", 0x0f);
  gotoXY (3, 21); ColourCout (u8"  Stone age.", 0x0f);
  gotoXY (2, 21); ColourCout (u8"->", 0x0c);
  gotoXY (3, 22); ColourCout (u8"  Middle age...", 0x0f);
  gotoXY (3, 23); ColourCout (u8"  Advanced age.........", 0x0f);
  gotoXY (3, 24); ColourCout (u8"  Hollow age.         .", 0x0f);
  gotoXY (35, 20); ColourCout (u8"Character Choices:", 0x0f);
  gotoXY (35, 21); ColourCout (u8"  ☺  ", 0x07);
  gotoXY (40, 21); ColourCout (u8"    ☻", 0x0f);
  gotoXY (40, 21); ColourCout (u8"->", 0x0c);
  gotoXY (65, 21); ColourCout (u8"  Involve me!", 0x0f);
  gotoXY (64, 21); ColourCout (u8"->", 0x0c);
  gotoXY (65, 22); ColourCout (u8"  Let me furnish! :)", 0x0f);
  gotoXY (65, 23); ColourCout (u8"  Let's hit the road!", 0x0f);



  // guide bar
  gotoXY (6, 27); ColourCout (u8"♣:", 0x02); ColourCout (u8" a healthy resource", 0x09);
  gotoXY (38, 27); ColourCout (u8"☻:", 0x0f); ColourCout (u8" a beloved packer", 0x09);
  gotoXY (68, 27); ColourCout (u8"▪", 0x0f); ColourCout (u8" already packed!", 0x09);


  loading ();


  Packer Packer1 (100);
  Packer Packer2 (101);
  Packer Packer3 (102);
  Packer Packer4 (103);
  Packer Packer5 (104);
  Packer Packer6 (105);
  Packer Packer7 (106);
  Packer Packer8 (107);
  Packer Packer9 (108);
  Packer Packer10 (109);
  Packer Packer11 (110);
  Packer Packer12 (111);
  Packer Packer13 (112);
  Packer Packer14 (113);
  Packer Packer15 (114);
  Packer Packer16 (115);

  std::list<Packer> dataset;
  dataset.insert (dataset.begin (), Packer1);
  dataset.insert (dataset.begin (), Packer2);
  dataset.insert (dataset.begin (), Packer3);
  dataset.insert (dataset.begin (), Packer4);
  dataset.insert (dataset.begin (), Packer5);
  dataset.insert (dataset.begin (), Packer6);
  dataset.insert (dataset.begin (), Packer7);
  dataset.insert (dataset.begin (), Packer8);
  dataset.insert (dataset.begin (), Packer9);
  dataset.insert (dataset.begin (), Packer10);
  dataset.insert (dataset.begin (), Packer11);
  dataset.insert (dataset.begin (), Packer12);
  dataset.insert (dataset.begin (), Packer13);
  dataset.insert (dataset.begin (), Packer14);
  dataset.insert (dataset.begin (), Packer15);
  dataset.insert (dataset.begin (), Packer16);


  // status bar
  gotoXY (91, 3); ColourCout (u8"☻:", 0x0f); ColourCout (" " + std::to_string (dataset.size ()), 0x09);
  gotoXY (91, 4); ColourCout (u8"▪:", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 5); ColourCout (u8"♣:", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 7); ColourCout (u8"energy:", 0x0f);
  gotoXY (91, 8); ColourCout (u8"used ", 0x0f); ColourCout (" ", 0x09);
  gotoXY (91, 9); ColourCout (u8"ready ", 0x0f); ColourCout (" ", 0x09);




  // coding for action area
  //std::thread t1 (Packer::blinkPacking, dataset, 3);
  std::thread t1 (Packer::horizontalMovement, dataset, 3);


  //for (int i = 0; i < 100; i++) {

  //  Packer1.movement (1);
  //  Packer2.movement (1);
  //  Packer3.movement (1);
  //  Packer4.movement (1);
  //  Packer5.movement (1);
  //  Packer6.movement (1);

  //}





  while (running) {
    system ("pause>nul");


    pressed (menu, flag);






  }


  t1.join ();
  //t1.join ();
  SetConsoleOutputCP (consoleOutputCPstorage); // important: always set codec back to what it was
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
