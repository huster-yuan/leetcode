/** https://leetcode-cn.com/problems/reverse-integer/
*��Ŀ��������ʵ��һ�� atoi ������ʹ���ܽ��ַ���ת������������������leetcode˵��
*ʾ��������: "   -42"
	  ���: -42

*˼·��ֻ��Ҫע��һ�����������������ˡ�
*/
#include<iostream>
using  namespace std;
int myAtoi(string s) {
	//i��Ϊ�α�
	int i = 0, a = 0;
	bool flag = false;

	//ȥ���ո�
	while (i < s.length() - 1 && s[i] == ' ') i++;

	//�жϵ�һ���ǿ��ַ�
	if (s[i] == '-' || s[i] == '+') {
		if (s[i] == '-') flag = true;
		i++;
	}

	//ȥ�������0
	i--;
	while (++i < s.length() && s[i] == '0');

	//�ۼ�
	while (i < s.length() && s[i] >= '0'&&s[i] <= '9') {
		if (a > INT_MAX / 10) {
			if (flag) return INT_MIN;
			else return INT_MAX;
		}
		//Խ���ж�
		if (a == INT_MAX / 10) {
			if (flag&&s[i] - '0' >= 8) return INT_MIN;
			if (!flag&&s[i] - '0' >= 7) return INT_MAX;
		}
		//����Ҫs[i]-'0'Ҫ����ǰ�棬������ܻ���ǰԽ��
		a = s[i] - '0' + a * 10;
		i++;
	}
	if (flag) return -a;
	else return a;
}