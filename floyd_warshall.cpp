#include <iostream>
#include <vector>
// #include "bits/stdc++.h"
using namespace std;

int V = 4;
int INF = 1e9;
// Initialising the adjacency matrix with some default values
vector<vector<int>> graph = {{0, 5, INF, 10},
                             {INF, 0, 3, INF},
                             {INF, INF, 0, 1},
                             {INF, INF, INF, 0}

};

void floyd()
{
    int n = graph.size();

    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // display
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }

        cout << endl;
    }
}

int main()
{
    // inputAdj(adj);
    // displayAdj(adj);
    floyd();
    return 0;
}