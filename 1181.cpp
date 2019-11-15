#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.size() == b.size())
        return a<b; //길이가 같은데 a가 이전 순서면 true
        
    else    //길이가 다른 경우
        return a.size()<b.size();   //a가 작으면 true
}

int main() {
    int n;  //몇개 입력받는지
    cin >> n;
    string str[n];

    for (int i=0; i<n; i++) {
        cin >> str[i];
    }

    sort(str, str+n, compare);  
    //compare은 인자 두개를 비교하는 함수로 첫번째 인자가 작은 경우 true 리턴해야함

    string check = "";
    for(int i=0; i<n; i++) {
        if(check != str[i]) {
            cout << str[i] << '\n';
            check = str[i];
        }
    }
}