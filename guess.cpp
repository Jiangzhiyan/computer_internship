//
// Created by Administrator on 2025/6/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    time_t t;
    while (1){
        srand((unsigned)time(&t));
        int a = rand() % 50;
        int input;
        int x = 0;
        while (1){
            cin >> input;
            if (input > a){
                cout << " 太大,";
                x++;
            }
            else if (input < a){
                cout << " 太小，";
                x++;
            }
            else{
                cout << " 对了！";
                x++;
                break;
            }
        }
        cout << "猜" << x << "次成功" << endl;
        char ch;
        cout << "继续否？";
        cin >> ch;
        if (ch == 'n'){
            break;
        }
    }


}