#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

    
using namespace std;
#define MAX 1000000000;
int n;
long long dp[102][12] = { 0, };
int answer;



int main() {
    cin >> n;
    //dp에서 행을 길이, 열은 끝자리 수를 말함
    //끝자리에는 0이 올수 있으나 첫번째 자리에는 못옴
    //줄의 수가 1인 경우의 수는 1이므로 1로 초기화
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        //길이가 2일때부터는 끝자리에 0이 올 수 있음


        for (int j = 0; j <= 9; j++) {
            //j-1이 -1일때를 방지하기 위함. 9를 넘어갈땐 어차피 0으로 초기화해서 상관없음
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1]  ;
            }
            else {
                dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1]  ;
            }
            dp[i][j] %= MAX;
        }

    }
        for (int i = 0; i <= 9; i++) {
            answer = (answer + dp[n][i])%MAX;
        }
    

        cout << answer;
    
}