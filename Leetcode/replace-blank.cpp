//212.空格替换
//
//设计一种方法，将一个字符串中的所有空格替换成 % 20 。你可以假设该字符串有足够的空间来加入新的字符，且你得到的是“真实的”字符长度。
//
//你的程序还需要返回被替换后的字符串的长度。
//
//样例
//对于字符串"Mr John Smith", 长度为 13
//
//替换空格之后的结果为"Mr%20John%20Smith"
//
//注意
//如果使用 Java 或 Python, 程序中请用字符数组表示字符串。
//
//挑战
//在原字符串(字符数组)中完成替换，不适用额外空间

#include<iostream>

//替换一个空格，space指向当前要被替换的空格
void insert_space(char *space) {
	char *p1 = space + 1;
	for (; *p1 != '\0'; ++p1) {}	//p1先找到字符串尾部
	for (char *p2 = p1 + 2; p1>space; --p1, --p2) {	//倒序将每个字符向后移两位
		*p2 = *p1;
	}
	*p1 = '%';	//空格替换成%20
	p1[1] = '2';
	p1[2] = '0';
}
//每有一个空格长度增加2，计算空格个数，并且每个空格调用一次上面的函数
int replaceBlank(char string[], int length) {
	int count = 0;
	for (int i = 0; i<length; ++i) {
		if (string[i] == ' ') {		//
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
	cout << replaceBlank(string, strlen(string)) << endl;
	cout << string << endl;
}
