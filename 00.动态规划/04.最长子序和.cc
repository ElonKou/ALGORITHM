/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 04.最长子序和.cc
*  Author   : pop
*  Email    : elonkou@ktime.cc
*  Date     : Sat 06 Mar 2021 08:21:07 PM CST
================================================================*/

#include <iostream>
#include <vector>

using namespace std;

// M(n) : 以n结尾的最大子序列, M:list
// M(n) = M(n) + n
// if n > 0: add into M list

void Solver(vector<int> data)
{
    int sum = data[0];
    vector<vector<int>> path = {{data[0]}};
    for (size_t i = 1; i < data.size(); i++)
    {
        vector<int> m = path[i - 1];
        if (sum <= 0)
        {
            m.clear();
            m.push_back(data[i]);
            sum = data[i];
        }
        else
        {
            m.push_back(data[i]);
            sum += data[i];
        }
        path.push_back(m);
    }
    for (size_t i = 0; i < path.size(); i++)
    {
        sum = 0;
        for (size_t j = 0; j < path[i].size(); j++)
        {
            sum += path[i][j];
            cout << path[i][j] << " ";
        }
        cout << "= " << sum << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<int> data = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solver(data);
    return 0;
}
