#include <iostream>
using namespace std;
struct data {
    int val;
    int digit[3];   // digit[0]百位 digit[1]十位 digit[2]个位
};
// 提取一个三位数的百位、十位、个位
void getDigits(struct data& d) {
    d.digit[0] = d.val / 100;         // 百位
    d.digit[1] = (d.val / 10) % 10;   // 十位
    d.digit[2] = d.val % 10;          // 个位
}
// 检查 first、first*2、first*3 是否恰好由 1~9 九个数字各一次组成
bool check(struct data first) {
    struct data second, third;
    second.val = first.val * 2;
    third.val = first.val * 3;
    getDigits(first);
    getDigits(second);
    getDigits(third);
    int cnt[10] = { 0 };                 // cnt[d] = 数字 d 出现次数
    struct data arr[3] = { first, second, third };
    for (int i = 0; i < 3; i++)        // 统计 9 个数字
        for (int j = 0; j < 3; j++)
            cnt[arr[i].digit[j]]++;
    if (cnt[0] != 0) return false;     // 不能出现 0
    for (int d = 1; d <= 9; d++)
        if (cnt[d] != 1) return false; // 1~9 必须各出现一次
    return true;
}
int main() {
    // 枚举第一个数 a：a*3 必须也是三位数，故 a <= 987/3 = 329
    for (int a = 123; a <= 329; a++) {
        struct data first;
        first.val = a;
        if (check(first))
            cout << a << " " << a * 2 << " " << a * 3 << endl;
    }
    return 0;
}