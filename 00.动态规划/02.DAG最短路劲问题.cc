/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 02.DAG最短路劲问题.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sat 06 Mar 2021 01:26:30 PM CST
================================================================*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef struct Item
{
    vector<char> pre;
    vector<int> value;
} Item;

map<char, int> path;

int F(map<char, Item> &data, char s)
{
    if (s == 'S')
    {
        path['S'] = 0;
        return path[s];
    }
    else
    {
        auto found = path.find(s);
        if (found != path.end())
        {
            return path[s];
        }
        int minv = 999;
        char mini = '+';
        for (size_t i = 0; i < data[s].pre.size(); i++)
        {
            int x = F(data, data[s].pre[i]);
            if (x + data[s].value[i] < minv)
            {
                minv = data[s].value[i] + x;
                mini = data[s].pre[i];
            }
        }
        path[s] = minv;
        return path[s];
    }
}

int main(int argc, char *argv[])
{
    map<char, Item> data;
    data['S'] = {{'S'}, {0}};
    data['A'] = {{'S'}, {10}};
    data['B'] = {{'S'}, {20}};
    data['C'] = {{'A'}, {30}};
    data['D'] = {{'A', 'B', 'C'}, {10, 20, 5}};
    data['T'] = {{'C', 'D'}, {20, 10}};
    int x = F(data, 'T');
    cout << x << endl;

    return 0;
}
