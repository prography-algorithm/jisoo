#include <bits/stdc++.h>
using namespace std;

int l, c;   //배열의 크기, 문자 개수


//k는 현재 배열에 저장된 문자 개수, idx는 문자배열에서 선택한 위치
void func(char *arr, char *alphabet, int k, int idx) {   
    if(k==l) {  //문자가 모두 선택되면
        int check = 0;
        for(int i=0; i<l; i++) {    //모음 자음 개수 확인
            if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                check++;
        }
        if(check < 1 || k-check < 2)    //조건에 맞지 않는 경우
            return;

        for(int i=0; i<l; i++){ //출력
            cout << arr[i];
        }
        cout << '\n';
        return;
    }
    for(int i=idx; i<c; i++) {  //배열에 알파벳 넣기
        arr[k] = alphabet[i];
        func(arr, alphabet, k+1, i+1);
    }
}

int main() {
    cin >> l >> c;
    char arr[l]; //암호 저장하는 배열
    char alphabet[c];   //사용될 문자 저장하는 배열

    for(int i=0; i<c; i++) {
        cin >> alphabet[i];
    }
    sort(alphabet, alphabet+c);   //정렬
    func(arr, alphabet, 0, 0);
}