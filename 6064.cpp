#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

    
using namespace std;

int gcd(int a, int b) { // 최대 공약수
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { // 최소 공배수
    return (a * b) / gcd(a, b);
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int m, n, x, y;
        int result = -1;
        cin >> m >> n >> x >> y;
        int doom = lcm(m, n); // 멸망해까지 답이 나오지 않으면 -1을 출력함
        //답은 m 또는 n 의 몇배 더하기 x 또는 y
        //x 기준으로 정답을 찾고 그것이 n으로 나눴을때 y가 나오는 수를
        //m울 더해가며 찾기. 1씩 더하면 시간초과
        for (int i = x; i <= doom; i += m) {
            int year = i % n;
            if (year == 0)
                year = n;
            if (year == y) {
                result = i;
                break;
            }
        }
        cout << result << '\n';
	}
	
}
//내가 푼것이 아니니 다음에 다시 보자