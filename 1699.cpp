#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[100001];
    for(int i = 0; i <= n; i++) {
        dp[i] = i;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j*j <= i; j++) {
            dp[i] = min(dp[i],dp[i-j*j] + 1);   //왜 이렇게 되는지 모르겠다ㅜ
        }
    }

    cout << dp[n];
}