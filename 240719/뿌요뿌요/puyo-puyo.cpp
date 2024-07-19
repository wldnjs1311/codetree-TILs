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

//n * n 격자에 1이상 100이하의 숫자가 각 칸에 하나씩
// 상하좌우로 인접한 칸끼리 같은 숫자로 이루어져 있으면 한 블럭으로 생각
//블럭을 이루고 있는 칸의 수가 4개 이상인 경우 해방 블럭 터짐

//초기 상태가 주어졌을 때, 터지게 되는 블럭의 수, 최대 블럭의 크기를 구하는 프로그램 작성
//터지는 블럭 수, 최대 블럭 크기

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  vector<vector<bool>> vis(n, vector<bool>(n, false));
  int bombCnt = 0; //터진 블럭 수
  int maxBlockSize = 0; //최대 블럭 크기

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j]) continue;
      
      int curNum = grid[i][j]; //현재 블럭 번호
      int blockSize = 0; //현재 블럭 크기
      stack<pair<int, int>> s;
      s.push({ i, j });

      while (!s.empty()) {
        pair<int, int> cur = s.top();
        s.pop();

        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = true;
        blockSize++;
        
        for (int i = 0; i < 4; i++) {
          int nextN = cur.first + dirN[i];
          int nextM = cur.second + dirM[i];
          if (nextN < 0 || nextN >= n || nextM < 0 || nextM >= n || grid[nextN][nextM] != curNum || vis[nextN][nextM]) continue;
          s.push({ nextN, nextM });
        }
      }

      maxBlockSize = max(maxBlockSize, blockSize);
      if (blockSize >= 4) bombCnt++;
    }
  }
  
  cout << bombCnt << ' ' << maxBlockSize;
  
}