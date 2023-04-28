
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> solve(int X, vector<int>& A)
{
    int min = INT_MAX;
    int ind = -1;
 
    for (int i = 0; i < A.size(); i++) {
        if (A[i] < min) {
            min = A[i];
            ind = i;
        }
    }
 
    int kicks = X / min;
 
    vector<int> ans;
 
    if (kicks == 0) {
        return ans;
    }
 
    for (int i = 0; i < kicks; i++) {
        ans.push_back(ind);
    }
 
    int temp = kicks;
    int max_val = kicks * A[ind];
 
    // Try to replace the first element in ans by i,
    // making the order lexicographically smaller
    for (int i = 0; i < ind; i++) {
 
        if (max_val - X == 0 || temp == 0){
            break;
        }
 
       
        while ((max_val - A[ind] + A[i]) <= X && temp != 0) {
            ans.erase(ans.begin());
            ans.push_back(i);
            temp--;
            max_val += (A[i] - A[ind]);
        }
    }
 
    sort(ans.begin(), ans.end());
 
    return ans;
}

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> A;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    vector<int> ans = solve(x,A);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
