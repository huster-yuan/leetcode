/** ��ַ https://leetcode-cn.com/problems/maximum-subarray/
*��Ŀ������һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
*ʾ��������: [-2,1,-3,4,-1,2,1,-5,4]
      ���: 6
      ����: ���������� [4,-1,2,1] �ĺ����Ϊ 6��

*˼·����̬�滮��dp[i]��ʾ�������±�0��ʼ��i��������������е�ֵ��״̬ת�Ʒ��� dp[i]=max(dp[i-1]+nums[i],nums[i]��;
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