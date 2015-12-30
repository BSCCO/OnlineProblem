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

//�Ȱ�string�еĵ�����ȡ����������һ��deque<string>�У���������ϳ��µ�string
string reverseWords(string s) {
	if (s.empty()) {
		return s;
	}
	deque<string> word;
	for (string::size_type i = 0; i < s.size(); ++i) {		
		while (s[i] == ' ') {	//�ҵ���һ����ĸ
			++i;
		}
		if (i == s.size()) {	//����Խ��
			break;
		}
		string w;
		while (s[i] != ' '&&i < s.size()) {		//��ȡ����
			w += s[i];
			++i;
		}
		word.push_front(w);		//�������deque��
	}
	string rev_s;
	for (string::size_type i = 0; i != word.size(); ++i) {	//��deque��ȡ����������µ�string
		rev_s = rev_s + word[i] + ' ';
	}
	rev_s.pop_back();	//ȥ��β���Ŀո�
	return rev_s;
}

void testReverseWords() {
	std::cout<<reverseWords("How are you") << std::endl;
}