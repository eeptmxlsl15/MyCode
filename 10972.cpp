#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int arr[10001];

int main() {
	int n;
	cin >> n;
		cin >> arr[i];
	}

		//������ ���۰� ���� ���ڷ� �ѱ��
		//������ ���� ������ �ٲ��ְ� true�� ��ȯ
		//���� ���� ������ ���ٸ� false�� ��ȯ
		
	if (next_permutation(arr, arr + n)) {
		for (int i = 0; i < n; i++) {
			cout << arr[i]<<" ";
		}
	}
	else
		cout << -1;
}