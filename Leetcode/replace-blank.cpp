#include<iostream>

void insert_space(char *space) {
	char *length = space + 1;
	for (; *length != '\0'; ++length) {}
	for (char *p = length + 2; length>space; --length, --p) {
		*p = *length;
	}
	*length = '%';
	length[1] = '2';
	length[2] = '0';
}
int replaceBlank(char string[], int length) {
	int count = 0;
	for (int i = 0; i<length; ++i) {
		if (string[i] == ' ') {
			insert_space(string + i);
			string += 2;
			++count;
		}
	}
	return length + count * 2;
}

using std::cout;
using std::endl;

void testReplaceBlank() {
	char string[] = "   ";
	int length = 3;
	
	cout << replaceBlank(string, length) << endl;
	cout << string << endl;
}
