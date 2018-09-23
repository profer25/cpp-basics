#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	double a, z1, z2;
	cin >> a;
	z1 = 2 * pow(double(sin(3 * M_PI + 2 * a)), 2) * pow(double(cos(5 * M_PI + 2 * a)), 2);
	z2 = 0.25 - 0.25*sin(2.5 * M_PI + 8 * a);
	cout << z1 << endl << z2;
	return 0;
}
