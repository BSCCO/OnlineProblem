//LintCode
//167.链表求和 
//
//你有两个用链表代表的整数，其中每个节点包含一个数字。数字存储按照在原来整数中相反的顺序，使得第一个数字位于链表的开头。写出一个函数将两个整数相加，用链表形式返回和。
//
//样例
//给出两个链表 3->1->5->null 和 5->9->2->null，返回 8->0->8->null

#include<iostream>
#include"LintCode.h"

//先各个数位相加，再遍历一次处理进位，以简化进位处理
ListNode *addLists(ListNode *l1, ListNode *l2) {
	if (!l1) {
		return l2;
	}
	if (!l2) {
		return l1;
	}

	ListNode *head = new ListNode(0);
	ListNode *p = head;
	p->val = l1->val + l2->val;
	while (l1->next&&l2->next) {	//相加
		l1 = l1->next;
		l2 = l2->next;
		p->next = new ListNode(0);
		p = p->next;
		p->val = l1->val + l2->val;
	}
	if (!l1->next) {
		p->next = l2->next;
	}
	if (!l2->next) {
		p->next = l1->next;
	}
	int c = 0;			//处理进位，最高位进位需要new，特殊处理
	for (p = head; !p->next; p = p->next) {
		p->val += c;
		c = p->val / 10;
		p->val %= 10;
	}
	if (p->val>10) {	//处理最高位的进位
		p->next = new ListNode(p->val / 10);
		p->val %= 10;
	}
	return head;
}

void testAddList() {

}