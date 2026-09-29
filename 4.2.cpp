#include <iostream>
using namespace std;

class myclass{
	double *a;
	public:
	myclass(int size) {
		a = new(nothrow) double [size];
		if(!a){
			cout<<"Error"<<endl;
			exit(1);
			}
		
		}
	~myclass()
	{
		cout<<"desructor"<<endl;
		delete[] a; //vazhnost destructora
		}
	};
	
int main(){
	
	for(int i = 0; i < 1000000; i++){
		cout<<i<<": ";
		myclass ob(200000);
		}
	
	
	
	
	}
