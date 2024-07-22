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

//숫자 0, 1로만 이루어진 n*n 격자가 주어졌을 때
//k개의 시작점으로부터 이동하여 도달 가능한 칸의 수
//1은 이동불가한 칸

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> map(n+1, vector<int>(n+1)); //0은 이동 가능한 칸, 1은 이동 불가한 칸
  vector<pair<int, int>> startPoint(k);

  //맵 입력
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> map[i][j];
  
  //시작점 입력
  for (int i = 0; i < k; i++) {
    int s, e;
    cin >> s >> e;
    startPoint[i] = { s, e };
  }
  
  vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
  queue<pair<int, int>> q;
  int cnt = 0;

  for (auto start : startPoint) {
    q.push({ start.first, start.second });
  }

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (vis[cur.first][cur.second]) continue;
    vis[cur.first][cur.second] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];
      if (nextN<1 || nextN >n || nextM < 1 || nextM>n || vis[nextN][nextM] || map[nextN][nextM])continue;
      q.push({ nextN, nextM });
    }
  }

  cout << cnt;
}