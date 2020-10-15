/** https://leetcode-cn.com/problems/zigzag-conversion/
题目：将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。具体见网站

思路：找数学规律，每k = numRows * 2 - 2重复一个新的Z字形，因此只需要对一个Z字形进行判断字母的分布。刚拿到题目，我的第一想法是对字符串遍历，但是这样需要内嵌行数numRows的遍历，会慢很多。将行数numRows作为主循环的话，可以一次从字符串中取出该行的所有字符。
*/

#include"biaozhun.h"
using namespace std;

string convert(string s, int numRows) {
	if (numRows <= 1) return s;
	string s1;

	//每k = numRows * 2 - 2重复一个新的Z字形（因为一个numRows行的Z字形，由k个字母组成）
	int k = numRows * 2 - 2;
	int j;
	for (int i = 0; i < numRows; i++) {
		j = i;
		while (j < s.size()) {
			//无论是哪一行，一个Z字形中至少包含一个字母
			s1 += s[j];

			//除了首尾，其他行有两个字母，因此需要加上另一个（根据数学规律），同时还要防止数组访问越界
			if (i > 0 && i < numRows - 1 && (numRows - i - 1) * 2 + j < s.size())
				s1 += s[(numRows - i - 1) * 2 + j];
			j += k;
		}
	}
	return s1;
}
void main6() {

	int a; cin >> a;
}