#include <iostream>
using namespace std;

class Soup{
private:
    double soupvolume; 
    double saltweight; 
public:
    Soup(double volume, double salt) : soupvolume(volume), saltweight(salt) {}
    friend class raschet; 
};
class Salad{
private:
    double saladvolume; 
    double saltweight; 
public:
    Salad(double volume, double salt) : saladvolume(volume), saltweight(salt) {}
    friend class raschet;
};
class raschet{
public:
    double getsaltpercent(Soup s){
      return (s.saltweight / s.soupvolume)*100;}
    double getsaltpercent(Salad sal){
      return (sal.saltweight / sal.saladvolume)*100;}
};
int main(){
    Soup mysoup(500, 5);
    Salad mysalad(200, 2);
    raschet Raschet;
    cout<<"Percent in soup "<<Raschet.getsaltpercent(mysoup)<<"%"<<endl;
    cout<<"Percent in salad " <<Raschet.getsaltpercent(mysalad)<<"%"<<endl;
}
