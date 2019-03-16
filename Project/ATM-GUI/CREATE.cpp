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
#include "CREATE.h"

using namespace std;

#define l 600
#define w 400

// Fl_Window *win = 0;
// Fl_Wizard *page = 0;


class teto: public Acount
{
public:

  void storeData(Info1 temp2)
  {
    string str(temp2.accNo);
    ofstream out1("Data/"+str + ".csv");
    out1<<temp2.accNo<<','<<temp2.fname<<' '<<temp2.lname<<','<<temp2.balance<<
    ','<<temp2.pin<<','<<'\n';
    out1.close();
    ofstream out("Data/usersData.csv",ios::app);
    out<<temp2.accNo<<','<<temp2.fname<<' '<<temp2.lname<<','
    <<temp2.father<<',';
    string str1(temp2.cnic);
    string str2(temp2.phone);
    out<<str1<<','<<str2<<','<<temp2.age<<','<<temp2.balance<<','<<'\n';
    out.close();


  }
  void gendr()
  {
    if(person->obj->male == 1)
    {
      strcpy(person->obj->gender , "Mr.");
    }
    if(person->obj->female == 1 )
    {
      strcpy(person->obj->gender , "Ms.");
    }
    else
    {
      strcpy(person->obj->gender , "Nil");
    }
  }

  void generate()
  {
    string str = "1100123",temp;
    temp = person->obj->cnic;
    int j = 0;
    for(int i = temp.length()-1; j<4;i--)
    {
      str+=temp[i];
      j++;
    }
    strcpy (person->obj->accNo , str.c_str());
  }


  bool checkData()
  {

    if(
      (checklist('f')==true)
      && (checklist('l')==true)
      && (checklist('F')==true)
      && (checklist('c')==true)
      && (checklist('p')==true)
      && (checklist('a')==true)
      && (checklist('b')==true)
      )

    {
      generate();
      gendr();
      return true;
    }
    return false;
  }
};




int main()
{
  teto c;
  Info1 temp2;
  c.fun(&temp2);
  win = new Fl_Window(l,w,"ATM");

  page = new Fl_Wizard(0,0,l,w);
  {
    c.createAccount();
    win->end();
    page->end();
    win->resizable(win);
    win->show();
    Fl::run();
  }



  win->begin();
  // c.fun(&temp2);s
page = new Fl_Wizard(0,0,l,w);
{
  if(c.checkData() == true)
  {
    c.setPIN();
  }
  else
  {
    c.createAccount();
  }
  page->end();
  win->end();
  win->resizable(win);
  win->show();
  Fl::run();
}
   win->begin();
   page = new Fl_Wizard(0,0,l,w);
   {
      if(temp2.pin != temp2.pin2 )
        {
          c.setPIN();
        }
        page->end();
        win->end();
        win->resizable(win);
        win->show();
        Fl::run();
  }

  c.storeData(temp2);






  return 0;
}
