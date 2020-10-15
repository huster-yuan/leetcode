/** https://leetcode-cn.com/problems/two-sum/
*题目：给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
*     进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
*
*思路：关键在于求两个数组中的第k大数，主要思想是：比较nums1、nums2的第k/2大数a、b的大小，如果 a<b ，说明第 k 大数肯定是大于数组nums1的第k/2个数，小于b数组的后k/2个数。然后分别砍去这两部分，可以通过两个游标来调整数组的初始和末尾位置，从而不改变原始数组，然后还要对k进行更新，最后递归调用即可。然后就是需要多考虑特殊情况，防止数组访问越界。相当于2分法，时间复杂度是 O(log(m + n))
*/

#include"biaozhun.h"
using namespace std;
//求第k大数。n1、n2和len1、len2为此时数组nums1、nums2的初始位置和数组长度
double mink(vector<int>& nums1, vector<int>& nums2, int n1, int n2, int k, int len1, int len2) {
	//其中一个数组为空,则第k大数就为另一个数组中的第k个数
	if (len1 <= 0) return nums2[n2 + k - 1];
	if (len2 <= 0) return nums1[n1 + k - 1];

	//k=1时，也就是求最小数，直接比较目前两个数组的第一个数
	if (k == 1) return min(nums1[n1], nums2[n2]);
	else {
		//当一个数组长度不够k/2时，将该数组的末位数（最大数）与另一个数组的初位数（最小数）比较
		//若nums1长度不超过k/2
		if (k / 2 >= len1) {
			//nums1的最大数比nums2的最小数还要小，则可直接从nums2中输出第k大数
			if (nums2[n2 - 1 + k / 2] >= nums1[n1 + len1 - 1]) return nums2[n2 - 1 + k - len1];
			//否则切掉nums2的前k/2个数（因为第k大数一定不在其中），nums1不变
			else return mink(nums1, nums2, n1, n2 + k / 2, k - k / 2, len1, len2 - k / 2);
		}
		//若nums2长度不超过k/2，与上一种情况同理
		if (k / 2 >= len2) {
			if (nums1[n1 - 1 + k / 2] >= nums2[n2 + len2 - 1]) return nums1[n1 - 1 + k - len2];
			else return mink(nums1, nums2, n1 + k / 2, n2, k - k / 2, len1 - k / 2, len2);
		}

		//砍掉两边的时候需要注意特殊情况，有时候不能砍掉第2/k个数，这里可以想办法再优化一下
		if (nums2[n2 + k / 2 - 1] >= nums1[n1 + k / 2 - 1]) return mink(nums1, nums2, n1 + k / 2, n2, k - k / 2, len1 - k / 2, min(k / 2 + k % 2, len2));
		else return mink(nums1, nums2, n1, n2 + k / 2, k - k / 2, min(k / 2 + k % 2, len1), len2 - k / 2);
	}

}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int len1 = nums1.size();
	int len2 = nums2.size();

	//分奇偶两种情况判断。如：若总共有9个数，输出第5大数即可，若总共10个数，需输出第5、6大数的平均值
	if ((len1 + len2) % 2 == 1) return mink(nums1, nums2, 0, 0, (len1 + len2 + 1) / 2, len1, len2);
	else return (mink(nums1, nums2, 0, 0, (len1 + len2) / 2, len1, len2) + mink(nums1, nums2, 0, 0, (len1 + len2) / 2 + 1, len1, len2)) / 2;
}
void main4() {
	int a1[1] = { 3 };
	int a2[5] = { 1,2,4,5,6 };
	vector<int> nums1(a1, a1 + 1);
	vector<int> nums2(a2, a2 + 5);
	cout << findMedianSortedArrays(nums1, nums2);

	int ak;
	cin >> ak;
}
