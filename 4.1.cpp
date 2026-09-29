#include <iostream>
using namespace std;

class Class{
	private:
	double a;
	double b;
	public:
		Class(double x, double y) : a(x), b(y) {}
	void show(){
		cout<<"a = "<<a<<", b = "<<b<<endl;}
};


int main(){
	Class ob1(4, 7);
	ob1.show();
	
	}
