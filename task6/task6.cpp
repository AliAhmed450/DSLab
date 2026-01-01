
#include <cstddef>
#include <iostream>
using namespace std;

struct Node {
  char data;
  Node *next;
  Node(char val) {
    data = val;
    next = NULL;
  }
};

// Function to find the starting node of the loop
Node *findLoopStart(Node *head) {
  Node *slow = head;
  Node *fast = head;

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
  Node *A = new Node('A');
  Node *B = new Node('B');
  Node *C = new Node('C');
  Node *D = new Node('D');
  Node *E = new Node('E');

  // Create linked list: A → B → C → D → E → C
  A->next = B;
  B->next = C;
  C->next = D;
  D->next = E;
  E->next = C; // Loop here

  Node *loopStart = findLoopStart(A);

  if (loopStart != NULL)
    cout << "Loop starts at node: " << loopStart->data << endl;
  else
    cout << "No loop detected" << endl;

  return 0;
}
