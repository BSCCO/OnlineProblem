//212.�ո��滻
//
//���һ�ַ�������һ���ַ����е����пո��滻�� % 20 ������Լ�����ַ������㹻�Ŀռ��������µ��ַ�������õ����ǡ���ʵ�ġ��ַ����ȡ�
//
//��ĳ�����Ҫ���ر��滻����ַ����ĳ��ȡ�
//
//����
//�����ַ���"Mr John Smith", ����Ϊ 13
//
//�滻�ո�֮��Ľ��Ϊ"Mr%20John%20Smith"
//
//ע��
//���ʹ�� Java �� Python, �����������ַ������ʾ�ַ�����
//
//��ս
//��ԭ�ַ���(�ַ�����)������滻�������ö���ռ�

#include<iostream>

//�滻һ���ո�spaceָ��ǰҪ���滻�Ŀո�
void insert_space(char *space) {
	char *p1 = space + 1;
	for (; *p1 != '\0'; ++p1) {}	//p1���ҵ��ַ���β��
	for (char *p2 = p1 + 2; p1>space; --p1, --p2) {	//����ÿ���ַ��������λ
		*p2 = *p1;
	}
	*p1 = '%';	//�ո��滻��%20
	p1[1] = '2';
	p1[2] = '0';
}
//ÿ��һ���ո񳤶�����2������ո����������ÿ���ո����һ������ĺ���
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
