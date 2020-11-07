/** https://leetcode-cn.com/problems/palindrome-number/
*题目：判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*示例：121     true
      -121    false 因为反过来是121-

*思路：比较前一半数的反转数和后一半数是否相等即可。
*/
#include"biaozhun.h"
using namespace std;
bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x < 10) return true;

	//k记录x的位数
	int a, k = 0;
	int y = x;
	while (y > 0) {
		k++;
		y /= 10;
	}

	//y记录x的前一半数字的反转数
	for (int j = 1; j <= k / 2; j++) {
		y = y * 10 + x % 10;
		x /= 10;
	}

	//k为奇数时，去掉中间的数字
	if (k % 2 == 1) x /= 10;

	//前一半数字的反转数等于后一半数，则说明是回文数
	if (x == y) return true;
	else return false;
}