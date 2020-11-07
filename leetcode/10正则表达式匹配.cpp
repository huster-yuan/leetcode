/** https://leetcode-cn.com/problems/regular-expression-matching/
*题目：给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
     '.' 匹配任意单个字符
     '*' 匹配零个或多个前面的那一个元素

*思路：主要在于要把*和前面一个字符看成一个整体，如‘a*’，可用动态规划处理
*/
#include"biaozhun.h"
using namespace std;

bool isMatch2(string s, string p) {
	int m = s.length();
	int n = p.length();
	vector<vector<bool>>dp(m + 1, vector<bool>(n + 1));

	//初始状态
	dp[0][0] = true;

	//这里是为了保证当p为“符号+星号”的组合，如p="a*b*c***"，仍然可以和s=""匹配，因为后面的循环是从1开始的。
	for (int j = 2; j < n + 1; j = j + 2) {
		if (p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
	}
	//迭代，详见 https://leetcode-cn.com/problems/regular-expression-matching/solution/shou-hui-tu-jie-wo-tai-nan-liao-by-hyj8/
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (p[j - 1] != '*') {
				if (p[j-1] == s[i-1] || p[j-1] == '.') dp[i][j] = dp[i - 1][j - 1];
				else dp[i][j] = false;
			} 
			else{
				//保证p的第一个字母为星号时数组不越界
				if (j < 2) dp[i][j] = false;
				else {
					if (p[j - 2] == s[i - 1] || p[j - 2] == '.') dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
					else dp[i][j] = dp[i][j - 2];
				}
				
			}
		}
	}
	return dp[m][n];

}
void main10() {
	cout<<isMatch2("hcabbbd", "hc*a.*d");

	cin.get();
}