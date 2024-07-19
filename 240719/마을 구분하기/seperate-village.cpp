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

// n*n 크기의 이차원 영역에 사람 혹은 벽이 놓여있음
//상하좌우 인접한 영역에 있는 사람들은 같은 마을
//총 마을의 개수, 같은 마을에 있는 사람 수를 오름차순 출력

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> map(n, vector<int>(n)); //벽 0, 사람 1, 방문 2

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> map[i][j];
  
  int cnt = 0; // 총 마을 수
  vector<int> people; // 마을에 속한 사람의 수

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] != 1) continue;

      cnt++;

      int pCnt = 0;
      stack<pair<int, int>> s;
      s.push({ i, j });

      while (!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();

        if (map[cur.first][cur.second] != 1) continue;
        map[cur.first][cur.second] = 2;
        pCnt++;

        for (int i = 0; i < 4; i++) {
          int nextN = cur.first + dirN[i];
          int nextM = cur.second + dirM[i];

          if (nextN < 0 || nextN >= n || nextM < 0 || nextM >= n || map[nextN][nextM] != 1)continue;
          s.push({ nextN, nextM });
        }
      }

      people.push_back(pCnt);
    }
  }

  sort(people.begin(), people.end());

  cout << cnt << '\n';
  for (int a : people) {
    cout << a << '\n';
  }
}