#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    double eps = 1e-15, f, x;
    
    cout << string(74, '-') << endl << "|";
    
    printf("%7s      |%15s     |%21s   |%11s |\n", "X", "ln(x + 1)", "ln(x + 1)(system)", "iterations");
    
    cout << string(74, '-') << endl;
    
    for (x = -0.9; x <= 1; x += 0.1){
        int i = 0;
        double ln = 1;
        f = 0;
        
        for (; abs(ln) > eps && i < 500; i++){
            ln = pow(-1, i) * pow(x, i + 1) / (i + 1);
            f += ln;
        } 
        
        cout << "|";
        printf("%9.3f    |%14.6f      |%17.6f       |", x, f, log(x + 1));
        
        if (i == 500) cout << "   > 500    |\n"; 
            else printf("%7d     |\n", i);
    }
    
    cout << string(74, '-');
    return 0;
}