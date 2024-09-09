#include <iostream>
#include <queue>
#include <list>
#include <deque>
#include <cmath>

using namespace std;

struct cmp
{
	bool operator() (pair<int,int>& a, pair<int,int>& b)
	{	
		int disA = abs(a.first) + abs(a.second);
		int disB = abs(b.first) + abs(b.second);

		if (disA == disB) return a.second > b.second;
		return disA > disB;
	}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		pq.push({ a,b });
	}

	for (int i = 0; i < m; i++)
	{
		//원점에서 가장 가까운 점을 골라서 x, y에 2씩 증가
		pair<int, int> tmp = pq.top();
		tmp.first += 2;
		tmp.second += 2;

		pq.pop();
		pq.push(tmp);
	}

	cout << pq.top().first << ' ' << pq.top().second;
}