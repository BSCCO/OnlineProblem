#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	multimap<int, int> map;
	int index1, index2;
	for (unsigned int i = 0; i != nums.size(); ++i) {
		map.insert({ nums[i],i + 1 });
	}
	auto map_it = map.cbegin();
	while (map_it != map.cend()) {
		auto diff = map.find(target - map_it->first);
		if ( diff!= map.end()) {
			if (map.count(map_it->first) != 1) {
				index1 = map_it->second;
				index2 = (++map_it)->second;
				break;
			}
			else {
				index1 = map_it->second;
				index2 = diff->second;
				break;
			}

		}
		++map_it;
	}
	vector<int> ans;
	ans.push_back(index1 < index2 ? index1 : index2);
	ans.push_back(index1 > index2 ? index1 : index2);
	return ans;

}

void testTwoSum()
{
	vector<int> nums = { 0,2,0 };
	vector<int> ans = twoSum(nums, 0);
	cout << "index1=" << ans[0] << endl;
	cout << "index2=" << ans[1] << endl;
	cin.get();
}