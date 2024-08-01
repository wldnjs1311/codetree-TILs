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

//K번 최댓값으로 이동하기
//nxn 크기의 격자에 1이상 100이하의 수가 적혀있음
//특정 위치에서 시작하여 조건을 만족하는 숫자의 위치를 찾아 상하좌우 이동
//이동 k번하거나 더 이상 이동할 수 없으면
//최종 위치 출력

//조건
//1. 시작 위치에 적혀있는 수 x,인접한 칸에서 x보다 작은 곳으로 이동 가능
//2. 1을 만족하면서 이동할 수 있는 칸들 중에 최대값으로 이동
//3. 2를 만족하는 것이 여러 개일 경우, 행 번호 작은 것 우선
//4. 3을 만족하는 것이 여러 개일 경우, 열 번호 작은 것 우선

//다시 4의 위치에서 1번부터 반복. x는 4의 위치의 칸 번호가 됨
pair<int, int> Move(int n, pair<int, int> start, int startNum);

vector<vector<int>> Map(102, vector<int>(102));


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> Map[i][j];
  
  int r, c;
  cin >> r >> c;

  pair<int, int> startPos = { r, c };
  while (k--) {
    pair<int, int>  nextPos = Move(n, startPos, Map[startPos.first][startPos.second]);
    if (nextPos == startPos) break;
    startPos = nextPos;
  }

  cout << startPos.first << ' ' << startPos.second;
}

pair<int, int> Move(int n, pair<int, int> start, int startNum) {
  vector<vector<bool>>  vis(n + 1, vector<bool>(n + 1, false));
  queue<pair<int, int>> q;
  
  vis[start.first][start.second] = true;
  q.push(start);

  int maxNum = 0;
  stack<pair<int, int>> MaxPos; //최대값 갖는 칸 저장
  MaxPos.push(start);

  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();

    if (Map[cur.first][cur.second] >= maxNum && Map[cur.first][cur.second] < startNum) {
      maxNum = Map[cur.first][cur.second];
      MaxPos.push(cur);
    }

    for (int i = 0; i < 4; i++) {
      int nextN = cur.first + dirN[i];
      int nextM = cur.second + dirM[i];
      if (nextN<1 || nextN>n || nextM<1 || nextM>n ||
        vis[nextN][nextM] || Map[nextN][nextM] >= startNum)continue;

      q.push({ nextN, nextM });
      vis[nextN][nextM] = true;
    }
  }

  pair<int, int> result = MaxPos.top();
  MaxPos.pop();

  while (!MaxPos.empty()) {
    pair<int, int> cur = MaxPos.top();
    MaxPos.pop();

    if (Map[cur.first][cur.second] < maxNum) break;
    if (cur == start) break;
    if (result.first > cur.first) result = cur;
    else if (result.first == cur.first)
      result = (result.second > cur.second) ? cur : result;

  }

  return result;
}