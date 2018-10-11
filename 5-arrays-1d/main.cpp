#include <iostream>

using namespace std;

int main(){
    int i, n, x = 1, j = 0, otr1, otr2;
    double summa1 = 0, summa2 = 0;
    cout << "vvedite razmer massiva\nn = ";
    cin >> n;
    double *a = new double [n];
    double *b = new double [n];
    cout << "\nvvedite massiv\n";
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (!(i % 2)) summa1 += a[i];
        if (a[i] < 0)
          if (x){x = 0; otr1 = i;}
          else otr2 = i;
    }
    for (i = otr1 + 1; i < otr2; i++)
        summa2 += a[i];
    for (i = 0; i < n; i++)
        if ((a[i] >= 1) || (a[i] <= -1)) b[j++] = a[i];
    cout << "summa1 = " << summa1 << endl;
    cout << "summa2 = " << summa2 << endl;
    cout << "massiv" << endl;
    for (i = 0; i < j; i++)
        cout << b[i] << " ";
    delete [] a;
    delete [] b;
    return 0;
}