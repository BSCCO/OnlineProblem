//LintCode
//41.最大子数组
//
//给定一个整数数组，找到一个具有最大和的子数组，返回其最大和。
//
//样例
//给出数组[?2, 2, ?3, 4, ?1, 2, 1, ?5, 3]，符合要求的子数组为[4, ?1, 2, 1]，其最大和为6
//
//注意
//子数组最少包含一个数
//
//挑战
//要求时间复杂度为O(n)

#include"LintCode.h"
#include<vector>
#include<iostream>

using std::vector;
using std::cout;
using std::endl;

int maxSubArray(vector<int> nums) {
	int max_sum = -2147483647-1;
	int sum = 0;
	for (int i = 0; i != nums.size(); ++i) {
		sum += nums[i];
		if (nums[i]>sum) {
			sum = nums[i];
		}
		if (sum>max_sum) {
			max_sum = sum;
		}
	}
	return max_sum;
}

void testMaxSubArray() {
	vector<int> nums = { -2,2,3,8,-10,35,-12,-10,-123,12 };
	cout << maxSubArray(nums) << endl;
	return;
}