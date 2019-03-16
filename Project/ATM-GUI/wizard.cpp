#include <stdlib.h>

#include <FL/Fl_Wizard.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Wizard.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include <iostream>
#include <string>
#include <fstream>

#define l 780
#define w 500

// Simple 'wizard' using fltk's new Fl_Wizard widget

Fl_Window *G_win = 0;
Fl_Wizard *G_wiz = 0;

void back_cb(Fl_Widget*,void*) { G_wiz->prev(); }
void next_cb(Fl_Widget*,void*) { G_wiz->next(); }
void done_cb(Fl_Widget*,void*) { exit(0); }

int main(int argc, char **argv) {
    G_win = new Fl_Window(l,w,"ATM");
    G_wiz = new Fl_Wizard(0,0,l,w);
    {
      Fl_Group *g = new Fl_Group(0,0,600,440,"Choose Option");

      Fl_Box * bx = new Fl_Box(180,30,200,60,"Welcome to FBL");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
      Fl_Button *b1 = new Fl_Button(80,110,180,40,"Login");b1->labelsize(14);b1->labelfont(FL_BOLD);
      Fl_Button *b2 = new Fl_Button(80,180,180,40,"Create an Account");b2->labelsize(14);b2->labelfont(FL_BOLD);
      Fl_Button *done = new Fl_Button(80,250,180,35,"Exit");done->labelfont(FL_BOLD); done->callback(done_cb);

      Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);

      g->labelsize(14);
      g->end();
    }
    {
      Fl_Group *g = new Fl_Group(0,0,l,w,"Create a Account");
      Fl_Box * bx = new Fl_Box(180,30,200,60,"Create an account");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);

      Fl_Input *fname = new Fl_Input(100,100,130,25,"First Name ");fname->value();
      Fl_Input *lname = new Fl_Input(370,100,130,25,"Last Name ");lname->value();
      Fl_Input *father = new Fl_Input(100,140,180,25,"Father Name ");father->value();
      Fl_Input *cnic = new Fl_Input(100,180,180,25,"CNIC ");cnic->value();
      Fl_Input *phone = new Fl_Input(100,220,180,25,"Phone ");phone->value();
      Fl_Input *age = new Fl_Input(100,260,80,25,"Age ");age->value();
      Fl_Input *gender = new Fl_Input(300,260,80,25,"Gender ");gender->value();
      Fl_Input *balance = new Fl_Input(100,300,180,25,"Balance ");balance->value();


      Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
      g->labelsize(14);
      g->end();
    }

    {
      Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");g->labelsize(14);


      Fl_Box *title = new Fl_Box(160,30,240,70,"Welcome to ATM");
      Fl_Input *user = new Fl_Input(200,150,180,25,"USERNAME ");user->value();
      Fl_Secret_Input *pass = new Fl_Secret_Input(200,190,180,25,"PIN ");pass->value();
      Fl_Button *button = new Fl_Button(240,230,100,30,"Login");button->callback(next_cb);

      Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);

      g->end();
    }
    {
      Fl_Group *g = new Fl_Group(0,0,l,w,"Choose Option");

      Fl_Box * bx = new Fl_Box(180,30,200,60,"Choose Option");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
      Fl_Button *b1 = new Fl_Button(80,110,140,30,"Withdraw");b1->labelsize(14);b1->labelfont(FL_BOLD);
      Fl_Button *b2 = new Fl_Button(80,160,140,30,"Deposit");b2->labelsize(14);b2->labelfont(FL_BOLD);
      Fl_Button *b3 = new Fl_Button(80,210,140,30,"Transfer");b3->labelsize(14);b3->labelfont(FL_BOLD);
      Fl_Button *b4 = new Fl_Button(80,260,140,30,"Check Balance");b4->labelsize(14);b4->labelfont(FL_BOLD);
      Fl_Button *b5 = new Fl_Button(80,310,140,30,"Change PIN");b5->labelsize(14);b5->labelfont(FL_BOLD);
      // Fl_Button *b6 = new Fl_Button(80,420,120,40,"5000");b6->labelsize(16);b6->labelfont(FL_BOLD);

      Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);

      g->labelsize(14);
      g->end();

    }
    {
        Fl_Group *g = new Fl_Group(0,0,l,w,"Instruction");

        Fl_Box * bx = new Fl_Box(180,30,200,60,"Choose Amount");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
        Fl_Button *b1 = new Fl_Button(80,120,120,40,"500");b1->labelsize(16);b1->labelfont(FL_BOLD);
        Fl_Button *b2 = new Fl_Button(80,180,120,40,"1000");b2->labelsize(16);b2->labelfont(FL_BOLD);
        Fl_Button *b3 = new Fl_Button(80,240,120,40,"5000");b3->labelsize(16);b3->labelfont(FL_BOLD);
        Fl_Button *b4 = new Fl_Button(380,240,120,40,"Other");b4->callback(next_cb);b4->labelsize(16);b4->labelfont(FL_BOLD);
        Fl_Button *b5 = new Fl_Button(380,180,120,40,"20000");b5->labelsize(16);b5->labelfont(FL_BOLD);
        Fl_Button *b6 = new Fl_Button(380,120,120,40,"10000");b6->labelsize(16);b6->labelfont(FL_BOLD);

        Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

        b4->callback(next_cb);
       //  Fl_Text_Buffer *buff = new Fl_Text_Buffer();
       // Fl_Text_Display *disp = new Fl_Text_Display(0, 20, 800, 450);
       // disp->buffer(buff);
       // buff->text("A couple of Intstructions!");

      g->labelsize(14);
      g->end();
    }
    {
      Fl_Group *g = new Fl_Group(0,0,l,w,"Instruction");
      Fl_Input *amount = new Fl_Input(200,150,180,30,"Amount: "); amount->value();
      Fl_Button *next = new Fl_Button(240,195,100,25,"Enter"); next->callback(next_cb);
      g->labelsize(14);
      g->end();

    }
    {
      Fl_Group *g = new Fl_Group(0,0,l,w,"End");

      Fl_Box * bx = new Fl_Box(180,30,260,260,"THANK YOU!");bx->labelsize(30);bx->labelfont(FL_BOLD+FL_ITALIC);
      bx->labelcolor(fl_rgb_color(162, 40, 10));

      g->labelsize(14);
      g->end();
    }
    // Wizard: page 1
    {
        Fl_Group *g = new Fl_Group(0,0,l,w);
        Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
        // Fl_Multiline_Output *out = new Fl_Multiline_Output(10,30,400-20,300-80,"Welcome");
        // out->labelsize(20);
        // out->align(FL_ALIGN_TOP|FL_ALIGN_LEFT);
        // out->value("This is First page");
        g->end();
    }
    // Wizard: page 2
    {
        Fl_Group *g = new Fl_Group(0,0,l,w);
        Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
        Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
        // Fl_Multiline_Output *out = new Fl_Multiline_Output(10,30,400-20,300-80,"Terms And Conditions");
        // out->labelsize(20);
        // out->align(FL_ALIGN_TOP|FL_ALIGN_LEFT);
        // out->value("This is the Second page");
        g->end();
    }
    // Wizard: page 3
    {
        Fl_Group *g = new Fl_Group(0,0,l,w);
        Fl_Button *done = new Fl_Button(440,365,100,25,"Finish"); done->callback(done_cb);
        Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
        // Fl_Multiline_Output *out = new Fl_Multiline_Output(10,30,400-20,300-80,"Finish");
        // out->labelsize(20);
        // out->align(FL_ALIGN_TOP|FL_ALIGN_LEFT);
        // out->value("This is the Last page");
        g->end();
    }
    G_wiz->end();
    G_win->end();
    G_win->resizable();
    G_win->show(argc, argv);
    return Fl::run();
}
