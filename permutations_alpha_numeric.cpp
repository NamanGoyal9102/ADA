#include <iostream>
using namespace std;
#include <vector>

void helper(string s, vector<string> &ans, string str = "")
{
    if (s.empty())
    {
        ans.push_back(str);
        return;
    }
    if (s[0] - '0' <= 9)
    {
        helper(s.substr(1), ans, str + s[0]);
        return;
    }
    char a = tolower(s[0]);
    char b = toupper(s[0]);

    helper(s.substr(1), ans, str + a);
    helper(s.substr(1), ans, str + b);
}

int main()
{
    string s;
    cin >> s;

    vector<string> ans;
    helper(s, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }
    return 0;
}
