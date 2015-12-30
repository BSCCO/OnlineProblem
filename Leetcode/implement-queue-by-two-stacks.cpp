//��ջʵ�ֶ��� �鿴���н��
//
//�����������������Ҫʹ������ջ��ʵ�ֶ��е�һЩ������
//
//����Ӧ֧��push(element)��pop() �� top()������pop�ǵ��������еĵ�һ��(��ǰ���)Ԫ�ء�
//
//pop��top������Ӧ�÷��ص�һ��Ԫ�ص�ֵ��
//
//����
//����push(1), pop(), push(2), push(3), top(), pop()����Ӧ�÷���1��2��2
//
//��ս
//��ʹ������ջ��ʵ��������ʹ���κ��������ݽṹ��push��pop �� top�ĸ��Ӷȶ�Ӧ���Ǿ�̯O(1)��

#include<stack>

using std::stack;
class Queue {
public:
	stack<int> stack1;
	stack<int> stack2;

	Queue() {
		// do intialization if necessary
	}

	//���ʱ����Ԫ��ѹ��s1��
	void push(int element) {
		stack1.push(element);
	}

	//����ʱ���ж�s2�Ƿ�Ϊ�գ��粻Ϊ�գ���ֱ�ӵ�����Ԫ�أ���Ϊ�գ���s1��Ԫ����������롱s2�������һ��Ԫ�ص��������ӡ�
	int pop() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				int ele = stack1.top();
				stack2.push(ele);
				stack1.pop();
			}
		}
		int top = stack2.top();
		stack2.pop();
		return top;
	}

	int top() {
		if (stack2.empty()) {
			while (!stack1.empty()) {
				int ele = stack1.top();
				stack2.push(ele);
				stack1.pop();
			}
		}
		return stack2.top();
	}
};