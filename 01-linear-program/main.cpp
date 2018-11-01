#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double a;
	cout << "vvedi a\na = ";
	cin >> a;

	double z1 = (sin(2 * a) + sin(5 * a) - sin(3 * a)) /
		(cos(a) - cos(3 * a) + cos(5 * a));
	double z2 = tan(3 * a);
	cout << "z1 = " << z1 << "\nz2 = " << z2;

	return 0;
}