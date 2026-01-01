#include <iostream>
using namespace std;

struct list17 {
  int data;
  list17 *next;
};

struct task17 {
  list17 *head = NULL;

  void insertNode(int data) {
    list17 *newNode = new list17;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      list17 *nodePtr = head;
      while (nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
      }
      nodePtr->next = newNode;
    }
  }

  void display() {
    if (head == NULL) {
      cout << "No nodes";
      return;
    } else {
      list17 *temp = head;
      while (temp != NULL) {
        cout << "data:" << temp->data << endl;
        temp = temp->next;
      }
      return;
    }
  }

  list17 *nthToLast(int N) {
    if (head == NULL || N <= 0)
      return NULL;

    list17 *slow = head;
    list17 *fast = head;

    for (int i = 0; i < N; i++) {
      if (fast == NULL)
        return NULL;
      fast = fast->next;
    }

    while (fast->next != NULL) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }

  int main() {
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);

    cout << "Linked List:" << endl;
    display();
    int N = 4;
    list17 *result = nthToLast(N);

    if (result != NULL)
      cout << "\n" << N << "th to last element: " << result->data << endl;
    else
      cout << "\nInvalid N or empty list" << endl;

    return 0;
  }
};
