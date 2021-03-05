/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 2018.1.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sun 28 Feb 2021 04:09:49 PM CST
================================================================*/

#include <iostream>
#define N 1024

using namespace std;

int main(int argc, char *argv[]){
    int ca = 0;
    int cb = 0;
    int temp = 0;
    cin >> ca;
    cin >> cb;
    
    int a[N] = {0};
    int b[N] = {0};
    for(int i = 0;i < ca; i++){
        cin >> temp;
        if(a[temp] == 0){
            a[temp] ++;
        }
    }
    for(int i = 0;i < cb; i++){
        cin >> temp;
        if(b[temp] == 0){
            b[temp] ++;
        }
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        if((a[i] == b[i]) && (a[i] != 0)) {
            x ++;
        }
        
        if(a[i] != 0 || b[i] != 0)
        {
            y++;
        }   
    }
    cout << x << " " << y;
    return 0;
}
