#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, i, j, summa = 0, pr = 1;
    cin >> n;
    int **a = new int *[n];
    for (i = 0; i < n; i++)
        a[i] = new int [n];
    bool *b = new bool [n];
    for (i = 0; i < n; i++){
        int x = 1;
        for (j = 0; j < n; j++){
            cin >> a[i][j];
            if (a[i][j] < 0) x = 0;
        }
        if (x) b[i] = true; else b[i] = false;
    }
    for (i = 0; i < n; i++)
        if (b[i])
            for (j = 0; j < n; j++)
                pr *= a[i][j];
    for (i = 0; i < n; i++){
        int sum1 = 0, sum2 = 0;
        j = 0;
        while (i < n | j < n){
            sum1 += a[i][j];
            sum2 += a[j++][i++];
        }
        summa = max(summa, max(sum1, sum2));
    }
    cout << "proizvedenie = " << pr << endl << "summa = " << summa;
    return 0;
}      