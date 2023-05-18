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

		//순열의 시작과 끝을 인자로 넘기면
		//순열을 다음 순열로 바꿔주고 true를 반환
		//만약 다음 순열이 없다면 false를 반환
		
	if (next_permutation(arr, arr + n)) {
		for (int i = 0; i < n; i++) {
			cout << arr[i]<<" ";
		}
	}
	else
		cout << -1;
}