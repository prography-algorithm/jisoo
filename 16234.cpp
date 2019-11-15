#include <bits/stdc++.h>
using namespace std;


int main() {
    int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };    //상하좌우

    int n, l, r;    //땅크기, 인구수차이 l명이상 r명 이하
    cin >> n >> l >> r;

    int map[51][51];  //인구수 저장
    bool visit[51][51]={0,};  //방문 저장

    for(int i=0; i<n; i++) {    //인구 수 입력받음
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    bool check = true;  //인구 이동 있는지 체크
    int count = 0;  //총 인구 이동 수

    while(check) {  //인구 이동 없을 떄 까지 반복
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(visit[i][j] == 1)
                    continue;

                queue<pair<int, int>> q;    //인접한 노드 저장하는 큐
                q.push({i, j}); //현재 보고있는 노드 저장

                int people;
                int country;
            
                while(!q.empty()) {  //큐가 빌 때 까지 반복
                    auto cur = q.front();   //큐 젤 앞에 원소 꺼낸다
                    q.pop();

                    for(int k=0; k<4; k++) {    //상하좌우 본다

                        int x = cur.first + dx[k];
                        int y = cur.second + dy[k];  //정확한 좌표 저장

                        if(x < 0 || x >= n || y < 0 || y >= m)  //map 범위 밖인 경우
                            continue;   //루프 끝으로
                        
                        if(visit[x][y] == 1 || map[x][y] == 0)   //이미 방문했거나 그림이 아닌경우
                            continue;

                        visit[x][y] = 1;
                        q.push({x,y});
                        
                    }
                }

            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                bool[n][m] = 0;    //방문 0으로 초기화
            }
        }
        
        count++;
    }
    cout << count;
}