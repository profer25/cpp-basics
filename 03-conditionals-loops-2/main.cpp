#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	const int kMaxIters = 1000000;
	const double kEps = 1e-15;
	cout << "eps = " << kEps << endl;

	cout << string(69, '-') << endl;
	printf("|%7s      |%15s     |%18s |%11s |\n",
		"x", "ln(x + 1)", "ln(x + 1) (cmath)", "iterations");
	cout << string(69, '-') << endl;

	for (double x = -0.9; x <= 0.9; x += 0.1) {
		int n;
		double func = 0, nth_term = 1;
		for (n = 0; abs(nth_term) > kEps && n < kMaxIters; n++) {
			nth_term = pow(-1, n) * pow(x, n + 1) / (n + 1);
			func += nth_term;
		}

		printf("|%9.3f    |%14.6f      |%14.6f     |", x, func, log(x + 1));
		if (n == kMaxIters)
			cout << "  max iter  |\n";
		else
			printf("%7d     |\n", n);
	}
	cout << string(69, '-');

	return 0;
}