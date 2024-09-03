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

class Node {
public:
  Node() : m_preNode(nullptr), m_nextNode(nullptr)
  {
    m_data = "";
  }
  Node(string _data) : m_preNode(nullptr), m_nextNode(nullptr)
  {
    m_data = _data;
  }
  ~Node() { delete m_preNode; delete m_nextNode; m_preNode = nullptr; m_nextNode = nullptr; }

public:
  string get_Data() { return m_data; }
  Node* get_Next() { return m_nextNode; }
  Node* get_Pre() { return m_preNode; }

  void set_Next(Node* _node) { m_nextNode = _node; }
  void set_Pre(Node* _node) { m_preNode = _node; }

private:
  string m_data;
  Node* m_preNode;
  Node* m_nextNode;
};

class List {
public:
  List(string _init) :m_begin(nullptr), m_cur(nullptr)
  {
    m_begin = new Node(_init);
    m_cur = m_begin;
  }

  ~List() { Release(); }

  void Release() {
    Node* cur = m_begin;
    while (!cur) {
      Node* temp = cur->get_Next();
      delete cur;
      cur = temp;
    }

    m_cur = nullptr;
    m_begin = nullptr;
  }

public:
  //함수
  void push_front(string _data) {
    Node* temp = new Node(_data);

    if (m_cur->get_Pre()!=nullptr) {
      temp->set_Pre(m_cur->get_Pre());
      m_cur->get_Pre()->set_Next(temp);
    }

    temp->set_Next(m_cur);
    m_cur->set_Pre(temp);
  }

  void push_back(string _data) {
    Node* temp = new Node(_data);
    
    if (m_cur->get_Next()!= nullptr) {
      temp->set_Next(m_cur->get_Next());
      m_cur->get_Next()->set_Pre(temp);
    }

    temp->set_Pre(m_cur);
    m_cur->set_Next(temp);
  }

  void move_front() {
    if (nullptr != m_cur->get_Pre())
      m_cur = m_cur->get_Pre();
  }

  void move_back() {
    if (nullptr != m_cur->get_Next())
      m_cur = m_cur->get_Next();
  }

  void print_front() {
    if (nullptr != m_cur->get_Pre())
      cout << m_cur->get_Pre()->get_Data() << ' ';
    else
      cout << "(Null)" << ' ';
  }

  void print_cur() {
    if (nullptr != m_cur)
      cout << m_cur->get_Data() << ' ';
    else
      cout << "(Null)" << ' ';
  }

  void print_back() {
    if (nullptr!=m_cur->get_Next())
      cout << m_cur->get_Next()->get_Data() << ' ';
    else
      cout << "(Null)" << ' ';
  }

private:
  Node* m_begin;
  Node* m_cur;
};



int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  string init;
  cin >> init;

  List myList(init);

  int n;
  cin >> n;

  while (n--) {
    int input(0);
    string data;
    cin >> input;

    switch (input)
    {
    case 1:
      cin >> data;
      myList.push_front(data);
      break;

    case 2:
      cin >> data;
      myList.push_back(data);
      break;

    case 3:
      myList.move_front();
      break;

    case 4:
      myList.move_back();
      break;

    default:
      break;
    }

    myList.print_front();
    myList.print_cur();
    myList.print_back();
    cout << '\n';
  }
}