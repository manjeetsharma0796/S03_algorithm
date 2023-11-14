// this is lcs dynamic approach

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void display(int arr[][6])
{
}

int LCS_DP(string A, string B, int m, int n)
{
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)                    // n 2
    {                                               // m 4
        for (int j = 1; j <= m; j++)                // A = bd
        {                                           // B = abcd
            if (A[j - 1] == B[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string A;
    string B;

    cout << "Enter first string: ";
    getline(cin, A);

    cout << "Enter second string to compare: ";
    getline(cin, B);

    int m = A.length();
    int n = B.length();

    cout << "Longest Subsequence: " << LCS_DP(A, B, m, n) << endl;

    return 0;
}
