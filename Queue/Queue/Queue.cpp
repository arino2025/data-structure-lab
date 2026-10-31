#define MaxSize 10
#include<iostream>
using namespace std;
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;//定义队列的顺序结构

void InitQueue(SqQueue &Q) {
	Q.front = Q.rear = 0;
}//初始化

bool QueueEmpty(SqQueue Q) {
	if (Q.front == Q.rear)
		return true;
	return false;
}//判空

bool QueueFull(SqQueue Q) {
	if ((Q.rear + 1) % MaxSize == Q.front)//if ((Q.front + 1) % MaxSize == Q.rear)这样写是表示判空
		return true;
	return false;
}//判满

bool EnQueue(SqQueue& Q,int x) {
	if (QueueFull(Q))return false;
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	return true;
}//入队

bool DeQueue(SqQueue& Q, int& x) {
	if (QueueEmpty(Q))return false;
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}//出队

int QueueLength(SqQueue Q) {
	return (Q.rear + MaxSize - Q.front) % MaxSize;
}//读取长度
int main() {
	// 循环队列测试
	SqQueue QQ;
	InitQueue(QQ);
	EnQueue(QQ, 1); 
	EnQueue(QQ, 2); 
	EnQueue(QQ, 3);
	int e;
	DeQueue(QQ, e); cout << "出队: " << e << endl;      // 1
	DeQueue(QQ, e); cout << "出队: " << e << endl;      // 2
	cout << "长度: " << QueueLength(QQ) << endl;        // 1

}