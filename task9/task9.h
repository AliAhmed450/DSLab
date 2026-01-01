#include <cstddef>
#include <iostream>
using namespace std;

struct Node9 {
  int value;
  Node9 *next;
  Node9 *prev;
  Node9(int x) { value = x; }
};

struct task9 {
  Node9 *head = NULL;
  Node9 *tail = NULL;

  void InsertFront(Node9 *n) {
    if (head == NULL) {
      head = n;
      tail = n;
      return;
    }
    n->next = head;
    head->prev = n;
    head = n;
  }

  void InsertBack(Node9 *n) {
    if (head == NULL) {
      head = n;
      tail = n;
      return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
  }

  void DeleteFront() {
    if (head == NULL)
      return;
    head = head->next;
    delete head->prev;
  }

  void DeleteBack() {
    if (head == NULL)
      return;
    Node9 *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete temp;
  }

  void printList(Node9 *head) {
    while (head) {
      cout << head->value << " ";
      head = head->next;
    }
    cout << endl;
  }

  int main() {
    Node9 *n = new Node9(10);
    InsertFront(n);
    Node9 *i = new Node9(15);
    InsertBack(i);
    Node9 *u = new Node9(13);
    InsertFront(u);
    Node9 *r = new Node9(8);
    InsertBack(r);
    printList(head);
    DeleteFront();
    printList(head);
    DeleteBack();
    printList(head);
    return 0;
  }
};
