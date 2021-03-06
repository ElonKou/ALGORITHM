/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : dp1.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Fri 05 Mar 2021 05:23:44 PM CST
================================================================*/

#include <iostream>

using namespace std;

int F(int x){
    if(x == 0 || x == 1){
        return 1;
    }else{
        return F(x - 1) + F(x - 2);
    }
}

int data[1024] = {0};

int G(int x){
    if(data[x] == 0){
        if(x == 0|| x == 1){
            data[0] = 1;
            data[1] = 1;
            return 1;
        }else{
            data[x] = G(x - 1) + G(x - 2);
            return data[x];
        }
    }else{
        return data[x];
    }
    return 0;
}

int main(int argc, char *argv[]){
    cout << F(5) << endl;
    cout << G(5) << endl;
    for(int i = 0;i < 20; i++){
        cout << data[i] << " "; 
    }
    return 0;
}
