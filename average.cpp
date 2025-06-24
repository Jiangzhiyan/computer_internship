#include <iostream>

using namespace std;

int main() {

    double a, b, c;
    char x;
    while (1){
        cout << "输入3门课程的成绩: ";
        cin >> a >> b >> c;
        cout << "平均成绩: " << (a+b+c)/3 << endl;
        cout << "退出否？";
        cin >> x;
        if(x == 'y'){
            break;
        }
    }

    return 0;
}
