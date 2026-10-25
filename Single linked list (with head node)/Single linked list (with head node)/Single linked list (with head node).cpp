#include<iostream>
using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;//重命名为LNode，Linklist=struct LNode*

 //初始化链表
bool InitList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return true;
}

//求表长操作
int Length(LinkList L) {
	int length=0;
	LNode* p = L;
	while (p->next != NULL) {
		p->next = p;
		length++;
	}
	return length;
}

//按序查找结点
LNode* GetNode(LinkList L, int i) {
	LNode* p = L->next;
	for (int k = 0; k < i; k++) {
		p=p->next ;
	}
	return p;
}

//按值查找结点
LNode* LocateNode(LinkList L, int k) {
	LNode* p = L->next;
	while (p->data != k) {
		p = p->next;
	}
	return p;
}

//插入节点操作,将值为x的结点插入到链表的第i个位置
bool ListInsert(LinkList& L, int i, int e) {
	LNode* p = L;//p结点用作遍历
	int j = 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* s = new LNode; //实际插入的是s结点
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//删除节点操作，将第i个结点删除
bool ListDelete(LinkList& L, int i, int& e) {
	LNode* p = L;
	int j = 0;
	while (p->next!=NULL&& j < i - 1) {
		p = p->next;
		j++;
	}
	if (p==NULL) {
		return false;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	delete q;
	return true;
}

//头插法建立单链表
LinkList List_HeadInsert(LinkList& L) {
	LNode* L = new LNode;
	LNode* s;//插入结点为s
	int x;
	L->next = NULL;
	cin >> x;
	while (x != 9999) {
		s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
	return L;
}

//尾插法建立单链表
LinkList List_TailInsert(LinkList& L) {
	LNode* L = new LNode;
	int x;
	LNode* s=NULL, * r = L;//s做实际插入结点，r做遍历结点
	L->next = NULL;
	cin >> x;
	while (x != 9999) {
		s = new LNode;
		s->data = x;
		s->next = r->next;
		r->next = s;
		cin >> x;
	}
	r->next = NULL;
	return L;
}
//打印链表
void PrintList(LinkList L) {
	LNode* p = L->next;
	while (p != NULL) {
		cout << p->data << "-";
		p = p->next;
	}
	cout << endl;
}

// 输入示例：1 2 3 4 5 9999
int main() {
	LinkList L;
	InitList(L);
	cout << "尾插法建表，输入 1 2 3 4 5 9999：" << endl;
	List_TailInsert(L);
	cout << "长度 = " << Length(L) << endl;
	PrintList(L);
	ListInsert(L, 3, 100);       // 在第 3 位插入 100
	cout << "插入 100 到第 3 位后：";
	PrintList(L);
	int e;
	ListDelete(L, 2, e);         // 删除第 2 个结点
	cout << "删除第 2 个结点（值=" << e << "）后：";
	PrintList(L);
	LNode* p = GetNode(L, 3);
	if (p) cout << "第 3 个结点值 = " << p->data << endl;
	p = LocateNode(L, 4);
	if (p) cout << "值为 4 的结点存在" << endl;
	else   cout << "未找到值为 4 的结点" << endl;
	return 0;
}