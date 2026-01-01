#include <iostream>
using namespace std;

struct Node8 {
  int data;
  Node8 *next = NULL;
  Node8(int x) { data = x; }
};

struct task8
{
Node8 *head = NULL;
Node8 *tail = NULL;

void insertNode(Node8 *node) {
  if (head == NULL) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

void deleteNode(Node8 *node) {
  if (head == NULL) {
    return;
  }
  if (head == node) {
    head = node->next;
    delete node;
  } else if (tail == node) {
    Node8 *temp = head;
    while (temp->next->next != NULL) {
      temp = temp->next;
    }
    tail = temp;
    delete temp->next; // delete last node
    temp->next = NULL;
  } else {
    Node8 *temp = node;
    while (temp) {
      if (temp->next == node) {
        temp->next = temp->next->next;
        delete node;
      }
      temp = temp->next;
    }
  }
}

void printList(Node8 *head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node8 *n = new Node8(10);
  insertNode(n);
  Node8 *p = new Node8(15);
  insertNode(p);
  Node8 *i = new Node8(13);
  insertNode(i);
  cout << "\nList Before: ";
  printList(head);
  deleteNode(i);
  printList(head);
  return 0;
}
};
