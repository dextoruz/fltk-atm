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

// Fl_Window *win = 0;
// Fl_Wizard *page = 0;



struct Info1{
  char fname[10],lname[10],father[20],gender[4],
  cnic[14],phone[11],balance[12],accNo[11];
  unsigned short int  age,pin,pin2,male,female,other;
};

struct Info
{
  Fl_Group *group;
  Fl_Box *boxx;
  Fl_Input *Fname;
  Fl_Input *Lname;
  Fl_Input *Father;
  Fl_Input *Cnic;
  Fl_Input *Phone;
  Fl_Int_Input*Age;
  Fl_Input*Balance;
  Fl_Int_Input*Pin;
  Fl_Int_Input*Pin2;
  Fl_Radio_Round_Button *m;
  Fl_Radio_Round_Button *f;
  Fl_Radio_Round_Button *o;

  Info1 *obj;
};

class Acount
{
protected:

  Info *person;
  Fl_Box *box2 = 0;
  bool checklist( char x)
  {
    switch (x)
    {
      case('f'):
      {
        for(int i = 0; person->obj->fname[i] != '\0'; i++)
        {
          if(!((person->obj->fname[i] >= 'a' && person->obj->fname[i]<= 'z')
            ||(person->obj->fname[i] >= 'A' &&  person->obj->fname[i]<= 'Z'))
            ||( person->obj->fname[i] == ' '))
          {
            return false;
          }
        }
        return true;
      }
      case('l'):
      {
        for(int i = 0; person->obj->lname[i] != '\0'; i++)
        {
          if(!((person->obj->lname[i] >= 'a' && person->obj->lname[i]<= 'z')
            ||(person->obj->lname[i] >= 'A' && person->obj->lname[i]<= 'Z')
            ||(person->obj->lname[i] == ' ')))
          {
            return false;
          }
        }
        return true;
      }
      case('F'):
      {
        for(int i = 0; person->obj->father[i] != '\0'; i++)
        {
          if(!((person->obj->father[i] >= 'a' && person->obj->father[i]<= 'z')
            ||(person->obj->father[i] >= 'A' && person->obj->father[i]<= 'Z')
            ||(person->obj->father[i] == ' ')))
          {
            printf("%s\n", person->obj->father );
            return false;
          }
        }
        return true;
      }
      case('c'):
      {
        for(int i = 0; i<13; i++)
        {
          if(!((person->obj->cnic[i] >= '0' && person->obj->cnic[i]<= '9')))
          {
            return false;
          }
        }
        return true;
      }
      case('p'):
      {
        for(int i = 0; i<11; i++)
        {
          if(!((person->obj->phone[i] >= '0' && person->obj->phone[i]<= '9')))
          {
            return false;
          }
        }
        return true;
      }
      case('b'):
      {
        for(int i = 0; person->obj->balance[i] != '\0'; i++)
        {
          if(!((person->obj->balance[i] >= '0' && person->obj->balance[i]<= '9')))
          {
            return false;
          }
        }
        return true;
      }
      case ('a') :
      {
        if( person->obj->age >= 18 && person->obj->age <=99  )
        {
          return true;
        }
        return false;

      }


    }
  }
  // Fl_Box *box = 0;
  // Fl_Box *bx2;
public:

  static void pin_cb(Fl_Widget*, void *param)
  {
    Info* per = reinterpret_cast<Info*>(param);

    per->obj->pin = atoi(per->Pin->value());
    per->obj->pin2 = atoi(per->Pin2->value());

    win->hide();
  }
  static void done_cb(Fl_Widget* , void* param)
  {
      Info* per = reinterpret_cast<Info*>(param);
      strcpy (per->obj->fname, per->Fname->value());
      strcpy (per->obj->lname, per->Lname->value());
      strcpy (per->obj->father, per->Father->value());
      strcpy (per->obj->cnic ,per->Cnic->value());
      strcpy (per->obj->phone , per->Phone->value());
      strcpy (per->obj->balance ,per->Balance->value());
      per->obj->other = per->o->value();
      per->obj->male = per->m->value();
      per->obj->female = per->f->value();

      per->obj->age = atoi(per->Age->value());

      // page->next();
      win->hide();
  }

  // void text(const char *val) {
  //   box->copy_label(val);
  // }
  // void invalid(const char *val)
  // {
  //   bx2->copy_label(val);
  // }
  void setPIN()
  {

      person->group= new Fl_Group(0,0,l,w);
        box2 = new Fl_Box(230,50,100,40,person->obj->accNo);box2->labelsize(24);

        // box = new Fl_Box(310,50,100,40,"");box->labelsize(22);box->labelfont(FL_BOLD);
        box2->labelcolor(fl_rgb_color(162, 40, 10));
      person->boxx = new Fl_Box(230,120,100,60,"Enter Your PIN");person->boxx->labelsize(22);
      person->boxx->labelfont(FL_BOLD+FL_ITALIC);

      person->Pin = new Fl_Int_Input(200,180,160,30,"PIN ");
      person->Pin2 = new Fl_Int_Input(200,220,160,30,"Re-type ");
      Fl_Button *b5 = new Fl_Button(220,260,120,25,"Submit");
      b5->labelsize(14);b5->labelfont(FL_BOLD);b5->callback(pin_cb,person);

      person->group->labelsize(14);
      person->group->end();

  }

  void createAccount()
  {
    person->group = new Fl_Group(0,0,l,w,"acc");
    {
    person->boxx = new Fl_Box(180,30,200,60,"Create an account");
    // bx2 = new Fl_Box(370,150,100,50,"");
    // bx2->labelsize(20);bx2->labelfont(FL_BOLD+FL_ITALIC);
    // bx2->labelcolor(fl_rgb_color(162, 40, 10));
    person->Fname = new Fl_Input(110,100,130,25,"First Name ");
    person->Lname = new Fl_Input(370,100,130,25,"Last Name ");
    person->Father = new Fl_Input(110,140,180,25,"Father Name ");
    person->Cnic = new Fl_Input(110,180,180,25,"CNIC ");
    person->Phone = new Fl_Input(110,220,180,25,"Phone ");
    person->Age = new Fl_Int_Input(110,260,80,25,"Age ");
    person->m = new Fl_Radio_Round_Button(320,250,80,25,"Male");
    person->f = new Fl_Radio_Round_Button(320,270,80,25,"Female");
    person->o = new Fl_Radio_Round_Button(320,290,80,25,"Other");
    person->Balance = new Fl_Input(110,300,180,25,"Balance ");
    person->boxx->labelsize(24);person->boxx->labelfont(FL_BOLD+FL_ITALIC);


    Fl_Button *next = new Fl_Button(250,340,100,35,"Next");
    next->callback(done_cb,person);
    next->labelfont(FL_BOLD);
    // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);
    }
    person->group->labelsize(14);
    person->group->end();

    // return info;
  }

  void fun(Info1 *p)
  {
    person -> obj = p;
    return;
  }



};
