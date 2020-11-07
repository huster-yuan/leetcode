/** 网址 https://leetcode-cn.com/problems/maximum-subarray/
*题目：给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*示例：输入: [-2,1,-3,4,-1,2,1,-5,4]
      输出: 6
      解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*思路：动态规划，dp[i]表示从数组下标0开始到i的最大连续子序列的值。状态转移方程 dp[i]=max(dp[i-1]+nums[i],nums[i]）;
*/
#include"biaozhun.h"
using namespace std;
int maxSubArray(vector<int>& nums) {
	int len = nums.size();
	int maxSum = INT_MIN;
	vector<int> dp(nums.size());
	dp[0] = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		maxSum = max(maxSum, dp[i]);
	}
	return maxSum;

}

void main53() {
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4};
	cout << maxSubArray(nums);
	cin.get();
}