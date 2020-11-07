/** ��ַ
*��Ŀ��һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
      ������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
      ���ܹ��ж�������ͬ��·����
*ʾ����
      ����: m = 3, n = 2
      ���: 3
      ����:
      �����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
      1. ���� -> ���� -> ����
      2. ���� -> ���� -> ����
      3. ���� -> ���� -> ����

*˼·����̬�滮��״̬ת�Ʒ��� dp[i][j]=dp[i-1][j]+dp[i][j-1];
*/
#include"biaozhun.h"
using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n));
	for (int i = 0; i < m; i++) dp[i][0] = 1;
	for (int j = 1; j < n; j++) dp[0][j] = 1;
	for(int i=1;i<m;i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	return dp[m-1][n-1];
}

void main62() {


	cin.get();
}