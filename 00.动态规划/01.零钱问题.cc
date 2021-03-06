/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : dp2.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Fri 05 Mar 2021 07:34:44 PM CST
================================================================*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef struct Item
{
    int v;
    vector<int> path;
} Item;

// 11, 5, 1
// cash(n) : 凑齐n的最少数量
// cash(n) = min(cash(n - 1) + 1, cash(n - 5) + 1, cash(b - 11) + 1)

int main(int argc, char *argv[])
{
    vector<Item> items;
    Item it = Item({0, {}});
    items.push_back(it);

    for (int i = 1; i < 20; i++)
    {
        Item it = Item({999, {}});
        if (i - 1 >= 0)
        {
            if (it.v > items[i - 1].v + 1)
            {
                it = items[i - 1];
                it.v ++;
                it.path.push_back(1);
            }
        }
        if (i - 5 >= 0)
        {
            if (it.v > items[i - 5].v + 1)
            {
                it = items[i - 5];
                it.v ++;
                it.path.push_back(5);
            }
        }
        if (i - 11 >= 0)
        {
            if (it.v > items[i - 11].v + 1)
            {
                it = items[i - 11];
                it.v ++;
                it.path.push_back(11);
            }
        }
        items.push_back(it);
        cout << "cost[" << i << "] = " << items[i].v << endl;
        for (int j = 0; j < items[i].path.size(); j++)
        {
            cout << items[i].path[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
