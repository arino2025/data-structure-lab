#include <iostream>
using namespace std;
// 判断 a、2a、3a 三个三位数是否恰好由 1~9 九个数字各一次组成
bool check(int a) {
    int b = a * 2, c = a * 3;
    int cnt[10] = { 0 };
    int nums[3] = { a, b, c };
    for (int i = 0; i < 3; i++) {
        int n = nums[i];
        cnt[n / 100]++;       // 百位
        cnt[n / 10 % 10]++;   // 十位
        cnt[n % 10]++;        // 个位
    }
    if (cnt[0] != 0) return false;   // 不能出现 0
    for (int d = 1; d <= 9; d++)
        if (cnt[d] != 1) return false;
    return true;
}
int main() {
    // 枚举第一个数 a：a*3 必须也是三位数，故 a <= 987/3 = 329
    for (int a = 123; a <= 329; a++)
        if (check(a))
            cout << a << " " << a * 2 << " " << a * 3 << endl;
    return 0;
}