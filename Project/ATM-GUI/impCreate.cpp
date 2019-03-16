// #include "groupClass.h"
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
#include <FL/Fl_Secret_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include <iostream>
#include <string>
// #include "groupClass.h"
// #include "messageBox.h"
#include <fstream>

using namespace std;

#define l 600
#define w 400


Fl_Wizard *page = 0;
void back_cb(Fl_Widget*,void*) { page->prev(); }
void next_cb(Fl_Widget*,void*) { page->next(); }
void done_cb(Fl_Widget*,void*) { exit(0); }

struct info
{
	string fname, lname, father, cnic, phone , age,gender,balance,acc ,pin,pin2;
};



class createPage
{
public:
  int string_to_int(string str)
	{

		int n = 0,no = 0;
		for(int i = 0; i<str.length(); i++)
		{
			if(str[i] >= '0' && str[i] <= '9')
			{
				no += (10*n) + (int(str[i])-48);
				n++;
			}
		}
		return no;
}
  info person;
  bool checkLength(char x)
    {

      switch (x)
      {
        case ('f') :{
          if(person.fname.length() <= 12)    ///// Ac/No
          {
            return true;
          }
          return false;

        }
        case ('l') :{
          if(person.lname.length() <= 12) ////// pin
          {
            return true;
          }
          return false;


        }
        case ('F') :{
          if(person.father.length() <= 20)
          {
            return true;
          }
          return false;

        }
        case ('b') :{
          if(person.balance.length() <= 12)
          {
            return true;
          }
          return false;

        }
        case ('c') :{
          if(person.cnic.length() <= 13)
          {
            return true;
          }
          return false;

        }
        case ('p') :{
          if(person.phone.length() <= 11)
          {
            return true;
          }
          return false;

        }
        case ('x') :{
          if(person.pin.length() == 4)
          {
            return true;
          }
          return false;

        }
        case ('y') :{
          if(person.pin2.length() == 4)
          {
            return true;
          }
          return false;

        }
        case ('g') :{
          if( string_to_int(person.age)>=18&&string_to_int(person.age)<=99 )
          {
            return true;
          }
          return false;

        }
      }
    }

    bool checkstr( char x)
    {
      string temp;
      switch (x)
      {
        case('f'):
        {
          if(checkLength(x) == true)
          {
            temp = person.fname;
            for(int i = 0; i<person.fname.length(); i++)
            {
              if(!((temp[i] >= 'a' && temp[i]<= 'z')||(temp[i] >= 'A' && temp[i]<= 'Z'))||(temp[i] == ' '))
              {
                return false;
              }
            }
            return true;
          }
          else
          {
            return false;
          }

        }
        case('l'):
        {
          if(checkLength(x) == true)
          {
            temp = person.lname;
            for(int i = 0; i<person.lname.length(); i++)
            {
              if(!((temp[i] >= 'a' && temp[i]<= 'z')||(temp[i] >= 'A' && temp[i]<= 'Z'))||(temp[i] == ' '))
              {
                return false;
              }
            }
            return true;
          }
          else
          {
            return false;
          }
          break;
        }
        case('F'):
        {
          temp = person.father;
          if(checkLength(x) == true)
          {
            for(int i = 0; i<person.father.length(); i++)
            {
              if(!((temp[i] >= 'a' && temp[i]<= 'z')||(temp[i] >= 'A' && temp[i]<= 'Z'))||(temp[i] == ' '))
              {
                return false;
              }
            }
            return true;
          }
          else
          {
            return false;
          }
          break;
        }
      }
    }


  Fl_Group *g;
  Fl_Box *bx;
  Fl_Box *bx2;
  Fl_Input *name;
  Fl_Input *lname;
  Fl_Input *father;
  Fl_Int_Input *cnic;
  Fl_Int_Input *phone;
  Fl_Int_Input *Age;
  Fl_Int_Input *balance;
  Fl_Radio_Round_Button *male;
  Fl_Radio_Round_Button *female;
  Fl_Radio_Round_Button *other;
  Fl_Button *next;

  void gendr()
  {
    if(male->value() == 1)
    {
      person.gender = "Mr.";
    }
    if(female->value() == 1)
    {
      person.gender = "Ms.";
    }
    else
    {
      person.gender = "Khuwaja sra ";
    }
  }
  void createAccountWarn()
  {
    g = new Fl_Group(0,0,l,w,"Create a Account");
    bx = new Fl_Box(180,30,200,60,"Create an account");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
    // bx2 = new Fl_Box(240,100,15,15,"*");bx2->labelsize(14);bx2->labelfont(FL_BOLD+FL_ITALIC);bx2->labelcolor(fl_rgb_color(162, 40, 10));
    bx2 = new Fl_Box(370,150,100,50,"Invalid Entry");bx2->labelsize(20);bx2->labelfont(FL_BOLD+FL_ITALIC);bx2->labelcolor(fl_rgb_color(162, 40, 10));

    name = new Fl_Input(110,100,130,25,"First Name ");
    lname = new Fl_Input(370,100,130,25,"Last Name ");
    father = new Fl_Input(110,140,180,25,"Father Name ");
    cnic = new Fl_Int_Input(110,180,180,25,"CNIC ");
    phone = new Fl_Int_Input(110,220,180,25,"Phone ");
    Age = new Fl_Int_Input(110,260,80,25,"Age ");
    male = new Fl_Radio_Round_Button(320,250,80,25,"Male");
    female = new Fl_Radio_Round_Button(320,270,80,25,"Female");
    other = new Fl_Radio_Round_Button(320,290,80,25,"Other");
    balance = new Fl_Int_Input(110,300,180,25,"Balance ");

    next = new Fl_Button(440,365,100,25,"Next"); next->callback(done_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
    g->labelsize(14);
    g->end();
    // return info;
  }
  void Thank()
  {

      Fl_Group *g = new Fl_Group(0,0,l,w,"End");


      Fl_Box *bx = new Fl_Box(180,30,260,260,"THANK YOU!");bx->labelsize(30);bx->labelfont(FL_BOLD+FL_ITALIC);
      // Fl_Button *done = new Fl_Button(440,365,100,25,"Finish"); done->callback(done_cb);
      bx->labelcolor(fl_rgb_color(162, 40, 10));

      g->labelsize(14);
      g->end();

  }

  void createAccount()
  {
    g = new Fl_Group(0,0,l,w,"Create a Account");
    bx = new Fl_Box(180,30,200,60,"Create an account");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);

    name = new Fl_Input(110,100,130,25,"First Name ");name->value();
    lname = new Fl_Input(370,100,130,25,"Last Name ");lname->value();
    father = new Fl_Input(110,140,180,25,"Father Name ");father->value();
    cnic = new Fl_Int_Input(110,180,180,25,"CNIC ");cnic->value();
    phone = new Fl_Int_Input(110,220,180,25,"Phone ");phone->value();
    Age = new Fl_Int_Input(110,260,80,25,"Age ");Age->value();
    male = new Fl_Radio_Round_Button(320,250,80,25,"Male");male->value();
    female = new Fl_Radio_Round_Button(320,270,80,25,"Female");female->value();
    other = new Fl_Radio_Round_Button(320,290,80,25,"Other");other->value();
    balance = new Fl_Int_Input(110,300,180,25,"Balance ");balance->value();


    next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
    g->labelsize(14);
    g->end();

    // return info;
  }

  void setPIN()
  {
      g = new Fl_Group(0,0,l,w);
      bx = new Fl_Box(180,30,200,60,"Enter Your PIN");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);

      Fl_Int_Input *pin = new Fl_Int_Input(200,120,160,30,"PIN "); person.pin = pin->value();
      Fl_Int_Input *rpin = new Fl_Int_Input(200,160,160,30,"Re-type "); person.pin2 = rpin->value();
      Fl_Button *b5 = new Fl_Button(220,200,120,25,"Submit");b5->labelsize(14);b5->labelfont(FL_BOLD);b5->callback(next_cb);
      // Fl_Button *done = new Fl_Button(440,365,100,25,"Finish"); done->callback(done_cb);
      // bx.labelcolor(fl_rgb_color(162, 40, 10));
      checkData();

      g->labelsize(14);
      g->end();

  }

  bool verifyPIN()
  {
    if(checkLength('x') == checkLength('y'))
    {
      generate();
      return true;    ///// show account no
    }
    return false;
  }

  bool checkData()
  {
    gendr();

      if(    (checkLength('p')==true)
          && (checkLength('c')==true)
          && (checkLength('b')==true)
          && (checkstr('f')==true)
          && (checkstr('l')==true)
          && (checkstr('F')==true)     )
      {
        return true;
      }
      return false;
  }
  void generate()
  {
    string str = "1100123",temp;
    temp = person.cnic;
    int j = 0;
    for(int i = temp.length()-1; j<4;i--)
    {
      str+=temp[i];
      j++;
    }
    person.acc = str;
  }

  void getPerson()
  {
    person.fname = name->value();
    person.lname = lname->value();
    person.father = father->value();
    person.cnic = cnic->value();
    person.phone = phone->value();
    person.balance = balance->value();
    person.age = Age->value();

  }
  info getdata()
  {
    return person;
  }

};



int main()
 {
  createPage ele;
  info s;
  Fl_Window *win = new Fl_Window(l,w,"ATM");


  page = new Fl_Wizard(0,0,l,w);
  {
    ele.createAccount();
    page->end();
    win->end();
    win->resizable(win);
    win->show();
    Fl::run();
    ele.checkData();
  }
  // page = new Fl_Wizard(0,0,l,w);
  // {
    // s = ele.getdata();
    // if(ele.checkData() == true)
    // {
      // cout<<ele.person.fname<<" "<<ele.person.lname<<" "<<ele.person.father<<endl;

      // ele.setPIN();
      // page->end();
      // win->end();
      // win->resizable(win);
      // win->show();
      // Fl::run();
    //   if (ele.verifyPIN() == true )
    //   {
    //     string user = ele.person.acc + ".csv";
    //     ofstream out1("Data/"+user);
    //     out1<<ele.person.acc<<','<<ele.person.fname+' '+ele.person.lname<<','<<ele.person.balance<<
    //     ','<<ele.person.pin;
    //     out1.close();
    //     ofstream out("Data/usersData.csv");
    //     out<<ele.person.acc<<','<<ele.person.fname+' '+ele.person.lname<<','
    //     <<ele.person.father<<','<<ele.person.cnic<<','<<ele.person.phone<<','
    //     <<ele.person.age<<','<<ele.person.balance;
    //     out.close();
    //     ele.Thank();
    //   }
    //   else
    //   {
    //     page->end();
    //     win->end();
    //     win->resizable(win);
    //     win->show();
    //     Fl::run();
    //     ele.setPIN();
    //   }
    //
    // }
    // else
    //
    // {
    //   page->end();
    //   win->end();
    //   win->resizable(win);
    //   win->show();
    //   Fl::run();
    //   ele.createAccountWarn();
    // }
    // cout<<s.fname<<endl;
  // }



  // page->end();





  return 0;
}
