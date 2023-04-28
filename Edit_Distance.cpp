#include <iostream>
#include <cstring>
using namespace std;

int EditDistance(string s1, string s2)
{
    // Write your code here
    int s1_size = s1.size();
    int s2_size = s2.size();
    int **dp = new int *[s1_size + 1];
    for (int i = 0; i <= s1_size; i++)
    {
        dp[i] = new int[s2_size + 1];
    }
    for (int j = 0; j <= s2_size; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s1_size; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i <= s1_size; i++)
    {
        for (int j = 1; j <= s2_size; j++)
        {
            if (s1[s1_size-i] == s2[s2_size-j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }
        }
    }
    return dp[s1_size][s2_size];
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << EditDistance(s1, s2) << endl;
}
