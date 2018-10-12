#include <iostream>
#include <string>

using namespace std;

struct aeroflot{
    string kuda;
    int reis, type;
};

int main(){
    aeroflot a[10];
    string gorod;
    int i;
    bool flag = false;
    cout << "vvedite gorod, reis, type samoletov:\n";
    for (i = 0; i < 7; i++)
        cin >> a[i].kuda >> a[i].reis >> a[i].type;
    cout << "vvedite gorod: ";
    cin >> gorod;
    for (i = 0; i < 7; i++)
        if (a[i].kuda == gorod){
            flag = true;
            cout << "reis " << a[i].reis << ", type " << a[i].type << endl;
        }
    if (!flag) cout << "net reisov";
    return 0;
}