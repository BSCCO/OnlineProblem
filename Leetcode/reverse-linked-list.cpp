//��ת����
//
//��תһ������
//
//����
//����һ������1->2->3->null�������ת�������Ϊ3->2->1->null
//
//��ս
//��ԭ��һ�η�ת���

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