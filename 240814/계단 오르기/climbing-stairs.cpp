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
  
  vector<int> dp(n+1, 0);

  dp[2] = 1;
  dp[3] = 1;

  for (int i = 4; i <= n; i++) {
    dp[i] = (dp[i-2] + dp[i-3]) % 10007;
  }

  cout << dp[n];
}