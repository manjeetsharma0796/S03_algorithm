// from LCS we are providing chars and expecting longest integers
// This is the recursive approach

#include <iostream>
#include <algorithm>
using namespace std;

string A;
string B;

int LCS_DP(int i, int j)
{
    if (A[i] == '\0' || B[j] == '\0')
    {
        return 0;
    }
    else if (A[i] == B[j])
    {
        return 1 + LCS_DP(i + 1, j + 1);
    }
    else
    {
        return max(LCS_DP(i + 1, j), LCS_DP(i, j + 1));
    }
}

int main()
{
    cout << "Enter first string: ";
    getline(cin, A);

    cout << "Enter second string to compare: ";
    getline(cin, B);

    cout << LCS_DP(0, 0);

    return 0;
}
