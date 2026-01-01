#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

/* ---------- Utility Functions ---------- */

Node* createNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    return n;
}

void insertEnd(Node*& head, int data) {
    Node* n = createNode(data);
    if (!head) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = n;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* ---------- Merge Function ---------- */
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    
    Node* head;
    if (a->data <= b->data) {
      head = a; 
      a = a->next;
    } else {
      head = b; 
      b = b->next;
    }

    Node *temp = head;
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



//NodeQ10* merge(NodeQ10* a, NodeQ10* b) {
//    if (!a) return b;
//    if (!b) return a;
//
//    NodeQ10 dummy;
//    NodeQ10* tail = &dummy;
//    dummy.next = NULL;
//
//    while (a && b) {
//        if (a->data <= b->data) {
//            tail->next = a;
//            a = a->next;
//        } else {
//            tail->next = b;
//            b = b->next;
//        }
//        tail = tail->next;
//    }
//
//    tail->next = (a ? a : b);
//    return dummy.next;
//}

/* ---------- Optimized Merge Sort ---------- */

Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

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

    Node* left = mergeSort(head);
    Node* right = mergeSort(slow);

    // Optimization: skip merge if ordered

    return merge(left, right);
}

/* ---------- Main ---------- */

int main() {
    Node* head = NULL;

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
