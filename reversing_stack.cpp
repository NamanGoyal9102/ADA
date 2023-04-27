#include<iostream>
#include<stack>

using namespace std;

void helper(stack<int> &s, int a) {
    if(s.empty()) {
        s.push(a);
        return;
    }
    int temp = s.top();
    s.pop();
    helper(s,a);
    s.push(temp);
}

void sorted(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    sorted(s);
    helper(s,temp);
}

int main(){
    stack<int> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.push(a);
    }
    for(int i = 0; i < n; i++) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
