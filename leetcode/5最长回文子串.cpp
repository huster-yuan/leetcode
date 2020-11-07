/** https://leetcode-cn.com/problems/longest-palindromic-substring/
*��Ŀ������һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��
*ʾ��������: "babad"
      ���: "bab"
      ע��: "aba" Ҳ��һ����Ч�𰸡�
*
*˼·��ʹ�õ���Manacher�㷨˼�룬ʹ�ø����ָ�����#�����ַ���������"babad"��ת��Ϊ"#b#a#b#a#d#"��ͬʱΪ�˼����������Խ����ж�ʱ�䣬����������β���ϲ�ͬ���������ţ���ת��Ϊ"!#b#a#b#a#d#@"�����⣬����ֻ������Ӵ��������α�����ַ���ĩβ�ĳ���С����ʷ�����Ӵ����ȣ�����Խ����ˣ���leetcode�У��˲��������̺ܶ�����ʱ�䡣
*/

#include"biaozhun.h"
using namespace std;

string longestPalindrome(string s) {
	int len = s.length();
	if (len <= 1) return s;

	//Ԥ����ʹ�÷ָ�����#��������λ���ϡ�!���͡�@��
	for (int i = 0; i <= len; i++) s.insert(i * 2, "#");
	s = '!' + s + '@';
	cout << s;

	//index��¼�����Ӵ���ʼλ�ã�count��¼�Ӵ����ȣ���ʼ��Ϊ1�Ļ����п��ܵ���index���ܸ��£��Ӷ����������
	int j, index=0, count = 0;

	//��s.length()-i<countʱ�����޷��õ���count����Ļ����Ӵ��ģ��˴����Խ�ʡʱ��
	for (int i = 1; i < s.length() - count; i++) {

		cout << "index:" << index << "  count:" << count<<endl;

		//�����λ����ӡ�!���͡�@�����˴�Ҫ�����������Խ����ж�
		//for (j = 1; i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]; j++);
		for (j = 1; s[i - j] == s[i + j]; j++);
		j--;
		//j��¼��ǰ�����Ӵ����ȣ�����count�󣬸���count��index
		if (j > count) {
			count = j;
			index = i - j;
		}
	}
	
	//���������#�����Ӵ�
	string s1;
	for (int i = 0; i < count; i++) s1 += s[index + i * 2 + 1];
	return s1;
}

void main5() {
	string s = "ac";
	cout << longestPalindrome(s);


	cin.get();
}