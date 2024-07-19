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

  vector<vector<int>> map(n, vector<int>(m)); //뱀은 0

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];

  
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  queue<pair<int, int>> q;

  q.push({ 0,0 });
  vis[0][0] = true;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    
    if (cur.first == n - 1 && cur.second == m - 1)
    {
      cout << 1;
      return 0;
    }

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];
      if (nextN < 0 || nextN >= n || nextM < 0 || nextM >= m || !map[nextN][nextM] || vis[nextN][nextM]) continue;
      vis[nextN][nextM] = true;
      q.push({ nextN, nextM });
    }
  }
  
  cout << 0;
}