#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>
#include <string>
using namespace std;

int N;
int M;
int answer;
int ban[10];
string numString;

//현재 값에 고장난 버튼이 포함되었는지 확인하는 함수
bool check(int num) {
	string temp = to_string(num);

	for (int i = 0; i < temp.length(); i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i]-48 == ban[j])//스트링이기때문에 -48해줘야한다 
				return false;
		}

	}
	return true;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> ban[i];
	}
	//100에서 +-로 답을 찾는 경우
	answer = abs(100 - N);
	//하나씩 다 해보기
	//답을 스트링으로 변환
	numString = to_string(N);

	for (int i = 0; i < 999999; i++) {
		if (check(i)) {//현재 숫자에 고장난 버튼이 없을때

			//현재 숫자의 자리수를 세기 위해 string 으로 변환하고
			// 그 길이를 int로 받음
			//+현재값이 +-로 몇번 이동해야하는지 알기위한 절댓값
			int temp = to_string(i).length() + abs(N - i);

			answer = min(answer, temp);

		}
	}
	cout << answer;

//다른 사람의 풀이 : ban을 bool로 선언해서 index에 true를 넣어서 check함수에서 확인하는 것이
//포문을 한번 돌기 때문에 더 효율적이다

}