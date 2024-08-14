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

//돌 치우기

//0은 이동 가능, 1은 돌
//주어진 돌 중 m개의 돌만 치워서
//k개의 시작점으로부터 상하좌우 인접한 곳으로만 이동하여 도달 가능한 칸의 수를 최대로 하는 프로그램

vector<vector<int>> Map(102, vector<int>(102));
vector < pair<int, int>> rocks;
vector<pair<int, int>> Remove(8); //치운 돌

int MaxSite = 0;
int n = 0;

void BFS(queue<pair<int, int>> q);
void ChooseRock(int m, int cur, queue<pair<int, int>> q);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int k, m;
  cin >> n >> k >> m;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> Map[i][j];
      if (Map[i][j] == 1) rocks.push_back({ i, j });
    }
  }
  queue<pair<int, int>> startPoints;
  for (int i = 0; i < k; i++) {
    int r, c;
    cin >> r >> c;
    startPoints.push({ r-1, c-1 });
  }

  ChooseRock(m, 0, startPoints);
  
  cout << MaxSite;
}

void BFS(queue<pair<int, int>> q, int m)
{
  int cnt = 0;

  vector<vector<bool>> vis(n, vector<bool>(n, false));

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    
    if (vis[cur.first][cur.second]) continue;
    vis[cur.first][cur.second] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];
      if (nextN < 0 || nextM < 0 || nextN >= n || nextM >= n || vis[nextN][nextM]) continue;
      
      if (Map[nextN][nextM] == 1) {
        bool isRemove = false;
        for (int i = 0; i < m; i++) {
          if (Remove[i].first == nextN && Remove[i].second == nextM) isRemove = true;
        }
        if (!isRemove) continue;
      }
      
      q.push({ nextN, nextM });

    }
  }

  MaxSite = max(MaxSite, cnt);
}

void ChooseRock(int m, int cur, queue<pair<int, int>> q)
{
  if (cur >= m) {
    BFS(q, m);
    return;
  }

  for (int i = cur; i < rocks.size(); i++) {
    Remove[cur] = rocks[i];
    ChooseRock(m, cur + 1, q);
  }
}