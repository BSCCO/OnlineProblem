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

//先把string中的单词提取出来，放入一个deque<string>中，再重新组合成新的string
string reverseWords(string s) {
	if (s.empty()) {
		return s;
	}
	deque<string> word;
	for (string::size_type i = 0; i < s.size(); ++i) {		
		while (s[i] == ' ') {	//找到第一个字母
			++i;
		}
		if (i == s.size()) {	//避免越界
			break;
		}
		string w;
		while (s[i] != ' '&&i < s.size()) {		//提取单词
			w += s[i];
			++i;
		}
		word.push_front(w);		//逆序放入deque中
	}
	string rev_s;
	for (string::size_type i = 0; i != word.size(); ++i) {	//从deque中取出单词组成新的string
		rev_s = rev_s + word[i] + ' ';
	}
	rev_s.pop_back();	//去掉尾部的空格
	return rev_s;
}

void testReverseWords() {
	std::cout<<reverseWords("How are you") << std::endl;
}