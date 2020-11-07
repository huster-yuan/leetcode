/** https://leetcode-cn.com/problems/longest-palindromic-substring/
*题目：给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*示例：输入: "babad"
      输出: "bab"
      注意: "aba" 也是一个有效答案。
*
*思路：使用的是Manacher算法思想，使用辅助分隔符‘#’将字符隔开，如"babad"，转化为"#b#a#b#a#d#"，同时为了减少数组访问越界的判断时间，还可以在首尾加上不同的其他符号，如转化为"!#b#a#b#a#d#@"，此外，由于只求最大子串，当主游标距离字符串末尾的长度小于历史回文子串长度，便可以结束了，在leetcode中，此步可以缩短很多运行时间。
*/

#include"biaozhun.h"
using namespace std;

string longestPalindrome(string s) {
	int len = s.length();
	if (len <= 1) return s;

	//预处理，使用分隔符‘#’，并首位加上‘!’和‘@’
	for (int i = 0; i <= len; i++) s.insert(i * 2, "#");
	s = '!' + s + '@';
	cout << s;

	//index记录回文子串初始位置，count记录子串长度（初始化为1的话会有可能导致index不能更新，从而错误输出）
	int j, index=0, count = 0;

	//当s.length()-i<count时，是无法得到比count更大的回文子串的，此处可以节省时间
	for (int i = 1; i < s.length() - count; i++) {

		cout << "index:" << index << "  count:" << count<<endl;

		//如果首位不添加‘!’和‘@’，此处要增加数组访问越界的判断
		//for (j = 1; i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]; j++);
		for (j = 1; s[i - j] == s[i + j]; j++);
		j--;
		//j记录当前回文子串长度，若比count大，更新count和index
		if (j > count) {
			count = j;
			index = i - j;
		}
	}
	
	//输出不含‘#’的子串
	string s1;
	for (int i = 0; i < count; i++) s1 += s[index + i * 2 + 1];
	return s1;
}

void main5() {
	string s = "ac";
	cout << longestPalindrome(s);


	cin.get();
}