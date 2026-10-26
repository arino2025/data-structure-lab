#include<iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

LNode* Init(LinkList& L) {//初始化链表带头结点，第一个结点值为1
	LNode* s = new LNode;
	L->next = s;
	s->data = 1;
	s->next = NULL;
	return L;
}



LNode* Insert(LinkList& L, int x, int y) {//将元素y插入到x中
	LNode* p = L->next->next;
	LNode* s = new LNode;

	while (p != NULL && p->data != x) {
		p = p->next;
	}
	s->data = y;
	s->next = p->next;
	p->next = s;
	return L;
}

void Inquire(LinkList L, int x) {//查询x下个元素，x最后则输出0
	LNode* p = L->next->next;

	while (p->next != 0 && p->data != x) {
		p = p->next;
	}
	if (p->next == NULL) {
		cout << "0" << endl;
	}
	else {
		cout << p->data << endl;
	}
}

LNode* Delete(LinkList&L, int x){
	LNode* p = L->next->next;
	while (p->next != 0 && p->data != x) {
		p = p->next;
	}
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return L;
}

int main() {
	LinkList L;
	Init(L);
	int times;
	cin >> times;
	for (int i = 1; i <= times; i++) {
		int way;
		cin >> way;
		switch (way)
		{
		case 1:
			int x,y;
			cin >> x >> y;
			Insert(L,x, y);
			break;
		case 2:
			int m;
			cin >> m;
			Inquire(L,m);
			break;
		default:
			int z;
			cin >> z;
			Delete(L,z);
			break;
		}
	}
	return 0;
}