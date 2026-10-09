#include <iostream>
using namespace std;

class Tovar{
	private:
	char name[30];
	double price;
	public:
	Tovar(){
		name[0] = '\0';
		price = 0;
		}
	Tovar(char n[], double p) : price(p) {
		int i = 0;
		while (n[i] != '\0' && i < 29) {
            name[i] = n[i];
            i++;}
			name[i] = '\0';
		}
	
	friend ostream& operator <<(ostream& out, Tovar& t){
		out<<"Name: "<<t.name<<endl;
		out<<"Price: "<<t.price<<"$"<<endl;
		return out;
		}
	friend istream& operator>>(istream& in, Tovar& t){
		cout<<"Enter name: ";
		in>>t.name;
		in>>t.price;
		return in;
		
		}	
	
	};
	
int main(){
	Tovar a((char*)"Fanta", 1.5);
	Tovar b;
	
	cin>>b;
	cout<<a;
	cout<<b;
	
	
	
	
	}
