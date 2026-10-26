#include<iostream>
using namespace std;
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinkList;

//双链表初始化
bool Init(DLinkList& L) {
	L = new DNode;
	L->prior = NULL;
	L->next = NULL;
	return true;
}
//双链表的插入操作(在p点之后）
bool DList_Insert(DNode*p,int e) {
	if (p == NULL)
		return false;
	DNode* s = new DNode;
	if (s == NULL)
		return false;
	s->data = e;
	s->next = p->next;
	if(p->next!=NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}
//双链表的删除操作（删除p的后继结点q）
bool DList_Delete(DNode* p) {
	if (p == NULL)
		return false;
	DNode* q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}
//销毁链表
void DestroyList(DLinkList& L) {
	while (L->next != NULL) {
		DList_Delete(L);
	}
	free(L);// 此时L仍指向链表的首地址
	L = NULL;
}
int main() {
	return 0;
}