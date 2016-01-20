//Construct Binary Tree from Preorder and Inorder Traversal
//
//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Have you met this question in a real interview ? Yes
//Example
//Given in - order[1, 2, 3] and pre - order[2, 1, 3], return a tree :
//
//  2
// / \
//1   3
//Note
//You may assume that duplicates do not exist in the tree.

#include<iostream>
#include<vector>
#include"TreeNode.h"

using std::vector;

TreeNode *build(vector<int>::iterator pre, vector<int>::iterator preEnd,
	vector<int>::iterator in, vector<int>::iterator inEnd ) {
	if (pre == preEnd) {
		return nullptr;
	}
	TreeNode *node = new TreeNode(*pre);
	vector<int>::iterator inLeftEnd = in;
	vector<int>::iterator preLeftEnd = pre+1;
	while (*inLeftEnd != *pre) {
		++inLeftEnd;
		++preLeftEnd;
	}
	node->left=build(pre + 1, preLeftEnd, in, inLeftEnd);
	node->right = build(preLeftEnd,preEnd,inLeftEnd+1,inEnd);
	return node;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

void testBuildTree() {
	vector<int> inorder = { 4,8,2,7,5,1,10,6,11,3,9 };
	vector<int> preorder = { 1,2,4,8,5,7,3,6,10,11,9 };
	TreeNode *head = buildTree(preorder, inorder);
	preVisit(head);
	std::cout << std::endl;
	inVisit(head);
	std::cout << std::endl;
	system("Pause");
}