#include <iostream>
using namespace std;

struct NodeQ10 {
  int data;
  NodeQ10 *next;
};

/* ---------- Utility Functions ---------- */

struct task10 {

  NodeQ10 *createNode(int data) {
    NodeQ10 *n = new NodeQ10();
    n->data = data;
    n->next = NULL;
    return n;
  }

  void insertEnd(NodeQ10 *&head, int data) {
    NodeQ10 *n = createNode(data);
    if (!head) {
      head = n;
      return;
    }

    NodeQ10 *temp = head;
    while (temp->next)
      temp = temp->next;

    temp->next = n;
  }

  void printList(NodeQ10 *head) {
    while (head) {
      cout << head->data << " ";
      head = head->next;
    }
    cout << endl;
  }
  bool isSorted(NodeQ10 *head) {
    while (head && head->next) {
      if (head->data > head->next->data)
        return false;

      head = head->next;
    }
    return true;
  }

  /* ---------- Merge Function ---------- */
  NodeQ10 *merge(NodeQ10 *a, NodeQ10 *b) {
    if (!a)
      return b;
    if (!b)
      return a;

    NodeQ10 *head;
    if (a->data <= b->data) {
      head = a;
      a = a->next;
    } else {
      head = b;
      b = b->next;
    }

    NodeQ10 *temp = head;
    while (a && b) {
      if (a->data <= b->data) {
        temp->next = a;
        a = a->next;
      } else {
        temp->next = b;
        b = b->next;
      }
      temp = temp->next;
    }
    temp->next = (a ? a : b);
    return head;
  }

  // NodeQ10* merge(NodeQ10* a, NodeQ10* b) {
  //     if (!a) return b;
  //     if (!b) return a;
  //
  //     NodeQ10 dummy;
  //     NodeQ10* tail = &dummy;
  //     dummy.next = NULL;
  //
  //     while (a && b) {
  //         if (a->data <= b->data) {
  //             tail->next = a;
  //             a = a->next;
  //         } else {
  //             tail->next = b;
  //             b = b->next;
  //         }
  //         tail = tail->next;
  //     }
  //
  //     tail->next = (a ? a : b);
  //     return dummy.next;
  // }

  /* ---------- Optimized Merge Sort ---------- */

  NodeQ10 *mergeSort(NodeQ10 *head) {
    if (!head || !head->next)
      return head;

    if(isSorted(head)){
      return head;
    }

    NodeQ10 *slow = head;
    NodeQ10 *fast = head;
    NodeQ10 *prev = NULL;

    bool alreadySorted = true;

    // Find middle + check sortedness
    while (fast && fast->next) {
      if (slow->next && slow->data > slow->next->data)
        alreadySorted = false;

      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    // Optimization: already sorted
    if (alreadySorted)
      return head;

    // Split list
    prev->next = NULL;

    NodeQ10 *left = mergeSort(head);
    NodeQ10 *right = mergeSort(slow);

    // Optimization: skip merge if ordered

    return merge(left, right);
  }

  /* ---------- Main ---------- */

  int main() {
    NodeQ10 *head = NULL;

    // Test Case 1 (Partially sorted)
    insertEnd(head, 1);
    insertEnd(head, 3);
    insertEnd(head, 5);
    insertEnd(head, 7);
    insertEnd(head, 2);
    insertEnd(head, 4);
    insertEnd(head, 6);
    insertEnd(head, 8);

    cout << "Original List:\n";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted List:\n";
    printList(head);

    return 0;
  }
};
