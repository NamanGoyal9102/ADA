
 
#include <bits/stdc++.h>
 
using namespace std;
vector<vector<int> > dp;
int wildcard_matching(string& s, string& p, int i, int j)
{
    // return 1 if i and j are negative
    if (i < 0 && j < 0)
        return 1;
 
    // return 0 if j is negative
    if (j < 0)
        return 0;
 
    // return i if i is negative
    if (i < 0) {
        // while j is positive
        while (j >= 0) {
            if (p[j] != '*')
                return 0;
            j--;
        }
        return 1;
    }
 
    // if dp state is not visited
    if (dp[i][j] == -1) {
        if (p[j] == '*') {
            return dp[i][j] = finding(s, p, i - 1, j)
                              || finding(s, p, i, j - 1);
        }
        else {
            if (p[j] != s[i] && p[j] != '?')
                return dp[i][j] = 0;
            else
                return dp[i][j]
                       = finding(s, p, i - 1, j - 1);
        }
    }
 
    // return dp[i][j] if dp state is previsited
    return dp[i][j];
}
 
bool isMatch(string s, string p)
{
    dp.clear();
 
    // resize the dp array
    dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
    return dp[s.size()][p.size()]
           = wildcard_matching(s, p, s.size() - 1, p.size() - 1);
}
 
// Driver code
int main()
{
    string str = "baaabab";
    string pattern = "*****ba*****ab";
    // char pattern[] = "ba*****ab";
    // char pattern[] = "ba*ab";
    // char pattern[] = "a*ab";
    // char pattern[] = "a*****ab";
    // char pattern[] = "*a*****ab";
    // char pattern[] = "ba*ab****";
    // char pattern[] = "****";
    // char pattern[] = "*";
    // char pattern[] = "aa?ab";
    // char pattern[] = "b*b";
    // char pattern[] = "a*a";
    // char pattern[] = "baaabab";
    // char pattern[] = "?baaabab";
    // char pattern[] = "*baaaba*";
 
    if (isMatch(str, pattern))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
 
    return 0;
}
