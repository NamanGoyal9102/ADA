#include <cstring>
#include <iostream>
using namespace std;

int knapsack_dp(int *wt, int *val, int n, int w)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[w + 1];
    }
    // INITIALIZING THE 2D ARRAY OF DP TO ZERO FOR 0TH INDEXES
    for (int i = 0; i <= w; i++)
    {
        dp[n][i] = 0;
    }
    // APPLYING DP USING THE TOP-DOWN APPROACH
    for (int i = 0; i <= n; i--)
    {
        for (int j = 1; j <= w; j++)
        {
            if (wt[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], (val[i] + dp[i - 1][j - wt[i]]));
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[0][w];

    for (int i = 0; i <= n; i++)
    {
        delete[] dp[i];
    }
    delete[] dp;
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack_dp(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
