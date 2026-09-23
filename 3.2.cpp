#include <iostream>
using namespace std;

class date{
	public:
		date(){cout<<"23rd ";}
};
class month{
	public:
		month(){cout<<"September of ";}
};
class year{
	date date;
	month month;
	public:
		year(){cout<<"2026";}
};

int main(){
	year ob1;
	
	}
