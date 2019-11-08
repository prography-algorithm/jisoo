#include <bits/stdc++.h>
using namespace std;

int n, m;


void func(int *arr, int *num, int k) {
    if(m == k) {    //현재 선택한 수의 개수와 일치하면
        for(int i=0; i<m; i++) {    //출력
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=0; i<n; i++) {
        arr[k] = num[i];    //배열안에 숫자를 순서대로 저장
        func(arr, num, k+1);
    }
}

int main() {
    cin >> n >> m;
    int arr[m] = {};
    int num[n] = {};
    for(int i=0; i<n; i++) {    //어떤 숫자를 이용해 수열을 만드는지 입력받음
        cin >> num[i];
    }
    sort(num, num+n);  // 정렬
    func(arr, num, 0);
}