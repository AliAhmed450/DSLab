#include <iostream>
using namespace std;

struct Node7 {
  int data;
  Node7 *next;
};

struct task7 {
  Node7 *head;

  void removeConsecutives(int k) {
    if (!head || k <= 0)
      return;

    Node7 dummy;
    dummy.next = head;

    Node7 *prev = &dummy;
    Node7 *curr = head;

    while (curr) {
      Node7 *start = curr;
      int count = 0;

      // Count consecutive zeros
      while (curr && curr->data == 0) {
        count++;
        curr = curr->next;
      }

      // Remove if count >= k
      if (count >= k) {
        prev->next = curr;
      }

      // Move prev to the last non-zero node
      curr = curr->next;
      if (count < k) {
        while (prev->next != curr)
          prev = prev->next;
      }
    }

    head = dummy.next;
  }

  Node7 *createNode(int data) {
    Node7 *n = new Node7();
    n->data = data;
    n->next = NULL;
    return n;
  }

  void insertEnd(int data) {
    Node7 *n = createNode(data);
    if (!head) {
      head = n;
      return;
    }

    Node7 *temp = head;
    while (temp->next)
      temp = temp->next;

    temp->next = n;
  }

  void printList(Node7 *head) {
    while (head) {
      cout << head->data << " ";
      head = head->next;
    }
    cout << endl;
  }

  int main() {
    insertEnd(1);
    insertEnd(0);
    insertEnd(0);
    insertEnd(0);
    insertEnd(1);
    insertEnd(0);
    insertEnd(0);
    insertEnd(1);
    printList(head);
    removeConsecutives(3);
    printList(head);
    return 0;
  }
};
