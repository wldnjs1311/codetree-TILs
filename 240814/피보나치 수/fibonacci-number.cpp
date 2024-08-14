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
  
  vector<int> dp(n+1);

  dp[0] = 0;
  dp[1] = 1;

  for (int i = 0; i < n -1; i++) {
    dp[i + 2] = dp[i] + dp[i + 1];
  }

  cout << dp[n];
}