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


// 주어진 돌 중 m개의 돌 치움
// k개의 시작점으로부터 상하좌우 이동
// 도달 가능한 칸의 수를 최대로 하기
// 0 : 이동 가능한 칸 / 1 : 돌 있는 칸
// 
// m개의 돌을 적절하게 치웠을 때 시작지점부터 방문 가능한 서로 다른 칸의 수의 최대를 출력
// 
// 음. 가장 먼저 만나는 애들부터 치우기?? 근데 이게 답이 나올 수 있나?

//시간 복잡도
//

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, k, m; //격자크기, 시작점의 수, 돌의 수
  cin >> n >> k >> m;

  //격자 입력
  vector<vector<int>> map(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> map[i][j];

  vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
  queue<pair<int, int>> q;
  int cnt = 0;

  //시작점 입력
  for (int i = 0; i < k; i++)
  {
    int r, c;
    cin >> r >> c;
    q.push({ r, c });
  }
  
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (vis[cur.first][cur.second]) continue;
    cnt++;
    vis[cur.first][cur.second] = true;

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];
      if (nextN < 1 || nextM < 1 || nextN > n || nextM > n || vis[nextN][nextM]) continue;

      if (map[nextN][nextM] && m <= 0)continue; //돌을 치울 수 없을 때
      else if (map[nextN][nextM]) --m; //돌 치우고 해당 위치로 이동
      q.push({ nextN, nextM });
    }
  }
  
  cout << cnt;
}