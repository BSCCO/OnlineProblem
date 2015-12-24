//319. Bulb Switcher 
//
//There are n bulbs that are initially off.You first turn on all the bulbs.Then, you turn off every second bulb.On the third round, you toggle every third bulb(turning on if it's off or turning off if it's on).For the nth round, you only toggle the last bulb.Find how many bulbs are on after n rounds.
//
//Example :
//
//	Given n = 3.
//
//	At first, the three bulbs are[off, off, off].
//	After first round, the three bulbs are[on, on, on].
//	After second round, the three bulbs are[on, off, on].
//	After third round, the three bulbs are[on, off, off].
//
//	So you should return 1, because there is only one bulb is on.

#include<iostream>

int bulbSwitch(int n) {
	int on_bulbs = 0;
	for (int m = 1; m <= n; ++m) {		//对每个灯泡而言
		int count = 0;					//记状态被变换的次数为count
		for (int i = 1; i <= m; ++i) {
			if (m%i == 0) {				//在第i轮（m能整除i）时状态发生变化
				++count;
			}
		}
		on_bulbs += count % 2;			//变了奇数次则灯泡是亮的
	}
	return on_bulbs;
}										//O(n^2)时间复杂度

void testBulbSwitch() {
	int n = 0;
	std::cout << "Enter n:" << std::endl;
	while (std::cin >> n) {
		std::cout << bulbSwitch(n) << std::endl;
		std::cout << "Enter n:" << std::endl;
	}
}