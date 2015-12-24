//LintCode
//365.二进制中有多少个1 
//
//计算在一个 32 位的整数的二进制表式中有多少个 1.
//
//样例
//给定 32 (100000)，返回 1
//
//给定 5 (101)，返回 2
//
//给定 1023 (111111111)，返回 9

#include"LintCode.h"

const int BITS_LENGTH = 32;

//从最低位数起，num%2可知最后一位是否是1，num/=2相当于右移一位
//负数取反变成正数，算出取反后的1数目就是原来数中的0的个数，用32减即可
int countOnes(int num) {
	int count = 0;
	if (num >= 0) {
		while (num) {
			count += num % 2;
			num /= 2;
		}
		return count;
	}
	else {
		num=~num;
		while (num) {
			count += num % 2;
			num /= 2;
		}
		return BITS_LENGTH - count;
	}
}

void testCountOnes(){
	std::cout << countOnes(-1) << std::endl;
}