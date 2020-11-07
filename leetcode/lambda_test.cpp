/** https://blog.csdn.net/weixin_43055404/article/details/103299156
*lambda表达式： [ capture ] ( params ) opt -> ret { body; };
 其中carpture是捕获列表，params是参数，opt是选项，ret则是返回值的类型，body则是函数的具体实现。
 1.捕获列表描述了lambda表达式可以访问上下文中的哪些变量。
   [] :表示不捕获任何变量
   [=]：表示按值捕获变量，并在表达式内生成该变量的副本。
   [&]：表示按引用捕获变量
   [this]：值传递捕获当前的this
 2.params表示lambda的参数，用在{}中。
 3.opt表示lambda的选项，例如mutable: 加上mutable 若[=]可以改变所捕获的变量副本，若[&]可改变引用的变量
 4.ret表示lambda的返回值，也可以显示指明返回值，lambda会自动推断返回值，但是值得注意的是只有当lambda的表达式仅有一条return语句时，自动推断才是有效的。


*思路：只需要注意一下数字溢出问题就行了。
*/

#include"biaozhun.h"
using namespace std;

bool f(int a) {
	return a % 7 == 0 ;
}

int lambda1() {
	vector<int> vec(10);
	generate(vec.begin(), vec.end(), rand);

	//int m = count_if(vec.begin(), vec.end(), f);
	//int m = count_if(vec.begin(), vec.end(), [](int a) {return a % 7 == 0; });
	auto lambda_f = [](int x) { return x % 7 == 0; };
	int m = count_if(vec.begin(), vec.end(), lambda_f);
	return m;
}

int lambda2() {
	int a = 5;
	auto lambda2_f1 = [=]()mutable->int { return a+1; };  //按值捕获a
	auto lambda2_f2 = [&]()mutable->int { return a+1; };  //按引用捕获a

 	lambda2_f1();  // 返回 6
	lambda2_f2();  // 返回 6
	a++;
	lambda2_f1();  // 返回 6
	lambda2_f2();  // 返回 7

	return a;
}

void main_lambda() {
	lambda2();
	cin.get();
}