/** https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*题目：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
*
*思路：使用两个游标来控制（滑动窗口），当新字符与已有序列中的字符重复时，调整游标，否则判断此时子串长度是否比历史长度还长。
*/
#include"biaozhun.h"
using namespace std;
int lengthOfLongestSubstring(string s) {

	//index当前时刻子串的初始位置
	int index = 0; 
	int pos;
	if (s.length() < 2) return s.length();

	//历史最长子串长度
	int maxlen = 1;
	for (int j = 1; j < s.length(); j++) {
		//j为当前子串的末尾位置
		//fand函数返回从index位置起，字符s[j]在s中的第一个位置
		pos = s.find(s[j], index);

		//pos<j 说明与当前子串中的字符相同，调整游标（不需要判断maxlen，这个动作不可能让子串变长）
		if (pos < j) index = pos + 1;
		else {
			//当前子串变大，比较当前子串长度与maxlen大小
			if (j - index + 1 > maxlen) maxlen = j - index + 1;
		}

	}
	return maxlen;
}
void main3() {
	string s = "wabbacd";
	cout << lengthOfLongestSubstring(s);


	int a; cin >> a;
}
