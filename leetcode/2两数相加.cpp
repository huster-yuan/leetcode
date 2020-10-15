/** https://leetcode-cn.com/problems/add-two-numbers/
*
题目：给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
     如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
     您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

	 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
     输出：7 -> 0 -> 8
     原因：342 + 465 = 807

思路：使用一个进位符，简单地进行对应位数相加，简单粗暴。
*/
#include"biaozhun.h"
using namespace std;

//结构体，节点的数据结构
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int a = 0;  //进位符
	ListNode *l = new ListNode();
	ListNode *head = l;
	while (l1 != NULL || l2 != NULL || a != 0) {
		if (l1 != NULL) {
			a += l1->val;
			l1 = l1->next;
		}
		if (l2 != NULL) {
			a += l2->val;
			l2 = l2->next;
		}
		l->next = new ListNode(a % 10);
		l = l->next;
		a /= 10;
	}
	l = head;
	head = head->next;
	delete l;
	return head;
}
void main2() {


	int a; cin >> a;
}