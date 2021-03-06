/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 2018.3.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sun 28 Feb 2021 05:43:54 PM CST
================================================================*/

#include <iostream>

using namespace std;

typedef struct Pit{
    int x;
    int y;
}Pit;
typedef struct Line{
    Pit A;
    Pit B;
    int dx;
    int dy;
    double rate;
    double bias;
    int type;  // 1:pingxing, -1:shuzhi
}Line;

int main(int argc, char *argv[]){
    // y = kx + b
    // y = mx + b
    Line L1, L2;
    cin >> L1.A.x >> L1.A.y >> L1.B.x >> L1.B.y;
    cin >> L2.A.x >> L2.A.y >> L2.B.x >> L2.B.y;
    // L1
    L1.dx = L1.B.x - L1.A.x;
    L1.dy = L1.B.y - L1.A.y;
    if(L1.dx == 0){
        L1.type = -1; // shuzhi
    }else if(L1.dy == 0){
        L1.type = 1;  // shuiping
    }else{
        L1.rate = L1.dy * 1.0 / L1.dx;
        L1.bias = L1.A.y - L1.rate * L1.A.x;
    }
    // L2
    L2.dx = L2.B.x - L2.A.x;
    L2.dy = L2.B.y - L2.A.y;
    if(L2.dx == 0){
        L2.type = -1; // shuzhi
    }else if(L2.dy == 0){
        L2.type = 1;  // shuiping
    }else{
        L2.rate = L2.dy * 1.0 / L2.dx;
        L2.bias = L2.A.y - L2.rate * L2.A.x;
    }
    // judge
    double x = 0;
    double y = 0;
    if((L1.type == 1 && L2.type == 1) || (L1.type == -1 && L2.type == -1)){
        cout << "pingxing"<< endl;
        return 0;
    }
    if( abs(L1.rate - L2.rate) < 1e-8){
        cout << "pingxing"<< endl;
        return 0;
    }
    if(L1.type == -1){
        x = L1.A.x;
        y = x * L2.rate;
    }else if(L2.type == -1){
        x = L2.A.x;
        y = x * L1.rate;
    }else{
        // k1 * x + b1 = k2 * x + b2;
        // (k1 - k2)x = b1 - b2;
        // x = (b1 - b2)/(k1 - k2);
        x = (L1.bias - L2.bias) / (L1.rate - L2.rate);
        y = L1.A.x - L1.rate * x;
    }
    cout << x << " " << y << endl;

    // cout << L1.rate << endl;
    // cout << L2.rate << endl;
    return 0;
}
