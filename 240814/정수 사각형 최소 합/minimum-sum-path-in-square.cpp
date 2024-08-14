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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> num(n + 1, vector<int>(n + 1));
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> num[i][j];

  dp[1][n] = num[1][n];

  for (int i = 2; i <= n; i++) {
    dp[1][n - i + 1] = dp[1][n - i + 2] + num[1][n - i + 1]; //가로
    dp[i][n] = dp[i - 1][n] + num[i][n]; //세로
  }

  for (int i = 2; i <= n; i++) {
    for (int j = n - 1; j >= 1; j--) {
      dp[i][j] = min(num[i][j] + dp[i - 1][j], num[i][j] + dp[i][j + 1]);
    }
  }

  cout << dp[n][1];
}