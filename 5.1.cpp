#include <iostream>
using namespace std;

class myclass{
	int size;
	int *a;
	public:
	myclass(int size) : size(size){
		a = new int[size];
		}
	
	void put(int i, int number){
		a[i] = number;
		}
	
	void show(){
		for(int i = 0; i<size;i++) cout<<i<<": "<<a[i]<<endl;
		}
	
	myclass(const myclass &temp_ob){
		this->size=temp_ob.size;
		
		this->a=new int [size];
		
		for(int i=0;i<this->size;i++) this->a[i]=temp_ob.a[i];
		}
	
	~myclass(){
		cout<<"do delete"<<endl;
		delete [] a;
		cout<<"posle delete"<<endl;
		}
	
	};
	
	
int main(){
	myclass ob(5);
	
	for(int i = 0;i<5;i++) ob.put(i, i);
	
	myclass ob2=ob;
	
	//for(int i = 0;i<10;i++) ob2.put(i, 10 - i);
	ob2.put(0, 100);
	ob.show();
	
	cout<<endl;
	
	ob2.show();
	
	
	
	
	
	}	
	
