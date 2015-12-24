//LintCode
//167.������� 
//
//����������������������������ÿ���ڵ����һ�����֡����ִ洢������ԭ���������෴��˳��ʹ�õ�һ������λ������Ŀ�ͷ��д��һ������������������ӣ���������ʽ���غ͡�
//
//����
//������������ 3->1->5->null �� 5->9->2->null������ 8->0->8->null

#include<iostream>
#include"LintCode.h"

//�ȸ�����λ��ӣ��ٱ���һ�δ����λ���Լ򻯽�λ����
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
	while (l1->next&&l2->next) {	//���
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
	int c = 0;			//�����λ�����λ��λ��Ҫnew�����⴦��
	for (p = head; !p->next; p = p->next) {
		p->val += c;
		c = p->val / 10;
		p->val %= 10;
	}
	if (p->val>10) {	//�������λ�Ľ�λ
		p->next = new ListNode(p->val / 10);
		p->val %= 10;
	}
	return head;
}

void testAddList() {

}