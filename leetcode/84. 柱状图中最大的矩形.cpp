/** https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*题目：给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积。
*示例：输入: [2,1,5,6,2,3]    
      输出: 10
 
*思路：参考 https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
     （1）暴力法：选定某根柱子后，从这根柱子开始向两边找，直到找到比他矮的柱子为止，这样可以得到这根柱子所能得到的最大矩形面积。需要遍历所有的柱子，时间复杂度总共是o(n^2)
	 （2）单调栈：单调栈中，越上面的元素，值越大。这样不断的把元素压入栈中，当要压入的元素小于栈顶元素，则将栈顶元素出站，同时只需要o(1)的复杂度就能找到两边的柱子位置，从而计算该柱子获得的最大矩形面积。
*/
#include"biaozhun.h"
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	if (heights.size() < 1) return 0;
	int maxAre = heights[0];
	stack<int> st;
	st.push(0);

	//l表示小于当前的第a号柱子的左边的第一个柱子的下标
	int l = 0, a;
	for (int i = 1; i < heights.size(); i++) {
		while (!st.empty() && heights[i] < heights[st.top()]) {
			a = st.top();
			st.pop();
			if (st.empty()) l = -1;
			else l = st.top();
			//i即为小于当前的第a号柱子的左边的第一个柱子的下标，与l对应
			maxAre = max(maxAre, (i - l - 1)*heights[a]);
		}
		if (st.empty()) st.push(i);
		else {
			if (heights[i] == heights[st.top()]) st.pop();
			st.push(i);
		}
	}
	//单调栈，右边没有更小的柱子，所以用数组边界来计算矩形面积。
	while (!st.empty()) {
		a = st.top();
		st.pop();
		if (st.empty()) l = -1;
		else l = st.top();
		maxAre = max(maxAre, (int)(heights.size() - 1 - l)*heights[a]);
	}
	return maxAre;
}
void main84() {
	int a[] = { 2,1,5,6,2,3 };
	vector<int> heights(a,a+6);

	cout << largestRectangleArea(heights);
	cin.get();
}