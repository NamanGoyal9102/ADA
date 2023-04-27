#include <stack>
#include <iostream>
using namespace std;
void SortStack(stack<int> &s) {
 if (s.empty())
        return;
    int x = s.top();
    s.pop();
    SortStack(s);
    stack<int> temp;
    while (!s.empty() && s.top() > x) {
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}
int main() {
    stack<int> s;
    s.push(10);
    s.push(8);
    s.push(9);
    s.push(65);
    s.push(78);
    SortStack(s);
    cout << "Sorted numbers are: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
   return 0;
}
