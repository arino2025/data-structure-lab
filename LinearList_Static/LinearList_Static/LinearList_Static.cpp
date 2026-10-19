#define MaxSize 10
#include<iostream>
using namespace std;
typedef struct {
	int data[MaxSize];
	int length;
}List;
void InitList(List&L) {//实现初始化功能
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
	}
	L.length = 0;
}
bool ListInsert(List& L, int i, int e) {//实现第i位插入e元素，返回值为函数是否运行
	if (i<1 || i>L.length+1) {
		return false;
	}
	if (L.length >= MaxSize) {
		return false;
	}
	for (int k =L.length; k>=i; k--) {
		L.data[k] = L.data[k-1];
	}
	L.length++;
	L.data[i-1] = e;
	return true;
}

bool ListDelete(List& L, int i, int&e) {//实现删除第i位元素，并提示删除的元素，返回值为函数是否运行
	if (i<1 || i>L.length) {
		return false;
	}
	if (L.length <=0) {
		return false;
	}
	e = L.data[i - 1];
	for (int k = i; k < L.length; k++) {
		L.data[k - 1] = L.data[k];
	}
	L.length--;
	return true;
}

int Locate(List& L, int e) {//实现按值查找，返回值表示为第i位
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i+1;
		}
	}
	return 0;
}

int Get(List& L, int i) {//实现按位查找，返回值位第i位的元素
	if (i<1 || i>L.length)
		return -1;
	return L.data[i - 1];
}

void print(List L) {
	for (int k = 0; k < L.length; k++) {
		cout << L.data[k] << " ";
	}
	cout << "The number of this list is" <<  L.length << endl;
}

int main() {
	List L;
	InitList(L);
	//测试用例
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 4);
	ListInsert(L, 4, 4);//插入1，2，4,4
	print(L);
	ListInsert(L, 3, 3);
	print(L);
	int e = 0;
	ListDelete(L, 4, e);
	Locate(L, 3);
	Get(L, 3);

	return 0;

}

//源代码三处错误，以上为修改过的
//1.bool ListInsert(List& L, int i, int e) {//实现第i位插入e元素，返回值为函数是否运行
//if (i<1 || i>MaxSize) {
//	return false;
//}
//if (L.length >= MaxSize) {
//	return false;
//}
//for (int k = L.length; k >= i; k--) {
//	L.data[k + 1] = L.data[k];
//}
//L.length++;
//L.data[i] = e;
//return true;
//}**ListInsert 移动逻辑错：应把 data[k-1]移到 data[k],且位置检查应为 i > L.length+1


//2.bool ListDelete(List & L, int i, int& e) {//实现删除第i位元素，并提示删除的元素，返回值为函数是否运行
//	if (i<1 || i>MaxSize) {
//		return false;
//	}
//	if (L.length <= 0) {
//		return false;
//	}
//	e = L.data[i - 1];
//	for (int k = i; i < L.length; k++) {
//		L.data[k - 1] = L.data[k];
//	}
//	L.length--;
//	return true;
//}ListDelete  i < L.length 死循环

//3.int Locate(List& L, int e) {//实现按值查找，返回值表示为第i位
//	for (int i = 0; i < L.length; i++) {
//		if (L.data[i] == e) {
//			return i;
//		}
//	}
//	return 0;
//}Locate 查不到时无返回值