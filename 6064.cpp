#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

    
using namespace std;

int gcd(int a, int b) { // �ִ� �����
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) { // �ּ� �����
    return (a * b) / gcd(a, b);
}
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int m, n, x, y;
        int result = -1;
        cin >> m >> n >> x >> y;
        int doom = lcm(m, n); // ����ر��� ���� ������ ������ -1�� �����
        //���� m �Ǵ� n �� ��� ���ϱ� x �Ǵ� y
        //x �������� ������ ã�� �װ��� n���� �������� y�� ������ ����
        //m�� ���ذ��� ã��. 1�� ���ϸ� �ð��ʰ�
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
//���� Ǭ���� �ƴϴ� ������ �ٽ� ����