#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[100001][3] = {{0}};

    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;

    /*
        dp[][0] = 모두 빈 경우
        dp[0][1] = 오른쪽에 있는 경우
        dp[0][2] = 왼쪽에 있는 경우
    */

    for(int i=1; i<=n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901; //양쪽 다 빈 경우
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;    //오른쪽에 있는 경우
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;    //왼쪽에 있는 경우
    }

    cout << dp[n][0];   //왜 0만 출력하는 걸까?
}