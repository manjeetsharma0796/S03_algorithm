#include <iostream>
#include <vector>
using namespace std;

int numOfNodes;

vector<vector<int>> adj; // it's an array of array
int visited[10000];

void dfs(int u)
{
    cout << " " << u;                           // this displays the current node being traversed
    visited[u] = 1;                             // marking that node being visited

    for (int i = 0; i < adj[u].size(); i++) {
        int currentNode = adj[u][i];
        if (visited[currentNode] == 0)
            dfs(currentNode);
    }
}

int main()
{
    cout << "Enter number of nodes: ";
    cin >> numOfNodes;
    adj.resize(numOfNodes);                     // only considering to potential size

    for (int i = 0; i < numOfNodes; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    dfs(0);

    return 0;
}