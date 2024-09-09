#include <iostream>
#include <queue>
#include <list>
#include <deque>
#include <cmath>

using namespace std;

int N, K;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	vector<list<int>> Mylist(K + 1);
	for (int i = 1; i <= N; i++)
	{
		Mylist[1].push_back(i);
	}

	int Q;
	cin >> Q;

	while (Q--)
	{
		int cmd;
		cin >> cmd;

		int i, j;
		switch (cmd)
		{
		case 1:
			cin >> i >> j;
			if (!Mylist[i].empty())
			{
				Mylist[j].push_back(Mylist[i].front());
				Mylist[i].pop_front();
			}
			break;

		case 2:
			cin >> i >> j;
			if (!Mylist[i].empty())
			{
				Mylist[j].push_front(Mylist[i].back());
				Mylist[i].pop_back();
			}
			break;

		case 3:
			cin >> i >> j;
			if (!Mylist[i].empty())
				Mylist[j].splice(Mylist[j].begin(), Mylist[i]);
		
			break;
		
		case 4:
			cin >> i >> j;
			if (!Mylist[i].empty())
				Mylist[j].splice(Mylist[j].end(), Mylist[i]);
			break;


		default:
			break;
		}
	}


	for (int i = 1; i <= K; i++)
	{
		list<int>::iterator iter = Mylist[i].begin();
		cout << Mylist[i].size() + 1 << ' ';
		for (iter ; iter != Mylist[i].end(); ++iter)
		{
			cout << (*iter) << ' ';
		}
		cout << '\n';
	}
}

//1 ~ K까지의 책꽂이
//1 ~ N까지의 책
//N개의 책은 번호 순서대로 모두 1번 책꽂이에 꽂혀 있음
//연결 리스트 2차원 느낌인가보오 vector가 list를 품는 느낌 어떰

//1. i번 책꽂이의