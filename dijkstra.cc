/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : dijkstra.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 03 Mar 2021 07:50:37 PM CST
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
    int                 cnt = 5;
    vector<vector<int>> arc = {
        {INF, 10, INF, INF, 5},
        {INF, INF, 1, INF, 2},
        {INF, INF, INF, 4, INF},
        {7, INF, 6, INF, INF},
        {INF, 3, 9, 2, INF},
    };
    vector<int> dist = dijkstra(arc, 1);
    for (size_t i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
    return 0;
}
