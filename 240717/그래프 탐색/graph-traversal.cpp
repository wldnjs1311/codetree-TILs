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

//도달할 수 있는 서로 다른 간선의 수

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> graph(N + 1);

  for (int i = 0; i < M; i++) {
    int dst, src;
    cin >> dst >> src;
    graph[dst].push_back(src);
    graph[src].push_back(dst);
  }

  int cnt = -1;

  vector<bool> vis(N + 1, false);
  stack<int> s;

  s.push(1);

  while (!s.empty()) {
    int cur = s.top();
    s.pop();

    if (vis[cur]) continue;
    vis[cur] = true;
    cnt++;

    for (int i = 0; i < graph[cur].size(); i++) {
      if (vis[graph[cur][i]]) continue;
      s.push(graph[cur][i]);
    }
  }

  cout << cnt;
}