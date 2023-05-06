#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

    
using namespace std;

int n;
int m;
int answer=0;
char arr_n[55][55] = { 0, };
char arr_m[55][55] = { 0, };


int main() {
    cin >> n>>m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &arr_n[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%1d", &arr_m[i][j]);
        }
    }

    if (n < 3 || m < 3) {
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr_n[i][j] != arr_m[i][j]) {
                    answer = -1;
                    cout << answer;
                    return 0;
                }

            }
        }

        
        cout << answer;
        return 0;
    }

    for (int i = 0; i < n - 2; i++) {
        
        for (int j = 0; j < m - 2; j++) {
            if (arr_n[i][j] != arr_m[i][j]) {
                answer++;
                for (int k = 0; k < 3; k++) {
                    arr_n[i+k][j] = !arr_n[i+k][j];
                    arr_n[i + k][j + 1] = !arr_n[i + k][j + 1];
                    arr_n[i + k][j + 2] = !arr_n[i + k][j + 2];
                }
                
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr_n[i][j] != arr_m[i][j]) {
                answer = -1;
                cout << answer;
                return 0;
           }

        }
    }

    cout << answer;
    return 0;
}