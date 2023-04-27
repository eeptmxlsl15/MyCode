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

//���� ���� ���峭 ��ư�� ���ԵǾ����� Ȯ���ϴ� �Լ�
bool check(int num) {
	string temp = to_string(num);

	for (int i = 0; i < temp.length(); i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i]-48 == ban[j])//��Ʈ���̱⶧���� -48������Ѵ� 
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
	//100���� +-�� ���� ã�� ���
	answer = abs(100 - N);
	//�ϳ��� �� �غ���
	//���� ��Ʈ������ ��ȯ
	numString = to_string(N);

	for (int i = 0; i < 999999; i++) {
		if (check(i)) {//���� ���ڿ� ���峭 ��ư�� ������

			//���� ������ �ڸ����� ���� ���� string ���� ��ȯ�ϰ�
			// �� ���̸� int�� ����
			//+���簪�� +-�� ��� �̵��ؾ��ϴ��� �˱����� ����
			int temp = to_string(i).length() + abs(N - i);

			answer = min(answer, temp);

		}
	}
	cout << answer;

//�ٸ� ����� Ǯ�� : ban�� bool�� �����ؼ� index�� true�� �־ check�Լ����� Ȯ���ϴ� ����
//������ �ѹ� ���� ������ �� ȿ�����̴�

}