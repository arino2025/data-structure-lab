#include<iostream>
using namespace std;


typedef struct LinkNode {
	int data;
	struct LinkNode* next;
}LinkNode;

typedef struct {
	LinkNode* front;//头指针
	LinkNode* rear;//尾指针
}LinkQueue;

void InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new LinkNode;
	Q.front->next = NULL;
}//初始化

bool QueueEmpty(LinkQueue Q) {
	return Q.front == Q.rear;
}//判空

bool EnQueue(LinkQueue& Q, int x) {
	LinkNode* s = new LinkNode;
	if (s == NULL)return false;
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	return true;
}//入队

bool DeQueue(LinkQueue&Q,int &x){
	if (QueueEmpty(Q))return false;//先判空
	LinkNode* p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;//如果Q.rear == p也就是删完后变空，需要将rear指向front表空
	delete p;
	return true;
}//出队

bool GetQueue(LinkQueue Q, int& x) {
	if (QueueEmpty(Q))return false;
	x = Q.front->next->data;
	return true;
}//读取队列首元素

int main() {
	// 链队列测试
	int x;
	LinkQueue LQ;
	InitQueue(LQ);
	EnQueue(LQ, 1); EnQueue(LQ, 2); EnQueue(LQ, 3);
	DeQueue(LQ, x); cout << "链队出队: " << x << endl;   // 1
	DeQueue(LQ, x); cout << "链队出队: " <<x << endl;   // 2
	cout << (QueueEmpty(LQ) ? "空" : "非空") << endl;    // 非空
	return 0;
}