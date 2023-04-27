#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;

    int pow = a;
    for(int i = 1; i < b; i++) {
        pow *= a;
    }
    cout << pow << endl;
    return 0;
}
