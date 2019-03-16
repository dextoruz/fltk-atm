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
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include <iostream>
#include <string>
#include <fstream>

#define l 600
#define w 400

Fl_Window *win = 0;
Fl_Wizard *page = 0;

void back_cb(Fl_Widget*,void*) { page->prev(); }
void next_cb(Fl_Widget*,void*) { page->next(); }
void done_cb(Fl_Widget*,void*) { exit(0); }

struct click1{
  int x = 0;
};
struct click2
{
  int x = 0;
};


class login
{
  Fl_Box *warning;
  Fl_Box * wel;
  Fl_Int_Input *amount;
  Fl_Group *gr;
  Fl_Button *enter;
public:
  Fl_Button *lo;
  Fl_Button *cr;
  click1 *c1;
  click2 *c2;

  // virtual static void b1_cb(Fl_Widget *, void * b);
  static void lo_cb(Fl_Widget*,void *p  )
  {
    click1 * per = reinterpret_cast<click1*>(p);
    per->x = 1;
    win->hide();
  }
  static void cr_cb(Fl_Widget *,void *p2 )
  {
    click2 * per2 = reinterpret_cast<click2*>(p2);

    per2->x = 1;
    win->hide();
  }

  void firtPage()
  {
    Fl_Group *g = new Fl_Group(0,0,600,440,"Choose Option");

     wel = new Fl_Box(180,30,200,60,"Welcome to FBL");wel->labelsize(24);wel->labelfont(FL_BOLD+FL_ITALIC);
    lo = new Fl_Button(120,130,180,40,"Login");lo->labelsize(14);lo->labelfont(FL_BOLD);
    cr = new Fl_Button(120,190,180,40,"Create an Account");cr->labelsize(14);cr->labelfont(FL_BOLD);
    lo->callback(lo_cb,c1);
    cr->callback(cr_cb,c2);

    g->labelsize(14);
    g->end();
  }
  void enterAmount()
  {

      gr = new Fl_Group(0,0,l,w,"Instruction");
      amount = new Fl_Int_Input(200,150,180,30,"Amount: "); amount->labelsize(24);amount->value();
      enter = new Fl_Button(240,195,100,25,"Enter");
      enter->callback(next_cb);

      gr->labelsize(14);
      gr->end();
  }
  // void chooseAmount()
  // {
  //     Fl_Group *g = new Fl_Group(0,0,l,w,"Instruction");
  //
  //     Fl_Box * bx = new Fl_Box(180,30,200,60,"Choose Amount");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
  //     Fl_Button *b1 = new Fl_Button(80,120,120,40,"500");b1->labelsize(16);b1->labelfont(FL_BOLD);
  //     Fl_Button *b2 = new Fl_Button(80,180,120,40,"1000");b2->labelsize(16);b2->labelfont(FL_BOLD);
  //     Fl_Button *b3 = new Fl_Button(80,240,120,40,"5000");b3->labelsize(16);b3->labelfont(FL_BOLD);
  //     Fl_Button *b4 = new Fl_Button(380,240,120,40,"Other");
  //     b4->callback(next_cb);
  //     b4->labelsize(16);b4->labelfont(FL_BOLD);
  //     Fl_Button *b5 = new Fl_Button(380,180,120,40,"20000");b5->labelsize(16);b5->labelfont(FL_BOLD);
  //     Fl_Button *b6 = new Fl_Button(380,120,120,40,"10000");b6->labelsize(16);b6->labelfont(FL_BOLD);
  //
  //     b1->callback(b1b1_cb,blnce);
  //     // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
  //     // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
  //
  //     // b4->callback(next_cb);
  //
  //   g->labelsize(14);
  //   g->end();
  // }
  void Thank()
  {

      Fl_Group *g = new Fl_Group(0,0,l,w,"End");


      Fl_Box *bx = new Fl_Box(180,30,260,260,"THANK YOU!");bx->labelsize(30);bx->labelfont(FL_BOLD+FL_ITALIC);
      // Fl_Button *done = new Fl_Button(440,365,100,25,"Finish");
       // done->callback(done_cb);
      bx->labelcolor(fl_rgb_color(162, 40, 10));

      g->labelsize(14);
      g->end();

  }
  Fl_Int_Input *user;
  Fl_Secret_Input *pass;
    static void login_cb(Fl_Widget *, void *)
  {
    win->hide();
  }
  void LOGIN()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");g->labelsize(14);


    Fl_Box *bx = new Fl_Box(160,30,240,70,"Welcome to ATM");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    user = new Fl_Int_Input(200,150,180,25,"Acc/No: ");
    pass = new Fl_Secret_Input(200,190,180,25,"PIN ");
    Fl_Button *button = new Fl_Button(240,230,100,30,"Login");
    button->callback(login_cb);

    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

    g->end();
  }
  void loginWarn()
  {
    Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");g->labelsize(14);


    Fl_Box *bx = new Fl_Box(160,30,240,70,"Welcome to ATM");bx->labelsize(24);
    bx->labelfont(FL_BOLD+FL_ITALIC);
    user = new Fl_Int_Input(200,150,180,25,"Acc/No.");
    pass = new Fl_Secret_Input(200,190,180,25,"PIN ");
    Fl_Button *button = new Fl_Button(240,230,100,30,"Login");
    button->callback(login_cb);

    warning = new Fl_Box(240,280,100,30,"*Invalid username or pin*");
    warning->labelsize(22);
    warning->labelcolor(fl_rgb_color(162, 40, 10));

    // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
    g->end();
  }
  login()
  {}
  ~login()
  {}

};
