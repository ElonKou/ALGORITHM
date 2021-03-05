/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : kruskal.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 03 Mar 2021 07:53:28 PM CST
================================================================*/

#include <algorithm>
#include <iostream>
#include <vector>

#define INF 999

using namespace std;

typedef struct Edge {
    int s;    // start
    int t;    // end
    int v;    // value
    int flag; // 0/1/2: cnt of used
} Edge;

typedef struct Graph {
    int          cnt;
    vector<Edge> edges;
} Graph;

bool cmp(Edge a, Edge b) {
    return a.v < b.v;
}

vector<int> kruskal(Graph graph) {
    vector<int>   path;
    vector<Edge>& edges = graph.edges;
    sort(edges.begin(), edges.end(), cmp);

    for (size_t i = 0; i < edges.size(); i++) {
        if (path.size() == 0) {
            path.push_back(edges[0].s);
            path.push_back(edges[0].t);
        } else {
            Edge* temp = nullptr;
            int   cnt  = 0;
            int   type = -1; // 0:s  1:t
            for (size_t j = 0; j < path.size(); j++) {
                if (edges[i].s == path[j]) {
                    cnt++;
                    type = 0;
                }
                if (edges[i].t == path[j]) {
                    cnt++;
                    type = 1;
                }
            }
            if (cnt == 1) {
                if (type == 0) {
                    path.push_back(edges[i].s);
                }
                if (type == 1) {
                    path.push_back(edges[i].t);
                }
            }
            if (cnt == 0) {
                path.push_back(edges[i].s);
                path.push_back(edges[i].t);
            }
        }
    }
    return path;
}

int main(int argc, char* argv[]) {
    Graph graph;
    graph.cnt   = 6;
    graph.edges = {
        {1, 2, 6, 0},
        {1, 3, 1, 0},
        {1, 4, 5, 0},
        {2, 3, 5, 0},
        {2, 5, 3, 0},
        {3, 4, 5, 0},
        {3, 5, 6, 0},
        {3, 6, 4, 0},
        {4, 6, 2, 0},
        {5, 6, 6, 0}};
    vector<int> xx = kruskal(graph);
    for (size_t i = 0; i < xx.size(); i++) {
        cout << xx[i] << " ";
    }

    return 0;
}
