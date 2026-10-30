#include<iostream>
using namespace std;
typedef struct LNode{
	int data;
	struct LNode* next;

}LNode,*LinkStack;//定义链式栈

bool InitStack(LinkStack& S) {
	S = new LNode;
	if (S == NULL)return false;
	S->next = NULL;
	return true;

}//初始化

bool StackEmpty(LinkStack S) {
	if (S->next == NULL)
		return true;
	return false;
}//判空

bool Push(LinkStack& S, int x) {
	LNode* s = new struct LNode;
	if (s == NULL)
		return false;
	s->data = x;
	s->next = S->next;
	S->next = s;
	return true;

}//入栈，头插法

bool Pop(LinkStack& S, int& x) {
	if (S->next == NULL)return false;
	LNode* p = S->next;
	x = p->data;
	S->next = p->next;
	delete p;
	return true;

}//出栈


bool GetTop(LinkStack S,int &x) {
	if (S == NULL)return false;
	x = S->next->data;
	return true;
}//读取栈顶元素

void DestroyStack(LinkStack& S) {
	LNode* p = S->next;
	while (p != NULL) {
		LNode* q = p;
		p = p->next;
		delete q;

	}
	delete S;
	S = NULL;
}//销毁整个栈

int main() {
	LinkStack S;
	InitStack(S);

	Push(S, 1);                 // 栈：1
	Push(S, 2);                 // 栈：1 2
	Push(S, 3);                 // 栈：3 2 1

	int e;
	GetTop(S, e);
	cout << "栈顶: " << e << endl;    // 3
	Pop(S, e); cout << "弹出: " << e << endl;   // 3
	Pop(S, e); cout << "弹出: " << e << endl;   // 2
	return 0;
}