#include <iostream>
using namespace std;

#define MaxSize 10
typedef int ElemType;

// 静态链表类型：SLinkList 是一个"长度为 MaxSize 的数组类型"
typedef struct {
    ElemType data;      // 数据域
    int next;           // 游标：存下一个结点的下标（不是地址！）
} SLinkList[MaxSize];

// ① 初始化：把所有结点串成"备用链表"（空闲结点池）
void InitSLinkList(SLinkList& a) {
    for (int i = 0; i < MaxSize - 1; i++)
        a[i].next = i + 1;        // 每个结点指向下一个
    a[MaxSize - 1].next = -1;     // 最后一个结点是表尾
}

// ② 申请空闲结点：从备用链头部取一个结点，返回其下标
int MallocNode(SLinkList& a) {
    int p = a[0].next;            // a[0].next 指向第一个空闲结点
    if (p != -1)                  // 有空闲才取
        a[0].next = a[p].next;    // 把该结点从备用链中摘下
    return p;                     // 返回下标；-1 表示没有空闲结点
}

// ③ 释放结点：把结点下标 p 插回备用链表头部
void FreeNode(SLinkList& a, int p) {
    a[p].next = a[0].next;        // 结点 p 指向原第一个空闲结点
    a[0].next = p;                // p 成为新的第一个空闲结点
}

// ④ 建立带头结点的链表：申请一个结点做头结点（哨兵）
int CreateList(SLinkList& a) {
    int head = MallocNode(a);     // 头结点下标
    a[head].next = -1;            // 空表：头结点的 next 为 -1
    return head;
}

// ⑤ 按位插入：在第 i 位插入 e（i 从 1 开始）
bool ListInsert(SLinkList& a, int head, int i, ElemType e) {
    if (i < 1) return false;
    int p = head;                 // 从头结点开始
    int j = 0;
    while (j < i - 1 && a[p].next != -1) {   // 找第 i-1 个结点
        p = a[p].next;
        j++;
    }
    if (j != i - 1) return false;             // 越界
    int s = MallocNode(a);                    // 申请新结点
    if (s == -1) return false;                // 没有空闲结点
    a[s].data = e;
    a[s].next = a[p].next;                    // 新结点指向 p 的后继
    a[p].next = s;                            // p 指向新结点
    return true;
}

// ⑥ 按位删除：删除第 i 个结点，e 带回
bool ListDelete(SLinkList& a, int head, int i, ElemType& e) {
    if (i < 1) return false;
    int p = head;
    int j = 0;
    while (j < i - 1 && a[p].next != -1) {    // 找第 i-1 个结点
        p = a[p].next;
        j++;
    }
    if (j != i - 1 || a[p].next == -1) return false;
    int q = a[p].next;                        // q 是待删结点下标
    e = a[q].data;
    a[p].next = a[q].next;                    // p 跳过 q
    FreeNode(a, q);                           // q 还回备用链
    return true;
}

// ⑦ 按值查找：返回下标，查无返回 -1
int LocateElem(SLinkList& a, int head, ElemType e) {
    int p = a[head].next;
    while (p != -1) {
        if (a[p].data == e) return p;
        p = a[p].next;
    }
    return -1;
}

// ⑧ 遍历打印
void Print(SLinkList& a, int head) {
    int p = a[head].next;          // 第一个数据结点
    while (p != -1) {
        cout << a[p].data << " ";
        p = a[p].next;
    }
    cout << endl;
}

int main() {
    SLinkList a;                   // 数组 a：10 个静态结点
    InitSLinkList(a);
    int head = CreateList(a);      // 头结点

    ListInsert(a, head, 1, 1);
    ListInsert(a, head, 2, 2);
    ListInsert(a, head, 3, 3);
    Print(a, head);                // 1 2 3

    ElemType e = 0;
    ListDelete(a, head, 2, e);     // 删第 2 位
    cout << "删除: " << e << endl;  // 2
    Print(a, head);                // 1 3
    return 0;
}
