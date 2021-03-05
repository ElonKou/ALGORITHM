/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : prim.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 03 Mar 2021 07:53:17 PM CST
================================================================*/

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

vector<int> prim(Graph graph, int v0) {
    vector<int>   path;
    vector<Edge>& edges = graph.edges;
    path.push_back(v0);

    for (size_t i = 0; i < edges.size(); i++) {
        if (edges[i].s == v0 || edges[i].t == v0) {
            edges[i].flag = 1;
        }
    }

    while (path.size() != graph.cnt) {
        // find min
        Edge* temp = new Edge({-1, -1, INF, 0});
        for (size_t i = 0; i < edges.size(); i++) {
            if (edges[i].flag == 1 && edges[i].v < temp->v) {
                // must not contain the selected point.
                int cc = 0;
                for (size_t j = 0; j < path.size(); j++) {
                    if (path[j] == edges[i].s) {
                        cc++;
                    }
                    if (path[j] == edges[i].t) {
                        cc++;
                    }
                }
                if (cc != 2) {
                    temp = &edges[i];
                }
            }
        }
        if (temp->v != INF) {
            cout << temp->s << ":" << temp->t << "=" << temp->v << endl;
            int index = -1;
            for (size_t i = 0; i < path.size(); i++) {
                if (path[i] == temp->s) {
                    index = temp->t;
                    break;
                }
                if (path[i] == temp->t) {
                    index = temp->s;
                    break;
                }
            }
            path.push_back(index);
            temp->flag = 2;

            // update edge
            for (size_t i = 0; i < edges.size(); i++) {
                if (edges[i].flag == 0) {
                    if (edges[i].s == index || edges[i].t == index) {
                        edges[i].flag = 1;
                    }
                }
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
    vector<int> xx = prim(graph, 1);
    for (size_t i = 0; i < xx.size(); i++) {
        cout << xx[i] << " ";
    }

    return 0;
}
