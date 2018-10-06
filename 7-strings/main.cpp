#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string s;
    int i;
    getline(cin, s);
    for (i = 0; i < s.size(); i++)
        if (((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'y') || (s[i] == 'u') || (s[i] == 'i') || (s[i] == 'o')) && (i == 0 || (s[i - 1] == ' ' && i > 0))){
            while (s[i] != ' ')
                cout << s[i++];
        cout << endl;
    }
    return 0;
}