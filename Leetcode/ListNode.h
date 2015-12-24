#pragma once

#include<iostream>
#include<vector>

struct ListNode {
	int val=0;
	ListNode *next=nullptr;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *creatListNode(std::vector<int> nums);
void printListNode(ListNode *list);