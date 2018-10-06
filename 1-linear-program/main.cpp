#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double a, z1, z2;
	cout << "vvedi a" << endl << "a = ";
	cin >> a;
	z1 = (sin(2 * a) + sin(5 * a) - sin(3 * a)) / (cos(a) - cos(3 * a) + cos(5 * a));
	z2 = tan(3 * a);
	cout << "z1 = " << z1 << endl << "z2 = " << z2;
	return 0;
}