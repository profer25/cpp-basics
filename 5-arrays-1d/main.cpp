#include <iostream>

using namespace std;

int main(){
    int i, n, x = 1, j = 0, otr1, otr2;
    double pr = 1, summa = 0;
    cin >> n;
    double *a = new double [n];
    double *b = new double [n];
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (!(i % 2)) pr *= a[i];
        if (a[i] < 0)
          if (x){x = 0; otr1 = i;}
          else otr2 = i;
    }
    for (i = otr1 + 1; i < otr2; i++)
        summa += a[i];
    for (i = 0; i < n; i++)
        if ((a[i] >= 1) || (a[i] <= -1)) b[j++] = a[i];
    cout << "proizvedenie = " << pr << endl;
    cout << "summa = " << summa << endl;
    cout << "massiv" << endl;
    for (i = 0; i < j; i++)
        cout << b[i] << " ";
    delete [] a;
    delete [] b;
    return 0;
}