//搜索二维矩阵 II
//
//写出一个高效的算法来搜索m×n矩阵中的值，返回这个值出现的次数。
//
//这个矩阵具有以下特性：
//
//每行中的整数从左到右是排序的。
//每一列的整数从上到下是排序的。
//在每一行或每一列中没有重复的整数。
//样例
//考虑下列矩阵：
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
//给出target = 3，返回 2
//
//挑战
//要求O(m + n) 时间复杂度和O(1) 额外空间
#include<vector>
#include<iostream>

using std::vector;
int searchMatrix(vector<vector<int> > &matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return 0;
	}
	auto m = matrix.size();// m行
	auto n = matrix[0].size();//n列
	decltype(m) i = 0;	//起始位置右上角
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