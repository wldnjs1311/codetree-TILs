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

//nxm 크기의 격자로 구성된 마을
// 격자마다 한 집을 의미
// 각 집의 높이는 1이상 100이하의 숫자로 이루어짐
//비가 k만큼 오면, 높이가 k이하인 집은 물에 잠김
//인접한 그룹의 수 => 안전영역
//안전영역의 수가 최대일 때의 K와 그때의 안전 영역의 수


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int N, M;
  cin >> N >> M;
  
  vector<vector<int>> town(N, vector<int>(M));
  
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> town[i][j];

  int maxSafeArea = 0;
  int maxK = 1;

  for (int k = 1; k <= 100; k++) {
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    int safeArea = 0;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (vis[i][j] || (town[i][j]) <= k) continue;
        
        safeArea++;

        stack<pair<int, int>> s;
        s.push({ i, j });

        while (!s.empty()) {
          pair<int, int> cur = s.top();
          s.pop();

          if (vis[cur.first][cur.second]) continue;
          vis[cur.first][cur.second] = true;

          for (int p = 0; p < 4; p++) {
            int nextN = cur.first + dirN[p];
            int nextM = cur.second + dirM[p];
            if (nextN < 0 || nextN >= N || nextM < 0 || nextM >= M || vis[nextN][nextM] || town[nextN][nextM] <= k)continue;
            s.push({ nextN, nextM });
          }
        }
      }
    }
    if (maxSafeArea < safeArea) {
      maxSafeArea = safeArea;
      maxK = k;
    }
  }
  cout << maxK << ' ' << maxSafeArea;
}