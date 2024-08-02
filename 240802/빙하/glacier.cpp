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

//빙하

//바깥에 있는 애들만 빙하 녹일 수 있음
//1이면 빙하, 0이면 물
//빙하 다 녹는 속도 출력

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> Map(N, vector<int>(M));

  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> Map[i][j];

  vector<vector<int>> vis(N, vector<int>(M, -1));
  queue<pair<int, int>> q;

  q.push({ 0,0 });
  vis[0][0] = 0;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];

      if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M)continue;



      if (Map[nextN][nextM] == 1) {//빙하
        if (vis[nextN][nextM] != -1 && vis[nextN][nextM] <= vis[cur.first][cur.second] + 1) continue;
        vis[nextN][nextM] = vis[cur.first][cur.second] + 1;
      }
      else { //물
        if (vis[nextN][nextM] != -1 && vis[nextN][nextM] <= vis[cur.first][cur.second]) continue;
        vis[nextN][nextM] = vis[cur.first][cur.second];
      }
      q.push({ nextN, nextM });
    }
  }

  int MaxTime = 0;
  int MaxCnt = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (Map[i][j]==1 && vis[i][j] > MaxTime) {
        MaxTime = vis[i][j];
        MaxCnt = 1;
      }
      else if (vis[i][j] == MaxTime)
        MaxCnt++;
    }
  }

  cout << MaxTime << ' ' << MaxCnt;

}