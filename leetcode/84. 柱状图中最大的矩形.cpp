/** https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
*��Ŀ������ n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 �����ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*ʾ��������: [2,1,5,6,2,3]    
      ���: 10
 
*˼·���ο� https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode-/
     ��1����������ѡ��ĳ�����Ӻ󣬴�������ӿ�ʼ�������ң�ֱ���ҵ�������������Ϊֹ���������Եõ�����������ܵõ����������������Ҫ�������е����ӣ�ʱ�临�Ӷ��ܹ���o(n^2)
	 ��2������ջ������ջ�У�Խ�����Ԫ�أ�ֵԽ���������ϵİ�Ԫ��ѹ��ջ�У���Ҫѹ���Ԫ��С��ջ��Ԫ�أ���ջ��Ԫ�س�վ��ͬʱֻ��Ҫo(1)�ĸ��ӶȾ����ҵ����ߵ�����λ�ã��Ӷ���������ӻ�õ������������
*/
#include"biaozhun.h"
using namespace std;

int largestRectangleArea(vector<int>& heights) {
	if (heights.size() < 1) return 0;
	int maxAre = heights[0];
	stack<int> st;
	st.push(0);

	//l��ʾС�ڵ�ǰ�ĵ�a�����ӵ���ߵĵ�һ�����ӵ��±�
	int l = 0, a;
	for (int i = 1; i < heights.size(); i++) {
		while (!st.empty() && heights[i] < heights[st.top()]) {
			a = st.top();
			st.pop();
			if (st.empty()) l = -1;
			else l = st.top();
			//i��ΪС�ڵ�ǰ�ĵ�a�����ӵ���ߵĵ�һ�����ӵ��±꣬��l��Ӧ
			maxAre = max(maxAre, (i - l - 1)*heights[a]);
		}
		if (st.empty()) st.push(i);
		else {
			if (heights[i] == heights[st.top()]) st.pop();
			st.push(i);
		}
	}
	//����ջ���ұ�û�и�С�����ӣ�����������߽���������������
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