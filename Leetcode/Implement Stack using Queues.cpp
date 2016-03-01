#include<queue>
#include<iostream>

class Stack {
private:
	typedef std::queue<int>* QueuePtr;
	std::queue<int> q1;
	QueuePtr storeQueuePtr = &q1;
	std::queue<int> q2;
	QueuePtr tempQueuePtr = &q2;
	//move a element in q1 to q2 and return this element
	int transferElement(QueuePtr q1, QueuePtr q2) {
		int element = q1->front();
		q2->push(element);
		q1->pop();
		return element;
	}
	//swap the objects that pointers point to
	void swapPtr(QueuePtr &q1, QueuePtr &q2) {
		QueuePtr temp;
		temp = q1;
		q1 = q2;
		q2 = temp;
	}
public:
	// Push element x onto stack.
	void push(int x) {
		storeQueuePtr->push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		while (storeQueuePtr->size()>1) {
			transferElement(storeQueuePtr, tempQueuePtr);
		}
		storeQueuePtr->pop();
		swapPtr(storeQueuePtr, tempQueuePtr);
	}

	// Get the top element.
	int top() {
		int topData;
		while (!(storeQueuePtr->empty())) {
			topData = transferElement(storeQueuePtr, tempQueuePtr);
		}
		swapPtr(storeQueuePtr, tempQueuePtr);
		return topData;
	}

	// Return whether the stack is empty.
	bool empty() {
		return storeQueuePtr->empty();
	}
};

void testStack() {
	Stack s;
	s.push(1);
	s.push(2);
	std::cout << s.top() << std::endl;
	s.pop();
	s.pop();
	std::cout << s.empty() << std::endl;
}