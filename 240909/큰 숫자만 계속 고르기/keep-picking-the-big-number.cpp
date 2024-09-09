#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		pq.push(a);
	}

	for (int i = 0; i < M; i++)
	{
		int tmp = pq.top();
		tmp--;
		pq.pop();
		pq.push(tmp);
	}

	cout << pq.top();
}