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
    //dp���� ���� ����, ���� ���ڸ� ���� ����
    //���ڸ����� 0�� �ü� ������ ù��° �ڸ����� ����
    //���� ���� 1�� ����� ���� 1�̹Ƿ� 1�� �ʱ�ȭ
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        //���̰� 2�϶����ʹ� ���ڸ��� 0�� �� �� ����


        for (int j = 0; j <= 9; j++) {
            //j-1�� -1�϶��� �����ϱ� ����. 9�� �Ѿ�� ������ 0���� �ʱ�ȭ�ؼ� �������
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