#include <iostream>

using namespace std;

int main() {
	double a, b, c, xn, xk, dx;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	cout << "xn = ";
	cin >> xn;
	cout << "(xk >= xn) xk = ";
	cin >> xk;
	cout << "(dx > 0) dx = ";
	cin >> dx;

	if (dx <= 0)
	{
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else
		if (xk < xn) {
			cout << "\nInvalid xk. Must be: xk >= xn.\n";
		}
		else {
			cout << "-------------------------------------" << endl;
			cout << "|        x        |        F        |" << endl;
			cout << "-------------------------------------" << endl;

			for (double x = xn; x <= xk; x += dx) {
				double f;
				bool division_by_zero = false;
				if (x && c < 0)
					f = -a * x - c;
				else
					if (!x && c > 0)
						f = (x - a) / -c;
					else
						if (c - a)
							f = b * x / (c - a);
						else
							division_by_zero = true;

				printf("|%11.3f      |", x);
				if (division_by_zero) {
					cout << "  division by 0  |\n";
				}
				else {
					int ac = static_cast<int>(a);
					int bc = static_cast<int>(b);
					int cc = static_cast<int>(c);
					if (ac | bc | cc)
						printf("%12.3f     |\n", f);
					else
						printf("%10d       |\n", static_cast<int>(f));
				}
			}
			cout << "-------------------------------------";
		}

	return 0;
}