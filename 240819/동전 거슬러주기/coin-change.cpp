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
//DP : 테이블 정의, 점화식 찾기, 초기값 정하기


//동전 거슬러주기
//n개의 동전의 종류
//금액 m을 거슬러주기 위해 필요한 최소 동전의 수

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];

  sort(coins.begin(), coins.end(), greater<>());
  vector<int> dp(m+1, INT_MAX);

  for (int coin : coins) dp[coin] = 1;

  for (int i = 0; i <= m; i++) { //i는 금액
    for (int j = 0; j < n; j++) { //j는 동전의 종류
      if (i - coins[j] < 0 || dp[i - coins[j]] == INT_MAX) continue;
      dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    }
  }

  if (dp[m] == INT_MAX) cout << -1;
  else cout << dp[m];
}