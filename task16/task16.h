#include <iostream>
#include <unordered_set>
using namespace std;

struct Node16 {
  int data;
  Node16 *next;
  Node16(int val) {
    data = val;
    next = NULL;
  }
};

struct task16 {
  void removeDuplicates(Node16 *head) {
    if (!head)
      return;

    unordered_set<int> seen;
    Node16 *curr = head;
    Node16 *prev = NULL;

    while (curr != NULL) {
      if (seen.find(curr->data) != seen.end()) {
        prev->next = curr->next;
        delete curr;
      } else {
        seen.insert(curr->data);
        prev = curr;
      }
      curr = prev->next;
    }
  }

  // Utility function
  void printList(Node16 *head) {
    while (head) {
      cout << head->data << " -> ";
      head = head->next;
    }
    cout << "NULL\n";
  }

  int main() {
    Node16 *head = new Node16(3);
    head->next = new Node16(5);
    head->next->next = new Node16(3);
    head->next->next->next = new Node16(7);
    head->next->next->next->next = new Node16(5);

    cout << "Before: ";
    printList(head);

    removeDuplicates(head);

    cout << "After: ";
    printList(head);
    return 0;
  }
};
