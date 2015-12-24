//LintCode
//41.���������
//
//����һ���������飬�ҵ�һ���������͵������飬���������͡�
//
//����
//��������[?2, 2, ?3, 4, ?1, 2, 1, ?5, 3]������Ҫ���������Ϊ[4, ?1, 2, 1]��������Ϊ6
//
//ע��
//���������ٰ���һ����
//
//��ս
//Ҫ��ʱ�临�Ӷ�ΪO(n)

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