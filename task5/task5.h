#include <iostream>
using namespace std;

struct Node5 {
  string companyName;
  float stockPrice;
  Node5 *next = NULL;
  Node5(string c, float s) {
    companyName = c;
    stockPrice = s;
    next = NULL;
  }
};

struct task5 {
  Node5 *head = NULL;
  Node5 *tail = NULL;

  void insertNode(Node5 *&_head, Node5 *&_tail, Node5 *node) {
    if (_head == NULL) {
      _head = node;
      _tail = node;
    } else {
      _tail->next = node;
      _tail = node;
    }
  }

  void addUntilNull(Node5 *&addFrom, Node5 *&addAt) {
    while (addFrom != NULL) {
      addAt->next = addFrom;
      addFrom = addFrom->next;
      addAt = addAt->next;
    }
  }

  void mergeLinkedLists(Node5 *&fl_head, Node5 *&sl_head) {
    Node5 *l1 = fl_head;
    Node5 *l2 = sl_head;
    if (fl_head->stockPrice < sl_head->stockPrice) {
      head = fl_head;
      l1 = fl_head->next;
    } else {
      head = sl_head;
      l2 = sl_head->next;
    }

    Node5 *temp = head;
    while (l1 != NULL && l2 != NULL) {
      if (l1->stockPrice < l2->stockPrice) {
        temp->next = l1;
        l1 = l1->next;
        if (l1 == NULL)
          addUntilNull(l2, temp);
      } else {
        temp->next = l2;
        l2 = l2->next;
        if (l2 == NULL)
          addUntilNull(l1, temp);
      }
      temp = temp->next;
    }
  }
  void printList(Node5 *h) {
    Node5 *temp = h;
    while (temp != NULL) {
      cout << temp->stockPrice << " -> ";
      temp = temp->next;
    }
  }
  int main() {
    Node5 *fh = NULL;
    Node5 *ft = NULL;
    Node5 *sh = NULL;
    Node5 *st = NULL;
    Node5 *n = new Node5("A", 10.0);
    insertNode(fh, ft, n);
    n = new Node5("A", 20);
    insertNode(fh, ft, n);
    n = new Node5("A", 30);
    insertNode(fh, ft, n);
    n = new Node5("A", 40);
    insertNode(fh, ft, n);
    n = new Node5("A", 50);
    insertNode(fh, ft, n);
    cout << "\nFirst List: ";
    printList(fh);
    cout << endl;
    n = new Node5("B", 15);
    insertNode(sh, st, n);
    n = new Node5("B", 25);
    insertNode(sh, st, n);
    n = new Node5("B", 26);
    insertNode(sh, st, n);
    n = new Node5("B", 45);
    insertNode(sh, st, n);
    n = new Node5("B", 47);
    cout << "\nSecond List: ";
    printList(sh);
    cout << endl;
    insertNode(sh, st, n);
    mergeLinkedLists(fh, sh);
    printList(head);
    return 0;
  }
};
