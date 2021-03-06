/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : 2019.3.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 03 Mar 2021 07:30:19 PM CST
================================================================*/

#include <iostream>
#include <vector>

#define INF 999
using namespace std;

vector<int> dijkstra(const vector<vector<int>>& arc, int v0) {
    vector<int>  path; // record the index in every step.
    vector<int>  dist; // record current shortest distance of the v0-vi.
    vector<bool> flag; // 1: in selected set, 0: not in this set

    path.push_back(v0);
    for (size_t i = 0; i < arc.size(); i++) {
        dist.push_back(arc[v0][i]);
        if (i != v0) {
            flag.push_back(false);
        } else {
            flag.push_back(true);
        }
    }
    while (path.size() != arc.size()) {
        // find shortest dist index
        int min_index = -1;
        int min_value = INF;
        for (size_t i = 0; i < dist.size(); i++) {
            if (!flag[i] && dist[i] < min_value) {
                min_value = dist[i];
                min_index = i;
            }
        }
        if (min_index != -1) {
            // modify the flag
            flag[min_index] = true;
            path.push_back(min_index);
            // update dist
            for (size_t i = 0; i < flag.size(); i++) {
                if (!flag[i]) {
                    if ((dist[min_index] + arc[min_index][i]) < dist[i]) {
                        dist[i] = dist[min_index] + arc[min_index][i];
                    }
                }
            }
        }
    }
    // return path;
    return dist;
}

int main(int argc, char* argv[]) {
    // graph: 1-2-3
    // 1-2: 1
    // 1-3: 2
    // 2-3: 1
    // 1: 3
    // 2: 2
    // 3: 3
    int cnt;
    cin >> cnt;
    vector<vector<int>> data = {};
    for (size_t i = 0; i < cnt; i++) {
        vector<int> temp;
        for (size_t j = 0; j < cnt; j++) {
            temp.push_back(INF);
        }
        data.push_back(temp);
    }

    int c;
    cin >> c;
    for (size_t i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;
        data[a - 1][b - 1] = 1;
        data[b - 1][a - 1] = 1;
    }
    // for (size_t i = 0; i < cnt; i++) {
    //     for (size_t j = 0; j < cnt; j++) {
    //         cout << data[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (size_t i = 0; i < cnt; i++) {
        vector<int> xx  = dijkstra(data, i);
        int         sum = 0;
        for (size_t j = 0; j < cnt; j++) {
            if (xx[j] != INF) {
                sum += xx[j];
            }
        }
        cout << sum << " ";
    }

    return 0;
}
