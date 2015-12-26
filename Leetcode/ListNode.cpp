#include "ListNode.h"
#include<vector>


ListNode * creatListNode(std:: vector<int> nums)
{
	ListNode *head = new ListNode(nums[0]);
	ListNode *p = head;
	for (std::vector<int>::size_type i = 1; i < nums.size(); ++i) {
		p->next = new ListNode(nums[i]);
		p = p->next;
	}
	return head;
}

void printListNode(ListNode * list)
{
	if (list == nullptr) {
		return;
	}
	while (list) {
		std::cout << list->val << "->";
		list = list->next;
	}
	std::cout << "null" << std::endl;
}

void deleteListNode(ListNode * head)
{
	ListNode *p = head;
	while (head) {
		p = head;
		head = head->next;
		free(p);
	}
	return;
}


