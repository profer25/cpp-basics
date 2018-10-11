#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    bool flag = false;
    int i;
    getline(cin, s);
    for (i = 0; i < s.size(); i++)
        if (((s[i] == 'a') || (s[i] == 'e') || (s[i] == 'y') || (s[i] == 'u') || (s[i] == 'i') || (s[i] == 'o')) && (i == 0 || (s[i - 1] == ' ' && i > 0))){
            while (s[i] != ' ' && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
                cout << s[i++];
        cout << endl;
        flag = true;
    }
    if (!flag) cout << "not found";
    fclose(stdin);
    fclose(stdout);
    return 0;
}