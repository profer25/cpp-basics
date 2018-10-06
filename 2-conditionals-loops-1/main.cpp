#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    double xn, xk, dx, a, b, c, f;
    cout << "vvedi a, b, c" << endl << "a = ";
    cin >> a;
    cout << endl << "b = ";
    cin >> b;
    cout << endl << "c = ";
    cin >> c;
    cout << endl << "vvedi xn, xk, dx" << endl << "xn = ";
    cin >> xn;
    cout << endl << "xk = ";
    cin >> xk;
    cout << endl << "dx = ";
    cin >> dx;
    cout << "-------------------------------------" << endl;
    cout << "|        X        |        F        |" << endl;
    cout << "-------------------------------------" << endl;
    for (double x = min(xk, xn); x <= max(xk, xn); x += dx){
        bool flag = false;
        if (x && c < 0) f = -a * x - c;
        else
            if (!x && c > 0) f = x - a / -c;
            else 
                if (c - a) f = b * x / (c - a);
                else flag = true;
        cout << "|";
        if (x < 0) printf("%11.3f      |", x);
        else printf("%11.3f      |", x);
        if (flag) cout <<"  devision by 0  |\n";
        else
            if (!(int(a) | int(b)) & (int(b) | int(c))) printf("%12.3f     |", f);
            else{
                int f1 = int(f);
                printf("%12d     |\n", f1);
            }
    }
    cout << "-------------------------------------";
    return 0;
} 