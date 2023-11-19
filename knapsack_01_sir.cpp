//This is the same as the sirs algorithm mentioned dynamic programming
#include <iostream>
using namespace std;

int p[5] = {0, 1, 2, 5, 6};
int wt[5] = {0, 2, 3, 4, 5};
int m = 8, n = 4;
int v[5][10];

void knapsack(int n, int m)
{
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (i == 0 || w == 0)
            {
                v[i][w] = 0;
            }
            else if (wt[i] > w)
            {
                v[i][w] = v[i - 1][w];
            }
            else
            {
                v[i][w] = max(v[i - 1][w], p[i] + v[i - 1][w - wt[i]]);
            }
        }
    }
    cout << v[n][m];
}

int main()
{
    knapsack(n, m);
    return 0;
}