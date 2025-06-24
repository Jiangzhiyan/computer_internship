//
// Created by Administrator on 2025/6/23.
//

#include <iostream>

using namespace std;

int main(){
    int a;
    cout << "输入小于128的十进制整数：";
    cin >> a;
    char x = a;
    cout << x << endl;
    char b;
    cout << "输入一个字符：";
    cin >> b;
    int y = b;
    cout << y << endl;
    cout << "输入十六进制整数：";
    int c;
    cin >> hex >> c;
    cout << dec << c << endl;
    int d;
    cout << "输入十进制整数：";
    cin >> dec >> d;
    cout << hex << d << endl;

    return 0;

}
