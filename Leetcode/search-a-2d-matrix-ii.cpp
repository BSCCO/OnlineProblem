//������ά���� II
//
//д��һ����Ч���㷨������m��n�����е�ֵ���������ֵ���ֵĴ�����
//
//�����������������ԣ�
//
//ÿ���е�����������������ġ�
//ÿһ�е��������ϵ���������ġ�
//��ÿһ�л�ÿһ����û���ظ���������
//����
//�������о���
//
//[
//
//	[1, 3, 5, 7],
//
//	[2, 4, 7, 8],
//
//	[3, 5, 9, 10]
//
//]
//
//����target = 3������ 2
//
//��ս
//Ҫ��O(m + n) ʱ�临�ӶȺ�O(1) ����ռ�
#include<vector>
#include<iostream>

using std::vector;
int searchMatrix(vector<vector<int> > &matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}
	auto m = matrix.size();// m��
	auto n = matrix[0].size();//n��
	decltype(m) i = 0;	//��ʼλ�����Ͻ�
	auto j = n-1;
	size_t count = 0;
	while (i < m&&j >= 0) {
		if (matrix[i][j] == target) {
			--j, ++i;
			++count;
		}
		else if (matrix[i][j]>target) {
			--j;
		}
		else if (matrix[i][j] < target) {
			++i;
		}
	}
	return count;
}

void testSearchMatrix() {
	vector<vector<int> > matrix = 
	{
		{1,3,5,7},
		{2,4,7,8},
		{3,5,9,10}
	};
	std::cout << searchMatrix(matrix, 3) << std::endl;
}