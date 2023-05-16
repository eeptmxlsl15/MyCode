#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> answer;

int n;

char ltgt[11];
bool visited[11];

bool check(char a, char b, char oper) {
	if (oper == '<') {
		if (a > b)
			return false;
	}
	else{
		if(a<b)
			return false;
	}
	return true;
		
}

void dfs(int index,  string num) {
	if (index == n + 1) {
		answer.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (visited[i])
			continue;
		if (index ==0 || check(num[index-1],i+'0',ltgt[index-1])) {
			visited[i] = true;
			dfs(index + 1, num + to_string(i));
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ltgt[i];
	}
	dfs(0,"");
	sort(answer.begin(), answer.end());
	cout << answer[answer.size() - 1];
	cout << answer[0];
	
	
}