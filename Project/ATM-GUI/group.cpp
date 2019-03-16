#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
// #include <Fl/Fl_Text_Buffer>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "Login.h"



#ifdef _WIN32
// WINDOWS
#include <windows.h>
#define usleep(v) Sleep(v/1000)
#else
// UNIX
#include <unistd.h>                            // usleep
#endif
using namespace std;

void box()
{
  Fl_Box *b = new Fl_Box(300,250,100,60,"hi");
  b->labelsize(20);
}

void but_a_cb(Fl_Widget* , void* ){
  // ofstream out("example.txt"); out.close();
   // printf("\007"); fflush(stdout);
   box();


}



int main()
{

  Fl_Window win(600,440,"group");
  // Fl_Box *b = new Fl_Box(200,200,100,60);
  Fl_Group *grp1 = new Fl_Group(0,0,600,440,"ATM");
  Fl_Button but(200,101,100,40,"click");
  // but.shortcut("ali");
   but.callback(but_a_cb);
  // if(Fl::pushed())
  // {
  //   Fl_Box *b = new Fl_Box(100,100,100,50,"hwllo");
  // }
  // else
  // {
  //   Fl_Box *b = new Fl_Box(100,100,100,50,"HIH");
  // }
win.show();
win.resizable();
  Fl::run();


  // Fl_Group *grp2 = new Fl_Group(22,20,400,400,"Instruction");
  //   {
  //     Fl_Box *message = new Fl_Box(40,30,70,140,"button");
  //     message->labelsize(20);
  //    //  Fl_Text_Buffer *buff = new Fl_Text_Buffer();
  //    // Fl_Text_Display *disp = new Fl_Text_Display(0, 20, 800, 450);
  //    // disp->buffer(buff);
  //    // buff->text("A couple of Intstructions!");
  //   }
  //   grp2->labelsize(14);
  //   grp2->end();


    return 0;
}
