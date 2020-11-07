/** 网址
*题目：
*示例：

*思路：
*/
#include"biaozhun.h"
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> mat(m, vector<int>(n));
	for (int j = 0; j < n; j++) {
		if (matrix[0][j] == '0') mat[0][j] = 0;
		else mat[0][j] = 1;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == '0') mat[i][j] = 0;
			else mat[i][j] += mat[i][j - 1];
			int a = 0;
		}
	}

	return 0;
}
void main85() {


	cin.get();
}
