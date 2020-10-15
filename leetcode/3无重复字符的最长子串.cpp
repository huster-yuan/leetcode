/** https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*��Ŀ������һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
*
*˼·��ʹ�������α������ƣ��������ڣ��������ַ������������е��ַ��ظ�ʱ�������α꣬�����жϴ�ʱ�Ӵ������Ƿ����ʷ���Ȼ�����
*/
#include"biaozhun.h"
using namespace std;
int lengthOfLongestSubstring(string s) {

	//index��ǰʱ���Ӵ��ĳ�ʼλ��
	int index = 0; 
	int pos;
	if (s.length() < 2) return s.length();

	//��ʷ��Ӵ�����
	int maxlen = 1;
	for (int j = 1; j < s.length(); j++) {
		//jΪ��ǰ�Ӵ���ĩβλ��
		//fand�������ش�indexλ�����ַ�s[j]��s�еĵ�һ��λ��
		pos = s.find(s[j], index);

		//pos<j ˵���뵱ǰ�Ӵ��е��ַ���ͬ�������α꣨����Ҫ�ж�maxlen������������������Ӵ��䳤��
		if (pos < j) index = pos + 1;
		else {
			//��ǰ�Ӵ���󣬱Ƚϵ�ǰ�Ӵ�������maxlen��С
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
