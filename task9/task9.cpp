#include <cstddef>
#include <iostream>
using namespace std;

struct Node 
{
  int value;
  Node* next;
  Node* prev;
  Node(int x)
  {
    value=x;
  }
};

Node* head = NULL;
Node* tail = NULL;

void InsertFront(Node* n)
{
  if(head == NULL)
  {
    head = n;
    tail = n;
    return;
  }
  n->next = head;
  head->prev = n;
  head =n;
}

void InsertBack(Node* n)
{
  if(head == NULL)
  {
    head = n;
    tail = n;
    return;
  }
  tail->next = n;
  n->prev = tail;
  tail = n;
}

void DeleteFront()
{
  if(head == NULL)
    return;
  head = head->next;
  delete head->prev;
}

void DeleteBack()
{
  if(head == NULL)
    return;
  Node* temp = tail;
  tail = tail->prev;
  tail->next = NULL;
  delete temp;
}

void printList(Node *head) {
  while (head) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

int main()
{
  Node* n = new Node(10);
  InsertFront(n);
  Node* i = new Node(15);
  InsertBack(i);
  Node* u = new Node(13);
  InsertFront(u);
  Node* r = new Node(8);
  InsertBack(r);
  printList(head);
  DeleteFront();
  printList(head);
  DeleteBack();
  printList(head);

}
