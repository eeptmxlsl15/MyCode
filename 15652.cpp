#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

    
using namespace std;

int n, m;
int arr[12] = { 0, };
bool visited[12] = { 0, };

void dfs(int num, int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i <= n; i++)
    {
        
        arr[cnt] = i;
        dfs(i, cnt + 1);
        
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);
}