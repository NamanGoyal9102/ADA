

#include<iostream>

using namespace std;

void motuPatlu(int n) {
    int indicate = 1;
    int left = n;
    for(int i = 1;i <= n; i++) {
        left -= i;
        if(left <= 0) {
            indicate = 0;
            break;
        } 
        left -= 2*i;
        if(left <= 0) {
            break;
        }
    }
    if(indicate == 1) {
        cout << "MOTU" << endl;
    } else {
        cout << "Patlu" << endl;
    }
}

int main() {
    int n;
    cin >> n;
    motuPatlu(n);
}
