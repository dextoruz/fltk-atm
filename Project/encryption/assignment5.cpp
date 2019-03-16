#include <iostream>
#include <stdlib.h>
#include <algorithm>

#define size 10
using namespace std;

class fraction
{
private:
	long p,q;
	char c;
public:
	friend istream& operator>>(istream& s, fraction& f)
	{
		cout<<"Enter fraction: ";
		s>>f.p>>f.c>>f.q;
		if(f.q == 0)
		{
			cout<<"Zero division error.\n";
			_Exit(EXIT_FAILURE);
		}
		return s;
	}
	friend ostream& operator<<(ostream& ss, fraction& f)
	{

		if(f.q == 1 || f.p == 0)
		{
			ss<<f.p;
		}
		else
		{
			ss<<f.p<<"/"<<f.q;
		}
		return ss;
	}
	void simplify()
	{
		int sign = 0;
		if(p<0 && q<0)
		{
			p*=-1;
			q*=-1;
		}
		if(q<0)
		{
			p*=-1;
			q*=-1;
		}
		if(p<0)
		{
			p*=-1;
			sign++;
		}
		for(long long x = p*q; x>1; x--)
		{
			if(p%x == 0 && q%x ==0)
			{
				p/=x;
				q/=x;
			}
			if(sign == 1)
			{
				p*=-1;
				sign = 0;
			}
		}
		return;
	}
	bool operator==( fraction f)
	{
		cout<<p<<c<<q<<" == "<<f.p<<f.c<<f.q<<" is ";
		fraction f1;
		f1.p = p;
		f1.q = q;
		f1.c = c;
		f1.simplify();
		f.simplify();
		if(f1.p == f.p && f1.q == f.q)
		{
			cout<<"true"<<endl;
			return true;
		}
		cout<<"false"<<endl;
		return false;
	}
	bool operator!=( fraction f)
	{
		cout<<p<<c<<q<<" != "<<f.p<<f.c<<f.q<<" is ";
		fraction f1;
		f1.p = p;
		f1.q = q;
		f1.c = c;
		f1.simplify();
		f.simplify();
		if(f1.p == f.p && f1.q == f.q)
		{
			cout<<"false"<<endl;
			return false;
		}
		cout<<"true"<<endl;
		return true;
	}
	bool operator>( fraction f)
	{
		cout<<p<<c<<q<<" > "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		long x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x > y)
		{
			cout<<"true"<<endl;
			return true;
		}
		cout<<"false"<<endl;
		return false;
	}
	bool operator<( fraction f)
	{
		cout<<p<<c<<q<<" < "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		long x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x < y)
		{
			cout<<"true"<<endl;
			return true;
		}
		cout<<"false"<<endl;
		return false;
	}

	bool operator>=( fraction f)
	{
		cout<<p<<c<<q<<" >= "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		long x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x >= y)
		{
			cout<<"true"<<endl;
			return true;
		}
		cout<<"false"<<endl;
		return false;
	}

	bool operator<=(fraction f)
	{
		cout<<p<<c<<q<<" <= "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		long x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x <= y)
		{
			cout<<"true"<<endl;
			return true;
		}
		cout<<"false"<<endl;
		return false;
	}
	fraction operator++(int)
	{
		fraction f;
		f.p = p + q;
		f.q = q;
		f.c = c;
		return f;
	}
	fraction operator++()
	{
		fraction f;
		f.p = p;
		f.q = q;
		f.c = c;
		p+=q;
		return f;
	}
	fraction operator--(int)
	{
		fraction f;
		f.p = p - q;
		f.q = q;
		f.c = c;
		return f;
	}
	fraction operator--()
	{
		fraction f;
		f.p = p;
		f.q = q;
		f.c = c;
		p-=q;
		return f;
	}
	fraction operator +(fraction f)
	{
		cout<<p<<c<<q<<" + "<<f.p<<c<<f.q<<" = ";
		fraction f1;
		f1.p = (p * f.q)+(q * f.p);
		f1.q = q * f.q;
		f1.c = c;
		f1.simplify();
		return f1;
	}
	fraction operator +(int value)const
	{
		cout<<p<<c<<q<<" + "<<value<<" = ";
		fraction f1;
		f1.p = p +(q * value);
		f1.q = q;
		f1.c = c;
		f1.simplify();
		return f1;
	}
	friend fraction operator +(int value, fraction &f)
	{
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		cout<<value<<" + "<<f.p<<f.c<<f.q<<" = ";
		f0.p = f0.p +(f0.q * value);
		f0.simplify();
		return f0;
	}
	fraction operator -( fraction f)const
	{
		cout<<p<<c<<q<<" - "<<f.p<<c<<f.q<<" = ";
		fraction f0;
		f0.p = (p * f.q)-(q * f.p);
		f0.q = q * f.q;
		f0.c = c;
		f0.simplify();
		return f0;
	}
	fraction operator -(int value)const
	{
		cout<<p<<c<<q<<" - "<<value<<" = ";
		fraction f1;
		f1.p = p -(q * value);
		f1.q = q;
		f1.c = c;
		f1.simplify();
		return f1;

	}
	friend fraction operator -(int value, fraction &f)
	{
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		cout<<value<<" - "<<f.p<<f.c<<f.q<<" = ";
		f0.p = f0.p -(f0.q * value);
		f0.simplify();
		return f0;
	}
	fraction operator -()
	{
		fraction temp;
		temp.p = p;
		temp.q = q;
		if(temp.p<0 && temp.q<0)
		{
			temp.q*=-1;
		}
		else if(temp.p>0 && temp.q>0)
		{
			temp.p*=-1;
		}
		else if(temp.p<0 && temp.q>0)
		{
			temp.p*=-1;
		}
		else if(temp.p>0 && temp.q<0)
		{
			temp.q*=-1;
		}
		return temp;
	}
	fraction operator *(fraction f)
	{
		cout<<p<<c<<q<<" * "<<f.p<<c<<f.q<<" = ";
		fraction f0;
		f0.p = p * f.p;
		f0.q = q * f.q;
		f0.c = c;
		f0.simplify();
		return f0;

	}
	fraction operator *(int value)
	{
		cout<<p<<c<<q<<" * "<<value<<" = ";
		fraction f0;
		f0.p = p * value;
		f0.q = q;
		f0.c = c;
		f0.simplify();
		return f0;
	}

	friend fraction operator *(int value, fraction &f)
	{
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		cout<<value<<" * "<<f.p<<f.c<<f.q<<" = ";
		f0.p *= value;
		f0.simplify();
		return f0;
	}
	fraction operator /(fraction f)
	{
		cout<<p<<c<<q<<" / "<<f.p<<c<<f.q<<" = ";
		fraction f0;
		f0.p = p * f.q;
		f0.q = q * f.p;
		f0.c = c;
		if(f0.q == 0)
		{
			cout<<"Zero division error.\n";
			_Exit(EXIT_FAILURE);
		}
		f0.simplify();
		return f0;
	}
	fraction operator /(int value)
	{
		cout<<p<<c<<q<<" / "<<value<<" = ";
		fraction f1;
		f1.p = p;
		f1.c = c;
		f1.q = q * value;
		if(f1.q == 0)
		{
			cout<<"Zero division error.\n";
			_Exit(EXIT_FAILURE);
		}
		f1.simplify();
		return f1;
	}
	friend fraction operator /(int value, fraction &f)
	{
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		int x;
		cout<<value<<" / "<<f.p<<f.c<<f.q<<" = ";
		x = f0.p;
		f0.p = f0.q * value;
		f0.q = x;
		f0.simplify();
		return f0;
	}
	void operator+=(fraction f)
	{
		cout<<p<<c<<q<<" + "<<f.p<<f.c<<f.q<<" = ";
		p = (p * f.q)+(q * f.p);
		q *= f.q;
		simplify();
		return;
	}
	void operator+=(int value)
	{
		cout<<p<<c<<q<<" + "<<value<<" = ";
		p += (q * value);
		q *= q;
		simplify();
		return;
	}
	void operator-=(fraction f)
	{
		cout<<p<<c<<q<<" - "<<f.p<<f.c<<f.q<<" = ";
		p = (p * f.q)-(q * f.p);
		q = q * f.q;
		simplify();
		return;
	}
	void operator-=(int value)
	{
		cout<<p<<c<<q<<" - "<<value<<" = ";
		p -= (q * value);
		simplify();
		return;
	}
	void operator*=(fraction f)
	{
		cout<<p<<c<<q<<" * "<<f.p<<f.c<<f.q<<" = ";
		p *= f.p;
		q *= f.q;
		simplify();
		return;
	}
	void operator*=(int value)
	{
		cout<<p<<c<<q<<" * "<<value<<" = ";
		p *= value;
		simplify();
		return;
	}
	void operator/=(fraction f)
	{
		cout<<p<<c<<q<<" / "<<f.p<<f.c<<f.q<<" = ";
		p *= f.q;
		q *= f.p;
		simplify();
		return;
	}
	void operator/=(int value)
	{
		cout<<p<<c<<q<<" / "<<value<<" = ";
		q *= value;
		simplify();
		return;
	}
	 fraction()
	 {}
	~fraction()
	{}

};

class safeArray
{
private:
	fraction array[size];
public:
	fraction& operator[](int x)
	{
		if(x<0 || x>=size)
		{
			cout<<"\n...Out of bound index...\n";
			_Exit(EXIT_FAILURE);
		}
		return array[x];
	}
	void inputValues()
	{
		for(int i = 0; i<size; i++)
		{
			cout<<"array["<<i<<"] = ";
			cin>>array[i];
		}
	}
	void printArray()
	{
		cout<<"[ ";
		for(int i = 0; i<size-1; i++)
		{
			cout<<array[i]<<" , ";
		}

		cout<<array[size-1]<<" ]"<<endl;
	}
	void sortArray()
	{
		for(int i = 0; i<size-1; i++)
		{
			if(array[i]>array[i+1])
			{
				swap(array[i],array[i+1]);
			}
		}
		cout<<"Sorted array.\n";
		printArray();
	}
	safeArray()
	{}
	~safeArray()
	{}
};

int main()
{
	fraction f,g,h;
	safeArray arr;
	// cin>>f;
	// cin>>g;
	// h = f+2;
	// cout<<h<<endl;
	// h = f-2;
	// cout<<h<<endl;
	// h = f*2;
	// cout<<h<<endl;
	// h = f/2;
	// cout<<h<<endl;
	// h = 2+f;
	// cout<<h<<endl;
	// h = 2-f;
	// cout<<h<<endl;
	// h = 2*f;
	// cout<<h<<endl;
	// h = 2/f;
	// cout<<h<<endl;
	// h = f + g;
	// cout<<h<<endl;
	// h = f - g;
	// cout<<h<<endl;
	// h = f * g;
	// cout<<h<<endl;
	// h = f / g;
	// cout<<h<<endl;
	// f==g;
	// f != g;
	// f >= g;
	// f <= g;
	// f > g;
	// f < g;
	// h = f++;
	// cout<<h<<endl;
	// h = ++f;
	// cout<<h<<endl;
	// cout<<f<<endl;    ///incremented value in f
	// h = f--;
	// cout<<h<<endl;
	// h = --f;
	// cout<<h<<endl;
	// cout<<f<<endl;
	// // f += g;
	// // cout<<f<<endl;
	// // f -= g;
	// // cout<<f<<endl;
	// // f *= g;
	// // cout<<f<<endl;
	// // f /= g;
	// // cout<<f<<endl;
	// // f +=2;
	// // cout<<f<<endl;
	// // f -=2;
	// // cout<<f<<endl;
	// // f *=2;
	// // cout<<f<<endl;
	// // f /= 2;
	// // cout<<f<<endl;


/////// SAFE   ARRAY


	// arr.inputValues();
	// h = arr[0] + arr[1];
	// cout<<h<<endl;
	// h = arr[2] - arr[3];
	// cout<<h<<endl;
	// arr[4] >= arr[5];
	// h = arr[6] * arr[7];
	// cout<<h<<endl;
	// h = arr[8] / arr[9];
	// cout<<h<<endl;
	// arr.printArray();
	// cin>>arr[10];
	// cout<<arr[10];
	// arr.sortArray();
	return 0;
}
