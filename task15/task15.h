#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
  stack<pair<int, int>> stack1;

public:
  void push(int val) {

    if (stack1.empty()) {
      stack1.push({val, val});

    } else {
      int currentMin = stack1.top().second;
      stack1.push({val, min(val, currentMin)});
    }
  }

  void pop() {
    if (!stack1.empty()) {
      stack1.pop();
    }
  }

  int getMin() {
    if (!stack1.empty()) {
      return stack1.top().second;
    }
    return -1;
  }

  void display() {
    stack<pair<int, int>> temp = stack1;
    while (!temp.empty()) {
      cout << "Value: " << temp.top().first << " Min: " << temp.top().second
           << endl;
      temp.pop();
    }
  }
};

struct task15{
int main() {
  MinStack minStack;

  minStack.push(3);
  cout << "Min: " << minStack.getMin() << endl;

  minStack.push(5);
  cout << "Min: " << minStack.getMin() << endl;

  minStack.push(2);
  cout << "Min: " << minStack.getMin() << endl;

  minStack.push(1);
  cout << "Min: " << minStack.getMin() << endl;
  minStack.pop();
  cout << "Min: " << minStack.getMin() << endl;
  minStack.pop();
  cout << "Min: " << minStack.getMin() << endl;

  return 0;
}
};
