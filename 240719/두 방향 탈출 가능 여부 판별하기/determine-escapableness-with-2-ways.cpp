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

//n * m 크기의 이차원 영역의 좌측 상단에서 우측 하단까지 물리지 않고 탈출
// 이동은 아래와 오른쪽으로만 이동함
// 뱀이 있는 칸 못 감
// 탈출 경로 존재 여부 찾기

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> map(n, vector<int>(m)); //뱀이 있으면 0

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  stack<pair<int, int>> s;

  s.push({ 0,0 });

  while (!s.empty()) {
    pair<int, int> cur = s.top();
    s.pop();

    if (vis[cur.first][cur.second]) continue;
    vis[cur.first][cur.second] = true;
    
    if (cur.first == n - 1 && cur.second == m - 1) {
      cout << 1;
      return 0;
    }
    
    for (int i = 0; i < 2; i++) {
      int nextN = cur.first + dirs[i].first;
      int nextM = cur.second + dirs[i].second;
      if (nextN < 0 || nextN >= n || nextM < 0 || nextM >= m||vis[nextN][nextM] || !map[nextN][nextM]) continue;
      s.push({ nextN, nextM });
    }
  }
  cout << 0;
}