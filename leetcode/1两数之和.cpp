/** https://leetcode-cn.com/problems/two-sum/
题目：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
     你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

思路：两重循环即可
*/

#include"biaozhun.h"
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	int i, j;
	for (i = 0; i < nums.size(); i++)
		for (j = nums.size() - 1; j > i; j--)
		{
			if (nums[i] + nums[j] == target) {
				cout << i << " " << j << endl;;
				return { i,j };
			}
		}
	
	return { i,j };
}
void main1() {
	int num[4] = {4, 2, 7, 11 };
	vector<int> nums(num, num + 4);
	int target = 9;

	twoSum(nums, target);
	cin >> target;
}



