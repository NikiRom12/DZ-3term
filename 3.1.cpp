#include <iostream>
using namespace std;
//перегрузка по типу параметров при одинаковом количестве параметров;

void func(int a, int b){
	cout<<a*b<<" V int"<<endl;	
	}
void func(double a, double b){
	cout<<a*b<<" V double"<<endl;	
	}
	
//перегрузка по количеству параметров;
void func1(int a, int b, int c, int d, int e){
	cout<<(a*b/c+d)*e<<" 5 parametrov"<<endl;
	}
void func1(int a, int b){
	cout<<a*b+a<<" 2 parametra"<<endl;
	}
//использование параметров по умолчанию в функции.
void func2(int kolvoseriy, int kolvosezonov = 3, int dlitelnost = 45){
	cout<<"Seriy "<<kolvoseriy<<", Sezonov "<<kolvosezonov<<", Dliteltost serii "<<dlitelnost<<endl;
	}


int main(){
	func(1, 23);
	func(1.5, 2.32);
	func1(1, 5, 17, 199, 87);
	func1(72, 91);
	func2(10);
	func2(15, 1);
	func2(30, 3, 22);
	
	}
