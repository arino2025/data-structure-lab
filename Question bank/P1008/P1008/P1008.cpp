
#include<iostream>

using namespace std;

struct data {
	int val;
	int digit[3];
};

struct data generate() {//生成第一个数字
	struct data first;
	for (int i = 1; i <= 3; i++) {
		first.val = 100 * i;
		first.digit[0] = i;//定义百位
		for (int j = 1; j != i && j <= 9; j++) {
			first.val +=10*j;
			first.digit[1] = j;//定义十位
			for (int k = 1; k != i && j <= 9 && k != j; k++) {
				first.val +=k;
				first.digit[2] = k;//定义个位
			}
		}
	}
	return first;
}


bool check(struct data first){//检查三个数字中有无位数上的数字相同
	struct data second, third;
	second.val = first.val * 2;
	second.digit[0] = second.val % 100;
	second.digit[1] = (second.val- second.digit[0]*100) % 10;
	second.digit[2] = second.val - second.digit[0] * 100- second.digit[1] * 10;//第二个数字
	for (int i = 0; i <= 2; i++) {
		if (first.digit[i] == second.digit[i]) {
			return false;
		}
	}//判断第一个和第二个
	third.val = first.val * 3;
	third.digit[0] = third.val % 100;
	third.digit[1] = (third.val - third.digit[0] * 100) % 10;
	third.digit[2] = third.val - third.digit[0] * 100 - third.digit[1] * 10;//第三个数字
	for (int i = 0; i <= 2; i++) {
		if (first.digit[i] == third.digit[i]|| second.digit[i] == third.digit[i]) {
			return false;
		}
	}//判断第三个数字和前两个
	return true;
	
}

int main() {
	struct data first;
	first=generate();
	if (check(first)) {
		cout << first.val << " " << first.val * 2 << " " << first.val * 3 << endl;
	}
	return 0;
	
}
//这道题你的代码结构和核心逻辑都出了问题：generate 根本不是在枚举，check 的取位全部算错，main 也只判断了一次。我先逐条指出，再给两个版本：一个保留你的 struct 骨架改对（即“在你的源代码上修改”），一个是最简洁的推荐写法。
//你的代码问题清单
//1. generate 不会“枚举”，只返回最后一次循环的残留值
//cpp
//自动换行
//复制
//struct data generate() {
//	struct data first;
//	for (int i = 1; i <= 3; i++) { ... }
//	return first;   // ❌ 三层循环都写进同一个 first，最后只返回一个被覆盖得乱七八糟的值
//}
//题目要找出所有满足条件的三位数，而你只生成了一个 first 就返回。枚举应该用循环遍历第一个数，或者把每个候选交给 check 判断。
//2. 循环条件把“跳过”写成了“终止”
//cpp
//自动换行
//复制
//for (int j = 1; j != i && j <= 9; j++) {          // ❌ 当 j 碰到 i 时整个循环结束
//	for (int k = 1; k != i && j <= 9 && k != j; k++)  // ❌ 同理
//		你想表达“j 不等于 i”，但 j != i 放在循环条件里，一旦 j == i 循环就直接停止，而不是跳过这次。要跳过应该写 if (j == i) continue; 。而且 i 从 1 开始时，j 一上来就 == i，循环体一次都不执行。
//		3. first.val 累加逻辑错误
//		cpp
//		自动换行
//		复制
//		first.val = 100 * i;    // 外层每次重置
//	first.val += 10 * j;    // ❌ 内层反复累加，且多个 j/k 叠在一起
//	first.val += k;
//	正确拼三位数应该是 100 * i + 10 * j + k，而不是反复 += 。
//		4. check 里取位全部算错
//		cpp
//		自动换行
//		复制
//		second.digit[0] = second.val % 100;   // ❌ 这是“后两位”，不是百位
//	second.digit[1] = (second.val - second.digit[0] * 100) % 10;  // ❌ 全是错的
//	second.digit[2] = ...
//		取位公式应为：
//		• 百位 = val / 100
//		• 十位 = (val / 10) % 10
//		• 个位 = val % 10
//		你的写法后面两行还会算出负数。
//		5. check 只比较“同一位”，且没查 0、没查重复
//		cpp
//		自动换行
//		复制
//		if (first.digit[i] == second.digit[i])  // ❌ 只比百位对百位、十位对十位……
//			题目要求三个数的全部 9 个数字恰好是 1~9 各出现一次。正确做法是统计每个数字 1~9 的出现次数，全部等于 1，且数字 0 一次都不能出现。同位置比较没有任何意义。
//			6. main 只生成一次、只判断一次
//			cpp
//			自动换行
//			复制
//			first = generate();
//	if (check(first)) { ... }   // ❌ 没有遍历所有可能的 first
//	7. 枚举范围
//		第一个数 a 满足 a * 3 也是三位数，所以 a ≤ 987 / 3 = 329，从 123 枚举到 329 即可。