#include <iostream>
using namespace std;

class Soup{
	private:
    double soupvolume; 
    double saltweight; 
public:
    Soup(double volume, double salt) : soupvolume(volume), saltweight(salt) {}
    friend double getsaltpercent(Soup s);
};
double getsaltpercent(Soup s){
    return (s.saltweight / s.soupvolume)*100;}
int main(){
    Soup mysoup(500, 5);
    cout<<"Percent "<< getsaltpercent(mysoup)<<"%"<< endl;
}
