#define MaxSize 10
#include<iostream>
using namespace std;
typedef struct {
	int data[MaxSize];
	int top;
}SqStack;//定义一个顺序结构的栈

void InitStack(SqStack& s) {
	s.top = -1;
};//初始化一个栈

bool StackEmpty(SqStack s) {
	if (s.top == 1)
		return true;
	return false;
}//判断是否栈空

bool Push(SqStack& s, int &x) {
	if (s.top == MaxSize - 1)
		return false;//栈满
	s.data[++s.top] = x;
	return true;

}//入栈

bool Pop(SqStack& s, int& x) {
	if (s.top == -1)
		return false;//空栈
	x = s.data[s.top--];
	return true;
}//出栈

bool GetTop(SqStack s, int& x) {
	if (s.top == -1)
		return false;
	x = s.data[s.top];
	return true;
}//读取栈顶元素

typedef struct {
	int data[MaxSize];
	int top0;
	int top1;
}ShStack;//共享栈

void InitShStack(ShStack& s) {
	s.top0 = -1;
	s.top1 = MaxSize;

}//初始化共享栈

bool StackFull(ShStack s) {
	if (s.top0 + 1 == s.top1)
		return true;
	return false;
}//判断栈满
