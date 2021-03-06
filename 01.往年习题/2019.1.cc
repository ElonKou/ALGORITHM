/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 2019.1.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sun 28 Feb 2021 07:45:44 PM CST
================================================================*/

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    // 九键盘输入
    // 0: " "
    // 1: *
    // 2: abc
    // 3: def
    // 4: ghi
    // 5: jkl
    // 6: mno 
    // 7: pqrs
    // 8: tuv
    // 9: wxyz
    char dict[10][4] = {
    {' ', ' ', ' ', ' '}, 
    {'*', '*', '*', '*'},
    {'a', 'b', 'c', '*'},
    {'d', 'e', 'f', '*'},
    {'g', 'h', 'i', '*'},
    {'j', 'k', 'l', '*'},
    {'m', 'n', 'o', '*'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v', '*'},
    {'w', 'x', 'y', 'z'}};
    string str;
    cin >> str;
    int cnt = 1;
    int num = str[0] - '0';
    for(int i = 1;i < str.size(); i++){
        if(str[i] == '-'){
            if(cnt != 0 && num != 0){
                cout << dict[num][cnt - 1];
            }
            num = 0;
            cnt = 1;
        }else{
            int c = str[i] - '0';
            if(num == c){
                cnt ++;
            }else{
                cout << dict[num][cnt - 1];
                num = c;
                cnt = 1;
            }
        } 
    }
    cout << dict[num][cnt-1];
    return 0;
}
