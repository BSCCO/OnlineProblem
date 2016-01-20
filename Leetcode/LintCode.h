#pragma once
#include"ListNode.h"
#include<string>
#include<vector>
#include<deque>

using std::string;
using std::vector;

int maxSubArray(vector<int> nums);
void testMaxSubArray();

std::string reverseWords(std::string s);
void testReverseWords();

int replaceBlank(char string[], int length);
void testReplaceBlank();

int countOnes(int num);
void testCountOnes();

ListNode *addLists(ListNode *l1, ListNode *l2);
void testAddList();

ListNode *reverse(ListNode *head);
void testReverse();

int findMin(vector<int> &num);
void testFindMin();

int searchMatrix(vector<vector<int> > &matrix, int target);
void testSearchMatrix();

void testBuildTree();