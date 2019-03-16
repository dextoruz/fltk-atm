#include <iostream>
#include <cstring>
#include <fstream>
//#include  "login.cpp"

using namespace std;

struct info
{
	string fname, lname, father, cnic, phone , age,gender,balance;
	int pin;

};

class createAccount
{
	private:
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
					break;
				}
				case ('l') :{
					if(person.lname.length() <= 12) ////// pin
	 				{
						return true;
					}
					return false;
					break;

				}
				case ('F') :{
					if(person.father.length() <= 20)
	 				{
						return true;
					}
					return false;
			

				}
				case ('c') :{
					if(person.cnic.length() == 13)
	 				{
						return true;
					}
					return false;
					break;

				}
				case ('p') :{
					if(person.phone.length() == 11)
	 				{
						return true;
					}
					return false;
					break;
				}
			}
		}
	public:
		string generate()
		{
			string str = "1100123",temp;
			temp = person.cnic;
			int j = 0;
			for(int i = temp.length()-1; j<4;i--)
			{
				str+=temp[i];
				j++;
			}
			return str;
		}
		bool checkstr( char x)
		{
			switch (x)
			{
				case('f'):
				{
					if(checkLength(x) == true)
					{
						for(int i = 0; i<person.fname.length(); i++)
						{
							if(!((person.fname[i] >= 'a' && person.fname[i]<= 'z')||(person.fname[i] >= 'A' && person.fname[i]<= 'Z'))||(person.fname[i] == ' '))
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
						for(int i = 0; i<person.lname.length(); i++)
						{
							if(!((person.lname[i] >= 'a' && person.lname[i]<= 'z')||(person.lname[i] >= 'A' && person.lname[i]<= 'Z'))||(person.lname[i] == ' '))
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
					if(checkLength(x) == true)
					{
						for(int i = 0; i<person.father.length(); i++)
						{
							if(!((person.father[i] >= 'a' && person.father[i]<= 'z')||(person.father[i] >= 'A' && person.father[i]<= 'Z'))||(person.lname[i] == ' '))
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
		bool checkInt( char x)
		{
			switch (x)
			{
				case('c'):
				{
					if(checkLength(x) == true)
					{
						for(int i = 0; i<person.cnic.length(); i++)
						{
							if(!(person.cnic[i] >= '0' && person.cnic[i]<= '9'))
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
						for(int i = 0; i<person.phone.length(); i++)
						{
							if(!(person.phone[i] >= '0' && person.phone[i]<= '9'))
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
		createAccount(string str[8])
		{
			person.fname = str[0];
			person.lname = str[1];
			person.father = str[2];
			person.cnic = str[3];
			person.phone = str[4];
			person.age = str[5];
			person.gender = str[6];
			person.balance = str[7];
			for(int i = 0;i<8;i++)
			{
				cout<<str[i]<<"  ";
			}
		}




};

// int main()
// {
// 	info temp;
// 	string str, str1[8];
// 	int i =0;
//
//
// //	ofstream out("createAC.txt");
// //	out.close();
// 	ifstream in("createAC.txt");
// 	while(!in.eof())
// 	{
// 		getline(in,str,',');
// 		str1[i] = str;
// //		cout<<str1[i];
// 		i++;
// 	}
// 	i = 0;
// 	in.close();
// 	createAccount dump(str1);
//
//
// 	return 0;
// }
