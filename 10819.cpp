#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
using namespace std;



int n;
int arr[10];
vector<int> v;
bool visited[10];
int answer =  0;
int sum = 0;

void dfs(int index) {
	if (index == n) {
		for (int i = 0; i < n-1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		
		answer = max(answer, sum);
		
		sum = 0;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i])
			continue;

		visited[i] = true;
		v.push_back(arr[i]);
		dfs(index + 1);
		v.pop_back();
		visited[i] = false;
		

	}


}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0);
	cout << answer;
}