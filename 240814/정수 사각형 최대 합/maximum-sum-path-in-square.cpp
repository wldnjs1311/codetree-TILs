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
  vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

  for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= n; j++) 
      cin >> num[i][j];
  
  for (int i = 1; i <= n; i++) {
    dp[i][1] = dp[i - 1][1] + num[i][1];
    dp[1][i] = dp[1][i - 1] + num[1][i];
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      dp[i][j] = max(num[i][j] + dp[i][j - 1], num[i][j] + dp[i - 1][j]);
    }
  }
  
  cout << dp[n][n];
}