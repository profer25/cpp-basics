#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int i, n, x = -1, y = -1;
    double mx, mn, pr = 1, s = 0;
    cin >> n;
    double *a = new double [n];
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < 0) s += a[i];
        if (x == -1){mx = a[i]; x = i;}
        else 
            if (a[i] > mx){mx = a[i]; x = i;}
        if (y == -1){mn = a[i]; y = i;}
        else 
            if (a[i] < mn){mn = a[i]; y = i;}
    }
    for (i = min(x, y) + 1; i < max(x, y); i++)
        pr *= a[i];
    sort(a, a + n);
    cout << "summa = " << s << endl;
    cout << "min = " << mn << endl;
    cout << "max = " << mx << endl;
    cout << "proizvedenie = " << pr << endl;
    cout << "massiv" << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    delete [] a;
    return 0;
}