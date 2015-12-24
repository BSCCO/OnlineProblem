//LintCode
//翻转字符串 
//
//给定一个字符串，逐个翻转字符串中的每个单词。
//
//样例
//给出s = "the sky is blue"，返回"blue is sky the"
//
//说明
//单词的构成：无空格字母构成一个单词
//输入字符串是否包括前导或者尾随空格？可以包括，但是反转后的字符不能包括
//如何处理两个单词间的多个空格？在反转字符串中间空格减少到只含一个

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