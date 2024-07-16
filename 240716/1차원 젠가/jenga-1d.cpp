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


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> blocks(n);
  for (int i = 0; i < n; i++)
    cin >> blocks[i];

  int iTop = n;

  for (int i = 0; i < 2; i++) {
    int s, e;
    cin >> s >> e;

    int iGap = e - s + 1;

    for (int k = e; k < iTop; k++) {
      blocks[k - iGap] = blocks[k];
    }

    iTop -= iGap;
  }

  cout << iTop << '\n';
  for (int i = 0; i < iTop; i++) {
    cout << blocks[i] << '\n';
  }
}