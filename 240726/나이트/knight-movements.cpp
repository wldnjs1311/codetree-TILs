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

int nightN[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int nightM[8] = {-2, -1, 1, 2, 2, 1, -1, -2};


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int n; //격자
  cin >> n;

  pair<int, int> start, end;
  cin >> start.first >> start.second >> end.first >> end.second;

  vector<vector<int>> vis(n + 1, vector<int>(n + 1, -1));
  queue<pair<int, int>> q;

  q.push(start);
  vis[start.first][start.second] = 0;

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (cur == end) break;

    for (int i = 0; i < 8; i++) {
      int nextN = cur.first + nightN[i];
      int nextM = cur.second + nightM[i];
      if (nextN<1 || nextM<1 || nextN>n || nextM>n || vis[nextN][nextM] != -1)continue;
      q.push({ nextN, nextM });
      vis[nextN][nextM] = vis[cur.first][cur.second] + 1;
    }
  }

  cout << vis[end.first][end.second];
}