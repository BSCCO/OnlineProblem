#pragma once
#include<iostream>
#include<vector>
using std::vector;
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode() = default;
	TreeNode(int n) :val(n), left(nullptr), right(nullptr) {}
};

void preVisit(TreeNode *head) {
	if (head == nullptr)
		return;
	std::cout << head->val << " ";
	preVisit(head->left);
	preVisit(head->right);
}

void inVisit(TreeNode *head) {
	if (head == nullptr)
		return;
	inVisit(head->left);
	std::cout << head->val << " ";
	inVisit(head->right);
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);