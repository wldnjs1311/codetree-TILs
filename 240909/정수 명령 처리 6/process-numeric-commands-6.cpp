#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> myPQ;

	int N;
	cin >> N;

	while (N--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int a;
			cin >> a;
			myPQ.push(a);
		}
		else if (cmd == "pop")
		{
			cout << myPQ.top() << endl;
			myPQ.pop();
		}
		else if (cmd == "size")
		{
			cout << myPQ.size() << endl;
		}
		else if (cmd == "empty")
		{
			if (myPQ.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (cmd == "top")
		{
			cout << myPQ.top() << endl;
		}
	}
}