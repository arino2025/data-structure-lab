#include <iostream>
using namespace std;
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, * LinkList;   // LinkList = struct LNode*
// 初始化链表（带头结点）
bool InitList(LinkList& L) {
    L = new LNode;
    L->next = NULL;
    return true;
}
// 求表长（带头结点，不含头结点）
int Length(LinkList L) {
    int len = 0;
    LNode* p = L;
    while (p->next != NULL) {
        p = p->next;   // 修正：指针后移，而非 p->next = p
        len++;
    }
    return len;
}
// 按序号查找：返回第 i 个结点（i 从 1 开始），不存在返回 NULL
LNode* GetNode(LinkList L, int i) {
    if (i < 1)
        return NULL;
    int j = 1;
    LNode* p = L->next;         // 指向第 1 个结点
    while (p != NULL && j < i) { // 后移 i-1 次
        p = p->next;
        j++;
    }
    return p;
}
// 按值查找：返回第一个值为 k 的结点，不存在返回 NULL
LNode* LocateNode(LinkList L, int k) {
    LNode* p = L->next;
    while (p != NULL && p->data != k) {
        p = p->next;
    }
    return p;
}
// 插入：将值为 e 的结点插入到第 i 个位置
bool ListInsert(LinkList& L, int i, int e) {
    if (i < 1)
        return false;           // 修正：i 必须 >= 1
    LNode* p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode* s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 删除：删除第 i 个结点，用 e 返回其值
bool ListDelete(LinkList& L, int i, int& e) {
    if (i < 1)
        return false;           // 修正：i 必须 >= 1
    LNode* p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL)        // 修正：判断 p->next，而非 p
        return false;
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    delete q;
    return true;
}
// 头插法建立单链表（带头结点，输入以 9999 结束）
LinkList List_HeadInsert(LinkList& L) {
    L = new LNode;              // 修正：使用形参 L，不再重复声明
    LNode* s;
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
// 尾插法建立单链表（带头结点，输入以 9999 结束）
LinkList List_TailInsert(LinkList& L) {
    L = new LNode;              // 修正：使用形参 L
    int x;
    LNode* s, * r = L;          // r 指向表尾
    L->next = NULL;
    cin >> x;
    while (x != 9999) {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;                  // 修正：r 后移指向新表尾
        cin >> x;
    }
    r->next = NULL;
    return L;
}
// 打印链表（测试辅助）
void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
// 简单测试（注释掉输入部分，按需运行）
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