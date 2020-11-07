/** https://leetcode-cn.com/problems/palindrome-number/
*��Ŀ���ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
*ʾ����121     true
      -121    false ��Ϊ��������121-

*˼·���Ƚ�ǰһ�����ķ�ת���ͺ�һ�����Ƿ���ȼ��ɡ�
*/
#include"biaozhun.h"
using namespace std;
bool isPalindrome(int x) {
	if (x < 0) return false;
	if (x < 10) return true;

	//k��¼x��λ��
	int a, k = 0;
	int y = x;
	while (y > 0) {
		k++;
		y /= 10;
	}

	//y��¼x��ǰһ�����ֵķ�ת��
	for (int j = 1; j <= k / 2; j++) {
		y = y * 10 + x % 10;
		x /= 10;
	}

	//kΪ����ʱ��ȥ���м������
	if (k % 2 == 1) x /= 10;

	//ǰһ�����ֵķ�ת�����ں�һ��������˵���ǻ�����
	if (x == y) return true;
	else return false;
}