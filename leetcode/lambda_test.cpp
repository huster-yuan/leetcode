/** https://blog.csdn.net/weixin_43055404/article/details/103299156
*lambda���ʽ�� [ capture ] ( params ) opt -> ret { body; };
 ����carpture�ǲ����б�params�ǲ�����opt��ѡ�ret���Ƿ���ֵ�����ͣ�body���Ǻ����ľ���ʵ�֡�
 1.�����б�������lambda���ʽ���Է����������е���Щ������
   [] :��ʾ�������κα���
   [=]����ʾ��ֵ������������ڱ��ʽ�����ɸñ����ĸ�����
   [&]����ʾ�����ò������
   [this]��ֵ���ݲ���ǰ��this
 2.params��ʾlambda�Ĳ���������{}�С�
 3.opt��ʾlambda��ѡ�����mutable: ����mutable ��[=]���Ըı�������ı�����������[&]�ɸı����õı���
 4.ret��ʾlambda�ķ���ֵ��Ҳ������ʾָ������ֵ��lambda���Զ��ƶϷ���ֵ������ֵ��ע�����ֻ�е�lambda�ı��ʽ����һ��return���ʱ���Զ��ƶϲ�����Ч�ġ�


*˼·��ֻ��Ҫע��һ�����������������ˡ�
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
	auto lambda2_f1 = [=]()mutable->int { return a+1; };  //��ֵ����a
	auto lambda2_f2 = [&]()mutable->int { return a+1; };  //�����ò���a

 	lambda2_f1();  // ���� 6
	lambda2_f2();  // ���� 6
	a++;
	lambda2_f1();  // ���� 6
	lambda2_f2();  // ���� 7

	return a;
}

void main_lambda() {
	lambda2();
	cin.get();
}