/** 网址
*题目：
*示例：

*思路：动态规划，思路大致与62题相同
*/
#include"biaozhun.h"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

	obstacleGrid[0][0] = (obstacleGrid[0][0] + 1) % 2;
	for (int i = 1; i < obstacleGrid.size(); i++) {
		if (obstacleGrid[i][0] == 0) obstacleGrid[i][0] = obstacleGrid[i-1][0];
		else obstacleGrid[i][0] = 0;
	}
	for (int j = 1; j < obstacleGrid[0].size(); j++) {
		if (obstacleGrid[0][j] == 0) obstacleGrid[0][j] = obstacleGrid[0][j-1];
		else obstacleGrid[0][j] = 0;
	}
	for (int i = 1; i < obstacleGrid.size(); i++) {
		for (int j = 1; j < obstacleGrid[0].size(); j++) {
			if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
			else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
		}
	}
	return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];

}

void main63() {


	cin.get();
}