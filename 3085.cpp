#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

int N;
char board[51][51];
int answer;
int horizentalMax = 0; 
int verticalMax = 0;

//&로 참조해서 해당 값을 바꿔주는 함수
void Swap(char& a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;

}
//가로의 최대값을 찾아줌
void horizentalMaxFind() {
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            //옆에 있는 값이랑 같을경우 cnt ++
            if (board[i][j] == board[i][j + 1]) {
                cnt++;

            }
            else {
                //다를 경우 지금까지 증가한 cnt의 최댓값저장
                if (horizentalMax < cnt)
                    horizentalMax = cnt;
                cnt = 0;

            }
        }
        if (horizentalMax < cnt)
            horizentalMax = cnt;
        cnt = 0;
    }
}
//세로의 최댓값을 찾아줌
void verticalMaxFind() {
    int cnt = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (board[j][i] == board[j + 1][i]) {
                cnt++;

            }
            else {
                if (verticalMax < cnt)
                    verticalMax = cnt;
                cnt = 0;

            }
        }
        if (verticalMax < cnt)
            verticalMax = cnt;
        cnt = 0;
    }
    
}

int main() {
    cin >> N;
    //보드 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];

        }
    }
    //빈보드 먼저 최댓값 구함
    verticalMaxFind();
    horizentalMaxFind();
 
    //가로 스왑
    for (int i = 0; i < N; i < i++) {
        for (int j = 0; j < N - 1; j++) {
            if (board[i][j] != board[i][j + 1]) {//값이 다를때만 스왑해서 최댓값구함
                Swap(board[i][j], board[i][j + 1]);
                verticalMaxFind();
                horizentalMaxFind();
                Swap(board[i][j], board[i][j + 1]);//스왑한거 원위치
            }

        }
    }
    //세로 스왑
    for (int i = 0; i < N; i < i++) {
        for (int j = 0; j < N - 1; j++) {
            if (board[j][i] != board[j+1][i]) {
                Swap(board[j][i], board[j+1][i]);
                verticalMaxFind();
                horizentalMaxFind();
                Swap(board[j][i], board[j + 1][i]);

            }

        }
    
    }

    cout << max(verticalMax, horizentalMax)+1;
    //cnt를 0부터 시작해서 마지막에 1 더해줘야함

    //다른 풀이 : 빈보드 따로 구하지 않고 값이 다를때나 같을때나 구분 없이
    //스왑하고 최댓값 구해도 지장 없음
}