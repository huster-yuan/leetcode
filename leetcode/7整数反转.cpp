/** https://leetcode-cn.com/problems/reverse-integer/
*题目：给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
      注意: 假设我们的环境只能存储得下32位的有符号整数，则其数值范围为 [−2^31, 2^31−1]。请根据这个假设，如果反转后整数溢出那么就返回0。
*示例：输入: -123
	  输出: -321

*思路：只需要注意一下数字溢出问题就行了。
*/
#include"biaozhun.h"
using namespace std;

int reverse_n(int x) {
	int a, y = 0;
	bool flag = false;
	if (x < 0) flag = true;
	x = abs(x);

	//MAX_INT pow(2, 31)=2 147 483 648
	long int MAX_INT = pow(2, 31);
	while (x > 0) {
		a = x % 10;
		if (y > MAX_INT / 10) return 0;
		if (y == MAX_INT / 10 && a >= 8) return 0;
		y = y * 10 + a;
		x = x / 10;
	}
	if (flag) y = -y;
	return y;
}