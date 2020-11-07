/** https://leetcode-cn.com/problems/reverse-integer/
*题目：请你来实现一个 atoi 函数，使其能将字符串转换成整数。具体规则间leetcode说明
*示例：输入: "   -42"
	  输出: -42

*思路：只需要注意一下数字溢出问题就行了。
*/
#include<iostream>
using  namespace std;
int myAtoi(string s) {
	//i作为游标
	int i = 0, a = 0;
	bool flag = false;

	//去掉空格
	while (i < s.length() - 1 && s[i] == ' ') i++;

	//判断第一个非空字符
	if (s[i] == '-' || s[i] == '+') {
		if (s[i] == '-') flag = true;
		i++;
	}

	//去掉多余的0
	i--;
	while (++i < s.length() && s[i] == '0');

	//累加
	while (i < s.length() && s[i] >= '0'&&s[i] <= '9') {
		if (a > INT_MAX / 10) {
			if (flag) return INT_MIN;
			else return INT_MAX;
		}
		//越界判断
		if (a == INT_MAX / 10) {
			if (flag&&s[i] - '0' >= 8) return INT_MIN;
			if (!flag&&s[i] - '0' >= 7) return INT_MAX;
		}
		//这里要s[i]-'0'要放在前面，否则可能会提前越界
		a = s[i] - '0' + a * 10;
		i++;
	}
	if (flag) return -a;
	else return a;
}