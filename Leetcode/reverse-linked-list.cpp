//翻转链表
//
//翻转一个链表
//
//样例
//给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null
//
//挑战
//在原地一次翻转完成

#include"LintCode.h"
#include<iostream>

ListNode *reverse(ListNode *head) {
	if (head == nullptr)
		return head;
	ListNode *pre = head;
	head = head->next;
	pre->next = nullptr;
	while (head) {
		ListNode *p = head;
		head = head->next;
		p->next = pre;
		pre = p;
	}
	return pre;
}

void testReverse() {
	vector<int> nums = { 1,2,3 };
	ListNode *list=creatListNode(nums);
	printListNode(list);
	list=reverse(list);
	printListNode(list);
	return;
}