#include <iostream>
using namespace std;

class nmassiv {
    int *a;
    int size;

	public:
    nmassiv(int size) : size(size) {
        try {
            a = new int[size];} 
        catch (...) {
            cout << "Pamyat ne videlilaas" << endl;
            exit(1);
      }
 }
int &put(int i) {
	if (i < 0 || i >= size) {
		cout << "vixod za granici massiva" << endl;
		exit(1);
	}
	return a[i];
}

int get(int i) {
	if (i < 0 || i >= size) {
		cout << "vixod za granici massiva" << endl;
		exit(1);}
	return a[i];
}
};

int main(void) {
    nmassiv a(10);
    a.put(2) = 1;
    a.put(16) = 9;
    cout << a.get(2) << endl;

    return 0;
}
