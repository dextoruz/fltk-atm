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
#include <stdlib.h>
#include <fstream>

using namespace std;

// #define l 760
// #define w 460
//
// // // Sets the text value
// //  void value(const char *val) {
// //    box->copy_label(val);
// //    inp->value(val);
// //  }
// //  // Gets the text value
// //  const char *value() const {
// //    return inp->value();
// //  }
// // void text(const char*s) {
// //         output->label(s);} //// box
//
//
// string st = "";
//
// struct info
// {
// 	string fname, lname, father, cnic, phone , age,gender,balance,acc ,pin,pin2;
// };
//
// struct test
// {
//   char str[40];
//   Fl_Input *inp;
// };
//
//
// Fl_Wizard *page = 0;
// Fl_Window *win = 0;
// // void next_cb(Fl_Widget* ,void*  );
//
// void next_cb(Fl_Widget* ,void* d) {
//
// // test* input = reinterpret_cast<test*>(d);
// // strncpy(input->str, input->inp->value(),10);
// // input->ival = atoi(input->inint->value());
//
//
//    page->next();
//
// }
//
//
// class temp
// {
// public:
//   test t;
//   Fl_Input *amount;
//   Fl_Box *output;
//   string str;
//
//
//    void value(const char *val) {
//      output->copy_label(val);
//
//    }
//          // const char *value() const {
//          //    return amount->value();}
//
//   void enterAmount()
//   {
//       Fl_Group *g = new Fl_Group(0,0,l,w);
//       t.inp = new Fl_Input(200,150,180,30,"Amount: "); t.inp->labelsize(24);
//       // amount->when(FL_WHEN_ENTER_KEY);
//       Fl_Button *next = new Fl_Button(240,195,100,25,"Enter"); next->callback(next_cb);
//
//
//       output = new Fl_Box(240, 230 ,100,50); output->labelsize(24);
//       // value(str.c_str());
//       g->end();
//       // Fl::run();
//       // getdata();
//       // cout<<str;
//   }
//
//
//   string getdata()
//   {
//     str = amount->value();
//     return str;
//   }
//
//
//
// };

// string ch(char c[])
// {
//   string s = "";
//   for(int i = 0; i<11; i++)
//   {
//     if(c[i] != '\0')
//     {
//       s+= c[i];
//     }
//   }
//   return s;
// }
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
void updateAmount()
{
  int i = 0;
  string str[4], temp;
  ifstream in(person->ob->accNo+".csv");
  while(!in.eof())
  {
    getline(in, temp,',');
    string s(temp);
    str[i] = s;
    i++;
  }
  in.close();
  // ofstream out(accno+".csv");
  // out<<str[0]<<','<<str[1]<<','<<bln<<','<<str[3]<<','<<'\n';
  // out.close();
}

int main()
{
  long str;
  str = string_to_int("187687");
  cout<<str<<endl;

  return 0;
}
