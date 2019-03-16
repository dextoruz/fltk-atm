#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class checklist
{
	public:
		virtual bool checkLength(char x) = 0;
		virtual bool checkInt(char x) = 0;
};

class login:public checklist
{
	private:
		string user,pin;
		bool checkLength(char x)
		{
			switch (x)
			{
				case ('u') :{
					if(user.length() == 10)    ///// Ac/No
					{
						return true;
					}
					return false;
					break;
				}
				case ('p') :{
					if(pin.length() == 4) ////// pin
	 				{
						return true;
					}
					return false;
					break;

				}
			}
		}
	public:

		bool checkInt( char x)
		{
			switch (x)
			{
				case('u'):
				{
					if(checkLength(x) == true)
					{
						for(int i = 0; i<user.length(); i++)
						{
							if(!(user[i] >= '0' && user[i]<= '9'))
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
				case('p'):
				{
					if(checkLength(x) == true)
					{
						for(int i = 0; i<pin.length(); i++)
						{
							if(!(pin[i] >= '0' && pin[i]<= '9'))
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
		login(string usr = "", string pas = "")
		{
			user = usr;
			pin = pas;
			cout<<user <<", "<<pin<<endl;
		}
		~login()
		{ }
};

int main()
{
	string s1,s2;
	ofstream out("login.txt"); out<<"1000129987"<<" "<<"1234"; out.close();
	ifstream in("login.txt");
	in>>s1>>s2;
	in.close();
	login l(s1 ,s2);
	bool x = l.checkInt('u');
	bool y = l.checkInt('p');
	cout<<x<<endl;
	cout<<y<<endl;


	return 0;
}
