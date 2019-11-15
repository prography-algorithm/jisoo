#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  //몇개 숫자 입력할지
    cin >> n;

    int array[n];   //숫자 담을 배열

    for(int i=0; i<n; i++) {    //숫자입력
        cin >> array[i];
    }

    sort(array, array+n);   //정렬

    int check = 0;

    for(int i=0; i<n; i++) {    //중복 제거하면서 출력
        if(check != array[i]) {
            cout << array[i] << ' ';
            check = array[i];
        }
    }
}