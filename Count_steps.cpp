#include<iostream>
using namespace std;

int CountSteps(int n) {
    int *ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 3; i <= n; i++) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    int Ans = ans[n];
    delete [] ans;
    return Ans;
}

int main(){
    int n;
    cin >> n;
    cout << CountSteps(n) << endl;
    return 0;
}
