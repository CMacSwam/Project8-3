#include <iostream>
#include <string>
#include<cstring>

using namespace std;

int romanCharValue(char r);
int convertRomanToInt(string s);

int main(){
	string input;

	while (true) {
		cout << "Enter Roman number or Q to quit: ";
		getline(cin, input);
		if (input == "Q") break;
		cout << convertRomanToInt(input) << endl;
	}

	return 0;

}

int romanCharValue(char r) {

	switch (r) {
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
	
}

int convertRomanToInt(string s) {

	int total = 0;

		for (int i = 0; i < s.length(); i++) {
			if ((romanCharValue(s[i]) >= romanCharValue(s[i + 1])) || s.length() == 1) {
				total += romanCharValue(s[i]);
			}
			else {
				total += romanCharValue(s[i + 1]) - romanCharValue(s[i]);
				i++;
			}
		}

		return total;
}