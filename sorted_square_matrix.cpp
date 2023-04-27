

#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int *input = new int[n];
    int *ans = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
        ans[i] = input[i];
    }

    int s = 0,l = n-1;
    for(int i = n-1; i >= 0; i--) {
        if(abs(input[l]) < abs(input[s])) {
            ans[i] = input[s]*input[s];
            s++;
        } else {
            ans[i] = input[l]*input[l];
            l--;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    delete [] input;   
    delete [] ans;   
    return 0;
}
