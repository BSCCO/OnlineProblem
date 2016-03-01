//335. Self Crossing My Submissions Question
//Total Accepted : 1441 Total Submissions : 8107 Difficulty : Medium
//You are given an array x of n positive numbers.You start at point(0, 0) and moves x[0] metres to the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on.In other words, after each move your direction changes counter - clockwise.
//
//Write a one - pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
//
//Example 1 :
//	Given x = [2, 1, 1, 2],
//	©°©¤©¤©¤©´
//	©¦      ©¦
//	©¸©¤©¤©¤©à©¤©¤>
//	        ©¦
//
//	Return true (self crossing)
//	Example 2:
//Given x = [1, 2, 3, 4],
//©°©¤©¤©¤©¤©¤©¤©´
//©¦            ©¦
//©¦
//©¦
//©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤>
//
//Return false (not self crossing)
//Example 3:
//Given x = [1, 1, 1, 1],
//©°©¤©¤©¤©´
//©¦      ©¦
//©¸©¤©¤©¤©à>
//
//Return true (self crossing)


//Generally, when add a new line(such as 5th in the under picture), it acrosses or not only relates to the former five lines, 
//     1
//©°©¤©¤©¤©¤©´
//©¦        ©¦0
//©¦
//©¦2      5
//©¦	 <¡ª©´
//©¦        ©¦4
//©¸©¤©¤©¤©¤©¼
//     3
//If the 5th line acrosses, it can only across the 0th or the 2nd line, so we know when to return true.
//For x[4], there is only 4 lines before it, just let the 0th line to be 0,it follows the rules, too.
#include<vector>
#include<deque>
#include<iostream>

using std::vector;
using std::deque;

//remove the oldest line and add a new line
void push(deque<int>& x, int n) {
	x.pop_front();
	x.push_back(n);
}

bool isSelfCrossing(vector<int>& x) {
	if (x.size() < 4) {
		return false;
	}
	
	deque<int> side(6, 0);	//store current line and the former five lines
	for (int i = 0; i<3; i++) {
		push(side, x[i]);	
	}
	for (int i = 3; i < x.size(); i++) {
		push(side, x[i]);

		//side[5] cross side[2]
		if (side[5] >= side[3] && side[4] <= side[2]) {
			return true;
		}

		//side[5] cross side[0]
		if (side[3] >= side[1] && side[1] + side[5] >= side[3]
			&& side[4] <= side[2] && side[0] <= side[2] && side[0] + side[4] >= side[2]) {
			return true;
		}

	}
	return false;
}

void testIsSelfCrossing() {
	vector<int> x = { 2,1,1,2 };
	std::cout << isSelfCrossing(x) << std::endl;
}