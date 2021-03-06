/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 2019.2.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 03 Mar 2021 07:01:15 PM CST
================================================================*/

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int cnt;
    cin >> cnt;
    int data[cnt] = {0};
    for (size_t i = 0; i < cnt; i++) {
        cin >> data[i];
    }
    int c;
    cin >> c;
    for (size_t i = 0; i < c; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b >> c;
        for (size_t j = a - 1; j <= b - 1; j++) {
            data[j] += c;
        }
    }
    int q;
    cin >> q;
    for (size_t i = 0; i < q; i++) {
        int a   = 0;
        int b   = 0;
        int sum = 0;
        cin >> a >> b;
        for (size_t j = 0; j < cnt; j++) {
            if (j >= (a - 1) && j <= (b - 1)) {
                sum += data[j];
            }
        }
        cout << sum << endl;
    }

    return 0;
}
