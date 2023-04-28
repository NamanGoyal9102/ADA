#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int, int> *arr = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cin >> arr[i].second;
    } 
    sort(arr,arr + n);

    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++) {
        if(ans.size() == 0) {
            ans.push_back(arr[i]);
            continue;
        }
        if(arr[i].second > ans[i-1].second && arr[i].second < ans[i-1].first) {
            continue;
        } else if(arr[i].first > ans[i-1].second && arr[i].first < ans[i-1].first) {
            continue;
        }
        ans.push_back(arr[i]);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << "Start Time : " << ans.at(i).second << " Finishing Time : " << ans.at(i).first << endl;
    }

    return 0;
}
