#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Radio_Round_Button.H>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include <iostream>
#include <string>
// #include "groupClass.h"
#include <fstream>


#ifdef _WIN32
// WINDOWS
#include <windows.h>
#define usleep(v) Sleep(v/1000)
#else
// UNIX
#include <unistd.h>                            // usleep
#endif
using namespace std;

#define l 600
#define w 400

// Simple 'wizard' using fltk's new Fl_Wizard widget

Fl_Wizard *G_wiz = 0;
void back_cb(Fl_Widget*,void*) { G_wiz->prev(); }
void next_cb(Fl_Widget*,void*) { G_wiz->next(); }
void done_cb(Fl_Widget*,void*) { exit(0); }

class messageBox
{

public:
  void Thank()
  {

      Fl_Group *g = new Fl_Group(0,0,l,w,"End");


      Fl_Box *bx = new Fl_Box(180,30,260,260,"THANK YOU!");bx->labelsize(30);bx->labelfont(FL_BOLD+FL_ITALIC);
      // Fl_Button *done = new Fl_Button(440,365,100,25,"Finish"); done->callback(done_cb);
      bx->labelcolor(fl_rgb_color(162, 40, 10));

      g->labelsize(14);
      g->end();

  }
  void chkBalance()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Transfer");

    Fl_Box * bx = new Fl_Box(180,30,200,260,"Your Balance is XXXXXXXXX");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);


    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);


    g->labelsize(14);
    g->end();
  }
  void transAmount()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w);

    Fl_Box * bx = new Fl_Box(180,30,200,260,"Amount has been transfered");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    bx->labelsize(22);
    bx->labelcolor(fl_rgb_color(162, 40, 10));


    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);


    g->labelsize(14);
    g->end();
  }
  void wrongInfo()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w);

    Fl_Box * bx = new Fl_Box(180,30,200,150,"Invalid Information!");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    bx->labelsize(22);
    bx->labelcolor(fl_rgb_color(162, 40, 10));


    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);


    g->labelsize(14);
    g->end();
  }
  void pinMessage()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w);

    Fl_Box * bx = new Fl_Box(180,30,200,150,"Your PIN has been changed.");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    bx->labelsize(22);




    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);


    g->labelsize(14);
    g->end();
  }


};

class group: public messageBox
{
private:
  Fl_Group *g ;
  Fl_Box *bx;
  Fl_Input *amount;
  Fl_Input *user;
  Fl_Secret_Input *pass;
  Fl_Button *next;
  Fl_Box *warning;
public:

  void enterAmount()
  {

      g = new Fl_Group(0,0,l,w,"Instruction");
      amount = new Fl_Input(200,150,180,30,"Amount: "); amount->labelsize(24);amount->value();
      next = new Fl_Button(240,195,100,25,"Enter"); next->callback(next_cb);


          // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
          // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

      g->labelsize(14);
      g->end();


  }
  void chngPin()
  {
    g = new Fl_Group(0,0,l,w,"Instruction");
    Fl_Box * bx = new Fl_Box(180,30,200,60,"Change PIN");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    Fl_Input *user = new Fl_Input(200,150,160,30,"Current PIN ");user->value();
    Fl_Input *amount = new Fl_Input(200,190,160,30,"New PIN ");amount->value();
    Fl_Input *sender = new Fl_Input(200,230,160,30,"Re-type ");sender->value();
    Fl_Button *b5 = new Fl_Button(220,270,120,25,"Send");b5->labelsize(14);b5->labelfont(FL_BOLD);


    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

    g->labelsize(14);
    g->end();
  }
  void createAccount()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Create a Account");
    Fl_Box * bx = new Fl_Box(180,30,200,60,"Create an account");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);

    Fl_Input *fname = new Fl_Input(110,100,130,25,"First Name ");fname->value();
    Fl_Input *lname = new Fl_Input(370,100,130,25,"Last Name ");lname->value();
    Fl_Input *father = new Fl_Input(110,140,180,25,"Father Name ");father->value();
    Fl_Input *cnic = new Fl_Input(110,180,180,25,"CNIC ");cnic->value();
    Fl_Input *phone = new Fl_Input(110,220,180,25,"Phone ");phone->value();
    Fl_Input *age = new Fl_Input(110,260,80,25,"Age ");age->value();
    Fl_Radio_Round_Button *male = new Fl_Radio_Round_Button(320,250,80,25,"Male");male->value();
    Fl_Radio_Round_Button *female = new Fl_Radio_Round_Button(320,270,80,25,"Female");female->value();
    Fl_Radio_Round_Button *other = new Fl_Radio_Round_Button(320,290,80,25,"Other");other->value();
    Fl_Input *balance = new Fl_Input(110,300,180,25,"Balance ");balance->value();


    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
    g->labelsize(14);
    g->end();
  }
  void loginWarn()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");g->labelsize(14);


    Fl_Box *bx = new Fl_Box(160,30,240,70,"Welcome to ATM");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    Fl_Input *user = new Fl_Input(200,150,180,25,"Acc/No.");user->value();
    Fl_Secret_Input *pass = new Fl_Secret_Input(200,190,180,25,"PIN ");pass->value();
    Fl_Button *button = new Fl_Button(240,230,100,30,"Login");button->callback(next_cb);

    warning = new Fl_Box(240,280,100,30,"*Invalid username or pin*");
    warning->labelsize(22);
    warning->labelcolor(fl_rgb_color(162, 40, 10));

    Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
    g->end();
  }
  void LOGIN()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");g->labelsize(14);


    Fl_Box *bx = new Fl_Box(160,30,240,70,"Welcome to ATM");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    Fl_Input *user = new Fl_Input(200,150,180,25,"Acc/No: ");user->value();
    Fl_Secret_Input *pass = new Fl_Secret_Input(200,190,180,25,"PIN ");pass->value();
    Fl_Button *button = new Fl_Button(240,230,100,30,"Login");button->callback(next_cb);

    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

    g->end();
  }

  void chooseOption()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");

    Fl_Box * bx = new Fl_Box(180,30,200,60,"Choose Option");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    Fl_Button *b1 = new Fl_Button(80,110,140,30,"Withdraw");b1->labelsize(14);b1->labelfont(FL_BOLD);
    Fl_Button *b3 = new Fl_Button(80,160,140,30,"Transfer");b3->labelsize(14);b3->labelfont(FL_BOLD);
    Fl_Button *b4 = new Fl_Button(80,210,140,30,"Check Balance");b4->labelsize(14);b4->labelfont(FL_BOLD);
    Fl_Button *b5 = new Fl_Button(80,260,140,30,"Change PIN");b5->labelsize(14);b5->labelfont(FL_BOLD);
    // Fl_Button *b6 = new Fl_Button(80,420,120,40,"5000");b6->labelsize(16);b6->labelfont(FL_BOLD);

    Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

    g->labelsize(14);
    g->end();

  }
  void firtPage()
  {
    Fl_Group *g = new Fl_Group(0,0,600,440,"Choose Option");

    Fl_Box * bx = new Fl_Box(180,30,200,60,"Welcome to FBL");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    Fl_Button *b1 = new Fl_Button(80,110,180,40,"Login");b1->labelsize(14);b1->labelfont(FL_BOLD);
    Fl_Button *b2 = new Fl_Button(80,170,180,40,"Create an Account");b2->labelsize(14);b2->labelfont(FL_BOLD);
    Fl_Button *b3 = new Fl_Button(80,230,180,40,"Deposit");b3->labelsize(14);b3->labelfont(FL_BOLD);
    // Fl_Button *done = new Fl_Button(80,290,180,35,"Exit");done->labelfont(FL_BOLD); done->callback(done_cb);

    Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

    g->labelsize(14);
    g->end();
  }
  void tranfer()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Transfer");

    Fl_Box * bx = new Fl_Box(180,30,200,60,"Transfer");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    Fl_Input *user = new Fl_Input(200,150,160,30,"Sender Acc/No. ");user->value();
    Fl_Input *amount = new Fl_Input(200,190,160,30,"Amount ");amount->value();
    Fl_Input *sender = new Fl_Input(200,230,160,30,"Reciever Acc/No. ");sender->value();
    Fl_Button *b5 = new Fl_Button(220,270,120,25,"Send");b5->labelsize(14);b5->labelfont(FL_BOLD);

    Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);


    g->labelsize(14);
    g->end();
  }

  void deposit()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w);

      Fl_Box * bx = new Fl_Box(180,70,200,60,"Deposit");bx->labelsize(30);bx->labelfont(FL_BOLD+FL_ITALIC);
      Fl_Input *user = new Fl_Input(200,150,160,30,"Acc/No. ");user->value();
      Fl_Input *amount = new Fl_Secret_Input(200,190,160,30,"Amount ");amount->value();
      Fl_Button *b5 = new Fl_Button(220,230,120,25," OK ");b5->labelsize(14);b5->labelfont(FL_BOLD);

      Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
      Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);


    g->labelsize(14);
    g->end();
  }
  void chooseAmount()
  {
      Fl_Group *g = new Fl_Group(0,0,l,w,"Instruction");

      Fl_Box * bx = new Fl_Box(180,30,200,60,"Choose Amount");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
      Fl_Button *b1 = new Fl_Button(80,120,120,40,"500");b1->labelsize(16);b1->labelfont(FL_BOLD);
      Fl_Button *b2 = new Fl_Button(80,180,120,40,"1000");b2->labelsize(16);b2->labelfont(FL_BOLD);
      Fl_Button *b3 = new Fl_Button(80,240,120,40,"5000");b3->labelsize(16);b3->labelfont(FL_BOLD);
      Fl_Button *b4 = new Fl_Button(380,240,120,40,"Other");b4->callback(next_cb);b4->labelsize(16);b4->labelfont(FL_BOLD);
      Fl_Button *b5 = new Fl_Button(380,180,120,40,"20000");b5->labelsize(16);b5->labelfont(FL_BOLD);
      Fl_Button *b6 = new Fl_Button(380,120,120,40,"10000");b6->labelsize(16);b6->labelfont(FL_BOLD);

      Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
      Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

      b4->callback(next_cb);

    g->labelsize(14);
    g->end();
  }


  group()
  {}
  ~group()
  {}



};

int main()
{
  int x = 1;

  group c;
  Fl_Window *G_win = new Fl_Window(l,w,"ATM");
  G_wiz = new Fl_Wizard(0,0,l,w);
  {
    c.firtPage();
    // c.createAccount();
    c.deposit();
    c.LOGIN();
    c.loginWarn();
    c.chooseOption();
    c.chooseAmount();
    c.enterAmount();
    c.tranfer();
    c.chngPin();

    c.pinMessage();
    c.wrongInfo();
    c.transAmount();
    c.chkBalance();
    c.Thank();

  }








  G_wiz->end();
  G_win->end();
  G_win->resizable(G_win);
  G_win->show();
  Fl::run();


  return 0;
}
