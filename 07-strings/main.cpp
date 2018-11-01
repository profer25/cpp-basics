#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
	ifstream fin("input.txt");
	if (!fin.is_open()) {
		cout << "Can't open file: input.txt!\n";
		return 1;
	}

	string line;
	bool words_exist = false;
	cout << "Words that start with vowel sounds:\n";
	char vowels[12] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
	while (getline(fin, line)) {
		for (unsigned i = 0; i < line.length(); i++)
			if (find(vowels, vowels + 12, line[i]) != (vowels + 12))
				if (i == 0 || (i > 0 && line[i - 1] == ' ')) {
					while (isalpha(line[i]) && line[i] != ' ')
						cout << line[i++];
					cout << endl;
					words_exist = true;
				}
	}
	fin >> line;

	if (!words_exist) cout << "not found";

	fin.close();

	return 0;
}