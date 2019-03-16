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



#ifdef _WIN32
// WINDOWS
#include <windows.h>
#define usleep(v) Sleep(v/1000)
#else
// UNIX
#include <unistd.h>                            // usleep
#endif
using namespace std;




class Login: public Fl_Window
{

public:
    string usr, pas;
    Fl_Box *title ;
    Fl_Box *warning;
    Fl_Button *button;
    Fl_Input *user;
    Fl_Secret_Input *pass ;
    static void cb_quit(Fl_Widget* , void* v) {

       ( (Login*)v )->cb_quit_i();
    }


    inline void cb_quit_i() {

        hide();
    }

    static void button_cb(Fl_Widget *wid, void *data)
    {
        Fl_Button *but = (Fl_Button*)wid;
        // but->callback(cb_quit,this);

    }
    // void text(const char *val) {
    //   warning->copy_label(val);
    // }

    Login(int w=600, int h=440,const char *tle="Login"):Fl_Window(w,h,tle)
    {
        begin();
            // Login = new Fl_Window(600,480);
            // Login->labelsize(24);
            title = new Fl_Box(160,30,240,70,"Welcome to ATM");
            user = new Fl_Input(200,150,180,25,"USERNAME ");user->value();
            pass = new Fl_Secret_Input(200,190,180,25,"PIN ");pass->value();
            button = new Fl_Button(240,230,100,30,"Login");button->callback(cb_quit,this);
            // button->callback(button_cb);

            title->labelsize(30);


            button->labelsize(16);
            usr = pass->value();
            pas = user->value();
            button->callback(cb_quit,this);

        end();
        resizable(this);
        show();
    }
    ~Login()
    { }
};
class Login2 :public Login
{
public:

  Login2(int w=600, int h=440,const char *tle="Login"):Login(w,h,tle)
  {
      begin();

          title = new Fl_Box(160,30,240,70,"Welcome to ATM");
          user = new Fl_Input(200,150,180,25,"USERNAME ");
          pass = new Fl_Secret_Input(200,190,180,25,"PIN ");
          button = new Fl_Button(240,230,100,30,"Login");
          // button->callback(button_cb);
          warning = new Fl_Box(240,280,100,30,"*Invalid username or pin*");
          warning->labelsize(22);
          warning->labelcolor(fl_rgb_color(162, 40, 10));
          title->labelsize(30);


          button->labelsize(16);
          pass->value();
          user->value();
          button->callback(cb_quit,this);

      end();
      resizable(this);
      show();
  }

};
////                        FOR EXECUTIION
/////// g++ main.cpp `fltk-config --ldstaticflags --cxxflags` -o main.exe && ./main.exe


int main(int argc, char **argv)
{

  int i = 0;
  string inpU ,inpP,outU,outP;


  Login wind;
  // wind.text("hello world");
  Fl::run();


  i+=1;
  // inpU = wind.user->value();
  // inpP = wind.pass->value();
  // ofstream out("login.txt");
  // out<<inpU<<' '<<inpP;
  // out.close();
  // ifstream in("login.txt");
  // in>>inpU>>inpP;

  if(inpU == "ali")
  {
    if(inpP == "1234")
    {
      ////// send to next window or group (amount gui)
    }
    else
    {
      Login2 win2;
      Fl::run();
      i+=1;
    }
  }
  else
  {
    Login2 win2;
    Fl::run();
    i+=1;
  }

  return 0;
}
