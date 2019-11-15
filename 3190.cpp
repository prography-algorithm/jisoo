#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;    //보드 크기
    int map[101][101] = {0,};    //보드
    int k;  // 사과의 개수

    cin >> n >> k;
    
    for(int i=0; i<k; i++) {    //사과 위치 저장
        int x, y;
        cin >> x >> y;
        map[x-1][y-1] = 1;
    }

    int l;  //방향 변환 횟수
    cin >> l;

    queue <pair<int, char>> change; //뱀 방향 변환할거 저장

    for(int i=0; i<l; i++) {    //방향 변환 저장
        int a;
        char b;
        cin >> a >> b;
        change.push({a, b});
    }

    queue<pair<int, int>> snake;    //뱀 위치
    snake.push({0,0});  //시작 위치

    int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };    //상하좌우
    int direction=0;  //현재 이동할 방향
    int time = 0;   //걸린 시간

    int x=0;    //시작 위치
    int y=0;
    map[x][y] = 2;

    while(1) {
        time++;
        x += dx[direction];    //현재 확인할 위치
        y += dy[direction];

        if(x < 0 || x >= n || y < 0 || y >= n)  //보드에서 나가는 경우
            break;
        
        else if (map[x][y] == 2)   //이동할 위치에 뱀 몸이 있으면 끝
            break;
        
        else if (map[x][y] == 0) {     //사과가 없는 경우
            auto tail = snake.front();   //뱀의 꼬리 위치
            map[tail.first][tail.second] = 0;  //맵 초기화

            snake.pop();    //꼬리 삭제
        }

        map[x][y] = 2;    //뱀 표시
        snake.push({x,y});  //뱀 머리 넣어줌

        if(time == change.front().first) {  //방향 변환
            if(change.front().second == 'L') {
                direction = (direction + 3) % 4;    //이유 모름
            }
            else {
                direction = (direction + 1) % 4;    //이유 모름
            }
            change.pop();
        }
    }

    cout << time;
    return 0;
}