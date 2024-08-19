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

//정수 사각형 최솟값의 최대
//n개의 숫자
//가장 긴 증가 부분 수열의 길이를 구하는 프로그램 작성
//테이블 정의, 점화식 찾기, 초기값 정하기

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> nums(n);
  vector<int> dp(n, 1);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  int maxLength = 1;
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (nums[i] > nums[j] && dp[i] < nums[j] + 1) {
        dp[i] = dp[j] + 1;
        maxLength = max(maxLength, dp[i]);
      }
    }
  }

  cout << maxLength;
}