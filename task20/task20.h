#include <iostream>
using namespace std;

struct list20 {
  int data;
  list20 *next;
};

struct task20 {
  list20 *head = NULL;

  void insertNode(int data) {
    list20 *newNode = new list20;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
    } else {
      list20 *nodePtr = head;
      while (nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
      }
      nodePtr->next = newNode;
    }
  }

  list20 *findLoopStart(list20 *head) {
    list20 *slow = head;
    list20 *fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast)
        break;
    }

    if (fast == NULL || fast->next == NULL)
      return NULL;

    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }

  int main() {
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(5);

    list20 *temp = head;
    list20 *loopNode = NULL;

    // making loop to test function

    while (temp->next != NULL) {
      if (temp->data == 3)
        loopNode = temp;
      temp = temp->next;
    }
    temp->next = loopNode;

    list20 *loopStart = findLoopStart(head);

    if (loopStart != NULL)
      cout << "Loop starts at node with data: " << loopStart->data << endl;
    else
      cout << "No loop found" << endl;

    return 0;
  }
};
