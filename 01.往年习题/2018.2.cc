/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 2018.2.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sun 28 Feb 2021 05:02:03 PM CST
================================================================*/

#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    // 7:
    // 1: 1
    // 2: 1 2
    // 3: 1 3
    // 4: 1 2 4
    // 5: 1 5
    // 6: 1 2 3 6
    // 7: 1 7
    int n;
    cin >> n;
    int sum = n - 1; 
    for(int i = 1;i <= n; i++){
        cout << "1 ";
        for(int j = 2;j <= i/2; j++){
            if(i % j == 0){
                sum += j;
                cout << j << " ";
            }
        }
        sum += i;
        cout << i << " " << endl;
    }
    cout << "sum = " << sum << endl;
    return 0;
}
