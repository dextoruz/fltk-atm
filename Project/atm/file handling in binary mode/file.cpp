#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person
{
  char name[50];
  int age;
  char phone[24];
};

void writeData(string filename, Person p)
{

    // double y,z,c;
      ifstream infile;
      infile.open(filename.c_str(), ios::binary | ios::in);
      string str,deleteline = "Ali Husnain,20,p17-6071";
      // cout<<deleteline.length()<<endl;
      while(!infile.eof())
      {
          getline(infile,str);
          // if(infile)
          // {
              cout<<str.length()<<endl;
          // }
      }
      infile.close();

      ofstream outfile;
      outfile.open(filename.c_str(), ios::binary | ios::out);

      // outfile<<p.name<<p.age<<p.phone;
      outfile.close();

      // infile.seekg(2, ios::beg);
      // infile>>y>>z>>c;
      // cout<<y<<"    "<<z<<"    "<<c<<"   \n"  ;


}

int main()
{
  Person me = {"Ali Husnain,",20,",p17-6071\n"};
  // writeData("ju.bin",me);
  ofstream outfile;
  outfile.open("junk.bin", ios::binary |ios::app|ios::out);
  outfile<<me.name<<me.age<<me.phone;
  outfile.close();
  double y,z,c;
    ifstream infile;
    infile.open("junk.bin", ios::binary | ios::in);
    string str;
    while(!infile.eof())
    {
        getline(infile,str,',');
        if(infile)
        {
            cout<<str<<endl;
        }
    }
    infile.seekg(2, ios::beg);
    // infile>>y>>z>>c;
    // cout<<y<<"    "<<z<<"    "<<c<<"   \n"  ;

    infile.close();

  return 0;
//// for updated information or change pin
  // str.replace(str.find(deleteline),deleteline.length(),"");

}
