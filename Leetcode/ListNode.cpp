#include "ListNode.h"
#include<vector>

using std::vector;

ListNode * creatListNode(vector<int> nums)
{
	ListNode *head = new ListNode(nums[0]);
	ListNode *p = head;
	for (vector<int>::size_type i = 1; i < nums.size(); ++i) {
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
	while (list->next) {
		std::cout << list->val << "->";
		list = list->next;
	}
	std::cout << "null" << std::endl;
}
