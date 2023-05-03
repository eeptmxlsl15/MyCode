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
                //��ȭ�� : ���� 3�� ��� ���ϸ� ���� ��.
                //4�̻��� �� ���� 1�� �ݵ�� ���Ե� ��, 2�� �ݵ�� ���Ե� ��, 3�� �ݵ�� ���Ե� ������
                //��Ÿ�� �� ����. ���� 4�� ���Ѵٸ� 1+ dp(3), 2+dp(2), 3 + dp(1) �� ��Ÿ�� �� �����Ƿ�
                //dp(3)+dp(2)+dp(1)�̴�
                dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
            }
            cout << dp[n]<<endl;
        }
        flag++;

    }
}