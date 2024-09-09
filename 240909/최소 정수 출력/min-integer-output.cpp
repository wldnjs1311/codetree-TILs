#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<int, vector<int>, greater<>> pq;

	int N;
	cin >> N;

	int a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (a == 0)
		{
			if (pq.empty()) cout << 0 << endl;
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(a);
		}
	}
}