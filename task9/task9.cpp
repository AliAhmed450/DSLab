#include <iostream>
using namespace std;

struct Node 
{
  int value;
  Node* next;
  Node* prev;
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
  Node* temp = head;
  head = head->next;
  delete temp;
}

void DeleteBack()
{
  Node* temp = tail;
  tail = tail->prev;
  delete temp;
}
