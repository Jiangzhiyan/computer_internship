#include <iostream>
using namespace std;

// 使用子函数计算第n个月的兔子对数
int fibonacci(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    const int months = 12; // 计算12个月的兔子对数
    
    // 方法1：不用子函数计算
    cout << "不用子函数计算结果：" << endl;
    int f0 = 1, f1 = 2;
    cout << f0 << " " << f1 << " ";
    
    for (int i = 2; i < months; i++) {
        int fn = f0 + f1;
        cout << fn << " ";
        f0 = f1;
        f1 = fn;
    }
    cout << endl;
    
    // 方法2：使用子函数计算
    cout << "用子函数计算结果：" << endl;
    for (int i = 0; i < months; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    
    return 0;
}
