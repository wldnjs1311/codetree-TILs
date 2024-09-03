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

int dirN[4] = { 0,0,-1,1 };
int dirM[4] = { 1,-1,0,0 };

struct node {
  int data;
  node* preNode;
  node* nextNode;
};

class IDList {
public:
  IDList(int _size) : size(_size), arr(nullptr), start(nullptr)
  {
    arr = new node * [size + 1];
    for (int i = 0; i <= size; i++) {
      arr[i] = new node{ i, nullptr, nullptr };
    }
  }
  ~IDList() { Release(); }

public:
  void Release() {
    for (int i = 0; i <= size; i++) {
      delete arr[i];
      arr[i] = nullptr;
    }
    delete [] arr;
    arr = nullptr;
  }

  void pickNode(int i) {
    if (arr[i]->preNode != nullptr) {
      arr[i]->preNode->nextNode = nullptr;
      arr[i]->preNode = nullptr;
    }

    if (arr[i]->nextNode != nullptr) {
      arr[i]->nextNode->preNode = nullptr;
      arr[i]->nextNode = nullptr;
    }
  }

  void insert_front(int i, int j) {
    if (arr[i]->preNode != nullptr) {
      arr[i]->preNode->nextNode = arr[j];
      arr[j]->preNode = arr[i]->preNode;
    }

    arr[j]->nextNode = arr[i];
    arr[i]->preNode = arr[j];
  }

  void insert_back(int i, int j) {
    if (arr[i]->nextNode != nullptr) {
      arr[i]->nextNode->preNode = arr[j];
      arr[j]->nextNode = arr[i]->nextNode;
    }

    arr[j]->preNode = arr[i];
    arr[i]->nextNode = arr[j];
  }

  void print_pre(int i) {
    if (arr[i]->preNode != nullptr)
      cout << arr[i]->preNode->data << ' ';
    else
      cout << 0 << ' ';
  }
  
  void print_next(int i) {
    if (arr[i]->nextNode != nullptr)
      cout << arr[i]->nextNode->data << ' ';
    else
      cout << 0 << ' ';
  }
  
  void print() {
    for (int i = 1; i <= size; i++) {
      print_next(i);
    }
  }

private:
  int size;
  node** arr;
  node* start;
};



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
  int n;
  cin >> n;
  IDList myList(n);

  int q;
  cin >> q;

  int input(0);

  while (q--) {
    cin >> input;
    int data(0);
    int a(0), b(0);

    switch (input)
    {
    case 1:
      cin >> data;
      myList.pickNode(data);
      break;

    case 2:
      cin >> a >> b;
      myList.insert_front(a, b);
      break;

    case 3:
      cin >> a >> b;
      myList.insert_back(a, b);
      break;

    case 4:
      cin >> data;
      myList.print_pre(data);
      myList.print_next(data);
      cout << '\n';
      break;


    default:
      break;
    }
  }

  myList.print();
}