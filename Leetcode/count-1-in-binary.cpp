//LintCode
//365.���������ж��ٸ�1 
//
//������һ�� 32 λ�������Ķ����Ʊ�ʽ���ж��ٸ� 1.
//
//����
//���� 32 (100000)������ 1
//
//���� 5 (101)������ 2
//
//���� 1023 (111111111)������ 9

#include"LintCode.h"

const int BITS_LENGTH = 32;

//�����λ����num%2��֪���һλ�Ƿ���1��num/=2�൱������һλ
//����ȡ��������������ȡ�����1��Ŀ����ԭ�����е�0�ĸ�������32������
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