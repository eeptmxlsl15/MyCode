#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

    
using namespace std;

int n;
int dp[22];


int main() {
    int t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> t;

    int flag = 0;

    while (flag != t) {

        cin >> n;
        if (n < 4)
            cout << dp[n] << endl;
        else {
            for (int i = 4; i <= n; i++) {
                //점화식 : 그전 3개 모두 더하면 현재 값.
                //4이상의 수 부터 1이 반드시 포함된 식, 2가 반드시 포함된 식, 3이 반드시 포함된 식으로
                //나타낼 수 있음. 만약 4를 구한다면 1+ dp(3), 2+dp(2), 3 + dp(1) 로 나타낼 수 있으므로
                //dp(3)+dp(2)+dp(1)이다
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
            cout << dp[n]<<endl;
        }
        flag++;

    }
}