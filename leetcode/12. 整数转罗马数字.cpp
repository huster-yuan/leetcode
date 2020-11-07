/** 网址
*题目：
*示例：

*思路：
*/
#include"biaozhun.h"
using namespace std;

string intToRoman(int num) {
	if (num >= 4000) return "";
	string numStr;
	char ch[4][3] = { {'I', 'V', 'X'},{'X', 'L', 'C'},{'C', 'D', 'M'},{'M', ' ', ' '} };
	int m, k = 0;
	while (num > 0) {
		m = num % 10;
		k++;
		if (m != 0) numStr = getNS(m, ch[k][0], ch[k][1], ch[k][2]) + numStr;
		num = num / 10;
	}
	return numStr;
}

//a:1 b:5 c:10,将1-9表示成对应的罗马符号
string getNS(int m, char a, char b, char c) {
	string ns = "";
	switch (m) {
	case 1: case 2: case 3:
		ns.append(m, a);
		break;
	case 4:
		ns.append(1, a);
		ns.append(1, b);
		break;
	case 5:
		ns.append(1, b);
		break;
	case 6:case 7:case 8:
		ns.append(1, b);
		ns.append(m - 5, a);
		break;
	case 9:
		ns.append(1, a);
		ns.append(1, c);
		break;
	}
	return ns;
}