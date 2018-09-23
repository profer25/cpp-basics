#include <iostream>
#include <cmath>
#include <cfloat>

using namespace std;

int main(){
    double x, eps = DBL_EPSILON, ln = 1, f = 1;
    cin >> x;
    for(int i = 0; abs(ln) > eps; i++){
        ln *= ((2 * i + 1) / (x * x * (2 * i + 3)));
        f += (2 * ln);
        if (i < 500) cout << f << endl;
        else{
            cout << '-' << endl;
            break;
        }
    }
    return 0;
}