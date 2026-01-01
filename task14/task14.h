#include <climits>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct task14 {
  void sortBogies(queue<int> &Q1) {
    queue<int> Q2; // extra queue (output)
    stack<int> S;  // stack

    while (!Q1.empty()) {
      int minVal = INT_MAX;
      int n = Q1.size();

      // Step 1: Move all elements to stack & find minimum
      for (int i = 0; i < n; i++) {
        int x = Q1.front();
        Q1.pop();
        minVal = min(minVal, x);
        S.push(x);
      }

      // Step 2: Move back except one min
      while (!S.empty()) {
        int x = S.top();
        S.pop();

        if (x == minVal) {
          Q2.push(x); // send min to output queue
        } else {
          Q1.push(x); // restore others
        }
      }
    }

    // Copy sorted result back to Q1
    Q1 = Q2;
  }

  /// Function to display the elements of the queue
  void displayQueue(queue<int> &q) {
    while (!q.empty()) {
      cout << q.front() << " ";
      q.pop();
    }
    cout << endl;
  }

  int main() {
    // Create a queue with unsorted bogie numbers
    queue<int> queue1;
    queue1.push(5);
    queue1.push(9);
    queue1.push(4);
    queue1.push(1);
    queue1.push(3);
    queue1.push(7);
    queue1.push(1);
    queue1.push(8);

    // Sort the bogies using the described algorithm
    sortBogies(queue1);

    cout << "Sorted Queue: ";
    displayQueue(queue1);

    return 0;
  }
};
