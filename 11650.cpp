#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    pair <int, int> xy[n];
    //pair를 sort할 경우 first 기준으로 정렬하고 그 값이 같으면 second 값으로 정렬함

    for(int i=0; i<n; i++) {
        cin >> xy[i].first >> xy[i].second;
    }

    sort(xy, xy+n);
    for(int i=0; i<n; i++) {
        cout << xy[i].first << ' ' << xy[i].second << '\n';
    }
}