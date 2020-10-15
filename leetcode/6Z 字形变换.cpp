/** https://leetcode-cn.com/problems/zigzag-conversion/
��Ŀ����һ�������ַ������ݸ������������Դ������¡������ҽ��� Z �������С��������վ

˼·������ѧ���ɣ�ÿk = numRows * 2 - 2�ظ�һ���µ�Z���Σ����ֻ��Ҫ��һ��Z���ν����ж���ĸ�ķֲ������õ���Ŀ���ҵĵ�һ�뷨�Ƕ��ַ�������������������Ҫ��Ƕ����numRows�ı����������ܶࡣ������numRows��Ϊ��ѭ���Ļ�������һ�δ��ַ�����ȡ�����е������ַ���
*/

#include"biaozhun.h"
using namespace std;

string convert(string s, int numRows) {
	if (numRows <= 1) return s;
	string s1;

	//ÿk = numRows * 2 - 2�ظ�һ���µ�Z���Σ���Ϊһ��numRows�е�Z���Σ���k����ĸ��ɣ�
	int k = numRows * 2 - 2;
	int j;
	for (int i = 0; i < numRows; i++) {
		j = i;
		while (j < s.size()) {
			//��������һ�У�һ��Z���������ٰ���һ����ĸ
			s1 += s[j];

			//������β����������������ĸ�������Ҫ������һ����������ѧ���ɣ���ͬʱ��Ҫ��ֹ�������Խ��
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