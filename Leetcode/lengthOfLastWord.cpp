#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(string s) {
	int spt = 0;
	for (int i = 0; i != s.size(); ++i) {
		if (s[i] == ' ')
			spt = i + 1;
	}
	return s.size() - spt;

}

void testLengthOfLastWord() {
	cout << lengthOfLastWord("a");
	cin.get();
}