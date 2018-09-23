#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <cfloat>

using namespace std;

double f_ln(int i, double x){
    return ((2 * i + 1) / (x * x * (2 * i + 3)));
}
    
void ext(int i, double f){
    if (i < 500) cout << f << endl;
        else{
            cout << '-' << endl;
            abort; //halt;
        }
}   
    
int main(){
    double x, eps = DBL_EPSILON, ln = 1, f = 1;
    cin >> x;
    for(int i = 0; abs(ln) > eps; i++){
        ln *= f_ln(i, x);
        f += (2 * ln);
        ext(i, f);
    }
    return 0;
}