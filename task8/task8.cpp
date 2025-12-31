#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next = NULL;
};

Node *head = NULL;
Node *tail = NULL;

void insertNode(Node *node) {
  if (head == NULL) {
    head = node;
    tail = node;
  } else {
    tail->next = node;
    tail = node;
  }
}

void deleteNode(Node *node) {
  if (head == NULL) 
  {
    return;
  }
  if (head == node) {
    head = node->next;
    delete node;
  } else {
    Node *temp = node;
    while (temp->next != NULL) {
      temp->data = temp->next->data;
      if (temp->next == tail) {
        tail = temp;
        delete temp->next;
      }
      if(temp->next)
      temp = temp->next;
    }
  }
}

int main() {}
