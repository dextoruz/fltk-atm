#include <iostream>
#include <string>
#include <fstream>
#include "LOGIN.h"
// #include "groupClass.h"
#include "CREATE.h"


using namespace std;

class ATM: public login, public Acount
{
private:
  int pow(int num1 , int num2)
  	{
  		int p = 1;
  		for(int i = 0; i<num2; i++)
  		{
  			p *= num1;

  		}
  		return p;
  }
  long string_to_int(string str)
  {

    int n = 0;
    long no = 0;
    for(int i = str.length()-1; 0<=i; i--)
    {
      if(str[i] >= '0' && str[i] <= '9')
      {
        no += pow(10,n) *(int(str[i])-48);
        n++;
      }
    }
    return no;
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
  static void b1_cb(Fl_Widget *, void * b)
  {
    long* per = reinterpret_cast<long*>(b);
    if(*per >= 500)
    {
      *per -= 500;
    }
    else
    {
      printf("%s\n", "Not enough balance");
    }
    win->hide();
  }
  static void b2_cb(Fl_Widget *, void * b)
  {
    long* per = reinterpret_cast<long*>(b);
    if(*per >= 1000)
    {
      *per -= 1000;
    }
    else
    {
      printf("%s\n", "Not enough balance");
    }
    win->hide();
  }
  static void b3_cb(Fl_Widget *, void * b)
  {
    long* per = reinterpret_cast<long*>(b);
    if(*per >= 5000)
    {
      *per -= 5000;
    }
    else
    {
      printf("%s\n", "Not enough balance");
    }
    win->hide();
  }
  static void b4_cb(Fl_Widget *, void * b)
  {
    page->next();
    // win->hide();
  }

  static void b5_cb(Fl_Widget *, void * b)
  {
    long* per = reinterpret_cast<long*>(b);
    if(*per >= 20000)
    {
      *per -= 20000;
    }
    else
    {
      printf("%s\n", "Not enough balance");
    }
    win->hide();
  }
  static void b6_cb(Fl_Widget *, void * b)
  {
    long* per = reinterpret_cast<long*>(b);
    if(*per >= 10000)
    {
      *per -= 10000;
    }
    else
    {
      printf("%s\n", "Not enough balance");
    }
    win->hide();
  }
public:
  long bln = 0;
  long *blnce = &bln;
  void chooseAmount()
  {
      Fl_Group *g = new Fl_Group(0,0,l,w,"Instruction");

      Fl_Box * bx = new Fl_Box(180,30,200,60,"Choose Amount");bx->labelsize(24);bx->labelfont(FL_BOLD+FL_ITALIC);
      Fl_Button *b1 = new Fl_Button(80,120,120,40,"500");b1->labelsize(16);b1->labelfont(FL_BOLD);
      Fl_Button *b2 = new Fl_Button(80,180,120,40,"1000");b2->labelsize(16);b2->labelfont(FL_BOLD);
      Fl_Button *b3 = new Fl_Button(80,240,120,40,"5000");b3->labelsize(16);b3->labelfont(FL_BOLD);
      Fl_Button *b4 = new Fl_Button(380,240,120,40,"Other");
      b4->callback(next_cb);
      b4->labelsize(16);b4->labelfont(FL_BOLD);
      Fl_Button *b5 = new Fl_Button(380,180,120,40,"20000");b5->labelsize(16);b5->labelfont(FL_BOLD);
      Fl_Button *b6 = new Fl_Button(380,120,120,40,"10000");b6->labelsize(16);b6->labelfont(FL_BOLD);

      b1->callback(b1_cb,blnce);
      b2->callback(b2_cb,blnce);
      b3->callback(b3_cb,blnce);
      b4->callback(b4_cb,blnce);
      b5->callback(b5_cb,blnce);
      b6->callback(b6_cb,blnce);
      // Fl_Button *next = new Fl_Button(440,365,100,25,"Next"); next->callback(next_cb);
      // Fl_Button *back = new Fl_Button(330,365,100,25,"Back"); back->callback(back_cb);

      // b4->callback(next_cb);

    g->labelsize(14);
    g->end();
  }
  void updateAmount(string us)
  {
    // int i = 0;
    string temp,str[4];
    // cout<<temp<<endl;
    ifstream in("Data/"+us+".csv");
    if(in.is_open())
    {
      for(int i = 0; i<4; i++)
      {
      getline(in, temp,',');
      string s(temp);
      str[i] = s;
      // cout<<str[i]<<endl;
      }
    }

  else
  {
    cout<<"File not found!\n";
  }
  in.close();

  ofstream out("Data/"+us+".csv");
  out<<str[0]<<','<<str[1]<<','<<bln<<','<<str[3]<<','<<'\n';
  out.close();


}
  void storeData(Info1 temp2)
  {
    string str(temp2.accNo);
    ofstream out1("Data/"+str + ".csv");
    out1<<temp2.accNo<<','<<temp2.fname<<' '<<temp2.lname<<','<<temp2.balance<<
    ','<<temp2.pin<<','<<'\n';
    out1.close();
    ofstream out("Data/usersData.csv",ios::app);
    out<<temp2.accNo<<','<<temp2.fname<<' '<<temp2.lname<<','
    <<temp2.father<<','<<temp2.cnic<<','<<temp2.phone<<','
    <<temp2.age<<','<<temp2.balance<<','<<'\n';
    out.close();


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
  bool verification(string u, string p)
  {
    string temp,u2="",p2="";
    temp = "Data/"+u + ".csv";

    ifstream in(temp);
    int i = 0;
    temp = "";
    if(in.is_open())
    {
      while(!(in.eof()))
      {
        getline(in,temp,',');
        string s(temp);
        if (i == 2)
        {
          bln = string_to_int(s);
          // cout<<bln<<endl;
        }
        if(i == 0)
        {
          u2  = s;
        }
        if(i == 3)
        {
          p2 = s;
          // cout<<u2<<endl;
        }
        i++;
      }
    }
    else
    {
      printf("%s\n", "user not found!" );
      return false;
    }
    in.close();

    if(u2 == u)
    {
      if(p2 == p)
      {
        return true;
      }
      else
      {
          return false;
      }
    }
    else
    {
      return false;
    }
  }


};



int main()
{

  ATM a;
  Info1 temp2;
  a.fun(&temp2);

  //
  // page = new Fl_Wizard(0,0,l,w);
  // {
  //   a.firtPage();
  // }
  // win->end();
  // page->end();
  // win->resizable(win);
  // win->show();
  // Fl::run();
  // if (a.c1->x == 1)
  // {
    // cout<<"login\n";
      //////////////////////////////////////////////////////

      ////////////login?/////////////////
      // win->begin();
      win = new Fl_Window(l,w,"ATM");
        page = new Fl_Wizard(0,0,l,w,"");
        {
          a.LOGIN();
        }
        page->end();
        win->end();
        win->resizable(win);
        win->show();
        Fl::run();

        string usr = a.user->value();
        string pas = a.pass->value();

        if(a.verification(usr,pas) == true)
        {
          win->begin();
          page = new Fl_Wizard(0,0,l,w,"");
          {
            a.chooseAmount();
            a.Thank();
            page->end();
            win->end();
            win->resizable(win);
            win->show();
            Fl::run();
          }
          // printf("%s\n", "1LOGED IN ");
        }
        else
        {
          win->begin();
          page = new Fl_Wizard(0,0,l,w,"");
          {
            a.loginWarn();
          }


          page->end();
          win->end();
          win->resizable(win);
          win->show();
          Fl::run();

        }
        // cout<<a.bln<<endl;
        a.updateAmount(usr);


  // if(a.c2->x == 1)
  // {
  //   cout<<"create\n";
    // //////////////////////////////////////////////////////
    //
    // win = new Fl_Window(l,w,"ATM" );
    // /////////////////// CREATe A account /////////////////
    //   page = new Fl_Wizard(0,0,l,w);
    //   {
    //     a.createAccount();
    //     win->end();
    //     page->end();
    //     win->resizable(win);
    //     win->show();
    //     Fl::run();
    //   }
    //   win->begin();
    //   // c.fun(&temp2);s
    // page = new Fl_Wizard(0,0,l,w);
    // {
    //   if(a.checkData() == true)
    //   {
    //     a.setPIN();
    //   }
    //   else
    //   {
    //     a.createAccount();
    //   }
    //   page->end();
    //   win->end();
    //   win->resizable(win);
    //   win->show();
    //   Fl::run();
    // }
    //    win->begin();
    //    page = new Fl_Wizard(0,0,l,w);
    //    {
    //       if(temp2.pin != temp2.pin2 )
    //         {
    //           a.setPIN();
    //         }
    //         page->end();
    //         win->end();
    //         win->resizable(win);
    //         win->show();
    //         Fl::run();
    //   }
    //
    //   a.storeData(temp2);
    //
    // }
  // }

  return 0;
}
