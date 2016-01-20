//58.Length of Last Word
//
//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	For example,
//	Given s = "Hello World",
//	return 5.

#include<iostream>
#include<string>

using namespace std;

int lengthOfLastWord(string s) {
	if (s.empty())
		return 0;
	int i = s.size() - 1;
	while ((i + 1) && s[i] == ' ') {  //s[i] is the last character except ' '
		--i;								
	}
	int length = 0;
	if (i > -1) {
		while (length < i + 1 && s[i - length] != ' ') {
			++length;
		}
	}
	return length;
}

void testLengthOfLastWord() {
	cout << lengthOfLastWord("a");
	cin.get();
}