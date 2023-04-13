#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

void Swap(int& a, int& b) {
	int temp=a;
	a = b;
	b = temp;

}

void Sort(int numbers[], int count) {
	for (int i = 0; i < count; i++) {
		int best = i;
		for (int j = i + 1; j < count; j++) {
			if (numbers[j] < numbers[best])
				best = j;
		}
		if(i!=best)
			Swap(numbers[i], numbers[best]);
	}

}

void ChooseLotto(int numbers[]) {
	srand((unsigned)time(0));
	int count = 0;
	while (count != 6) {
		int randValue = 1 + (rand() % 45);

		bool found = false;
		for (int i = 0; i < count; i++) {
			if (numbers[i] == randValue)
				found = true;
				break;
		}
		if (found == false) {
			numbers[count] = randValue;
			count++;
		}
	}
	Sort(numbers, 6);
}

int main() {
	int a = 1;
	int b = 1;
	Swap(a, b);

	int numbers[6] = { 1,42,3,15,5,6 };
	Sort(numbers, sizeof(numbers)/sizeof(int));

	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++) {
		cout << numbers[i] << endl;
	}
	return 0;
}