#include <iostream>
#include <string>
#include "decryption.h"


using namespace std;

class secure: decrpytion
{
private:
	string s;
public:
	string forEncryption(string st)
	{
		s = getSTR(st);
		return s;
	}
	string forDecryption(string st)
	{
		s = getstr(st);
		s = decrpyted(s);
		return s;
	}
	secure()
	{ }
	~secure()
	{ }
};
