/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 03.最長子序列.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sat 06 Mar 2021 06:08:38 PM CST
================================================================*/

#include <iostream>
#include <vector>

using namespace std;

void solver(vector<int> data)
{
    vector<int> flag = {1};
    vector<vector<int>> path = {{data[0]}};
    for (size_t i = 1; i < data.size(); i++)
    {
        int mcnt = 1;
        vector<int> p;
        for (int j = i - 1; j >= 0; j--)
        {
            if (data[j] < data[i] && flag[j] >= mcnt)
            {
                mcnt = flag[j] + 1;
                p = path[j];
            }
        }
        p.push_back(data[i]);
        flag.push_back(mcnt);
        path.push_back(p);
    }
    for (size_t i = 0; i < flag.size(); i++)
    {
        cout << flag[i] << " ";
    }
    cout << endl;
    for (size_t i = 0; i < path.size(); i++)
    {
        cout << "path " << data[i] << " : ";
        for (size_t j = 0; j < path[i].size(); j++)
        {
            cout << path[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<int> data = {1, 5, 3, 4, 6, 9, 7, 8};
    solver(data);
    return 0;
}
