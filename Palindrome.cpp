#include<iostream>
using namespace std;
bool isPalindrome(string test) {
    int i = 0, j = test.length() - 1;
    while(i < j) {
        if(test[i] != test[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main(){
    string test;
    cin >> test;
    if(isPalindrome(test)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}
