#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <utility>
#include <climits>
#include <queue>
#include <stack>
#include <list>

using namespace std;

int dirN[4] = { 0,0,-1,1 };
int dirM[4] = { 1,-1,0,0 };

int dirthirN[4] = { -1, -1, 1, 1 };
int dirthirM[4] = { -1, 1, 1, -1 };

pair<int, int> dirs[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> map(n, vector<int>(m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];

  
  vector<vector<int>> vis(n, vector<int>(m, -1));
  queue<pair<int, int>> q;

  q.push({ 0,0 });
  vis[0][0] = 0;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];
      if (nextN < 0 || nextM < 0 || nextN >= n || nextM >= m ||
        vis[nextN][nextM] != -1 || !map[nextN][nextM])continue;

      q.push({ nextN, nextM });
      vis[nextN][nextM] = vis[cur.first][cur.second] + 1;
    }
  }

  cout << vis[n - 1][m - 1];
}