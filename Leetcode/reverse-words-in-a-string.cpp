//LintCode
//��ת�ַ��� 
//
//����һ���ַ����������ת�ַ����е�ÿ�����ʡ�
//
//����
//����s = "the sky is blue"������"blue is sky the"
//
//˵��
//���ʵĹ��ɣ��޿ո���ĸ����һ������
//�����ַ����Ƿ����ǰ������β��ո񣿿��԰��������Ƿ�ת����ַ����ܰ���
//��δ����������ʼ�Ķ���ո��ڷ�ת�ַ����м�ո���ٵ�ֻ��һ��

#include<iostream>
#include<string>
#include<deque>
using std::string;
using std::deque;

string reverseWords(string s) {
	if (s.empty()) {
		return s;
	}
	deque<string> word;
	string w;
	for (int i = 0; i < s.size(); ++i) {
		while (s[i] == ' ') {
			++i;
		}
		if (i == s.size()) {
			break;
		}
		while (s[i] != ' '&&i < s.size()) {
			w += s[i];
			++i;
		}
		word.push_front(w);
		w.clear();
	}
	string rev_s;
	for (int i = 0; i != word.size(); ++i) {
		rev_s = rev_s + word[i] + ' ';
	}
	rev_s.pop_back();
	return rev_s;
}

void testReverseWords() {
	std::cout<<reverseWords("How are you") << std::endl;
}