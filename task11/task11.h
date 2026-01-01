
#include <iostream>
using namespace std;

struct task11 {

  const int SIZE = 6;
  int _index = SIZE - 1;

  void push(int *stack, int toAdd) {
    if (_index == SIZE - 1) {
      cout << "Stack Overflow" << endl;
      return;
    }
    stack[++_index] = toAdd;
  }

  int peek(int *stack) { return stack[_index]; }

  int pop(int *stack) {
    if (_index < 0)
      return -1;

    return stack[_index--];
  }

  bool stackEmpty() { return _index < 0; }

  void insert(int *stack, int toAdd) {
    if (stackEmpty() || peek(stack) <= toAdd) {
      push(stack, toAdd);
      return;
    }

    int temp = pop(stack);
    insert(stack, toAdd);
    push(stack, temp);
  }

  void sortStack(int *stack) {
    if (stackEmpty())
      return;

    int x = pop(stack);
    sortStack(stack);
    insert(stack, x);
  }

  int main() {
    int stack[6] = {5, 2, 4, 1, 7, 4};

    sortStack(stack);

    cout << "Sorted stack (bottom to top):\n";
    for (int i = 0; i <= _index; i++)
      cout << stack[i] << endl;

    return 0;
  }
};
