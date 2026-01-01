
#include <cstddef>
#include <iostream>
using namespace std;

struct Node6 {
  char data;
  Node6 *next;
  Node6(char val) {
    data = val;
    next = NULL;
  }
};

struct task6 {

  // Function to find the starting node of the loop
  Node6 *findLoopStart(Node6 *head) {
    Node6 *slow = head;
    Node6 *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        break;
    }

    // No cycle found
    if (fast == NULL || fast->next == NULL)
      return NULL;

    // Step 2: Find start of loop
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow; // Starting node of loop
  }

  int main() {
    // Create nodes
    Node6 *A = new Node6('A');
    Node6 *B = new Node6('B');
    Node6 *C = new Node6('C');
    Node6 *D = new Node6('D');
    Node6 *E = new Node6('E');

    // Create linked list: A → B → C → D → E → C
    A->next = B;
    B->next = C;
    C->next = D;
    D->next = E;
    E->next = C; // Loop here

    Node6 *loopStart = findLoopStart(A);

    if (loopStart != NULL)
      cout << "Loop starts at node: " << loopStart->data << endl;
    else
      cout << "No loop detected" << endl;

    return 0;
  }
};
