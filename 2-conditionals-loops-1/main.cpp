#include <iostream>

using namespace std;

int main(){
    double xn, xk, dx, a, b, c, f;
    cin >> a >> b >> c >> xn >> xk >> dx;
    for (; xn <= xk; xn += dx){
        if (xn < 0 && b) f = a * xn * xn + b;
        else
            if (xn > 0 && !b) f = (xn - a) / (xn - c);
            else 
                f = xn / c;
        if ((int(a) | int(b)) & (int(a) | int(c))) cout << f << endl;
        else 
            cout << int(f) << endl;
    }
    return 0;
} 