
#include <iostream>
using namespace std;

struct Node {
    string companyName;
    float stockPrice;
    Node* next = NULL;
    
    Node(string c, float s) {
        companyName = c;
        stockPrice = s;
        next = NULL;
    }
};

Node* head = NULL;
Node* tail = NULL;

void insertNode(Node*& _head, Node*& _tail, Node* node) {
    if (_head == NULL) {
        _head = node;
        _tail = node;
    }
    else {
        _tail->next = node;
        _tail = node;
    }
}

void addUntilNull(Node*& addFrom, Node*& addAt) {
    while (addFrom != NULL) {
        addAt->next = addFrom;
        addFrom = addFrom->next;
        addAt = addAt->next;
    }
}

void mergeLinkedLists(Node*& fl_head, Node*& sl_head) {
    Node* l1 = fl_head;
    Node* l2 = sl_head;

    if (fl_head == NULL) {
        head = sl_head;
        return;
    }
    if (sl_head == NULL) {
        head = fl_head;
        return;
    }

    // Initialize merged list
    if (l1->stockPrice < l2->stockPrice) {
        head = l1;
        l1 = l1->next;
    }
    else {
        head = l2;
        l2 = l2->next;
    }

    Node* temp = head;

    while (l1 != NULL && l2 != NULL) {
        if (l1->stockPrice < l2->stockPrice) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        }
        else {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }

    // If there are remaining elements in either list
    if (l1 != NULL) {
        temp->next = l1;
    }
    if (l2 != NULL) {
        temp->next = l2;
    }
}

void printList(Node* h) {
    Node* temp = h;
    while (temp != NULL) {
        cout << temp->companyName << ": " << temp->stockPrice << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* fh = NULL;
    Node* ft = NULL;
    Node* sh = NULL;
    Node* st = NULL;

    // Creating first list
    Node* n = new Node("A", 10.0);
    insertNode(fh, ft, n);
    n = new Node("A", 20.0);
    insertNode(fh, ft, n);
    n = new Node("A", 30.0);
    insertNode(fh, ft, n);
    n = new Node("A", 40.0);
    insertNode(fh, ft, n);
    n = new Node("A", 50.0);
    insertNode(fh, ft, n);
    cout << "First List:" << endl;
    printList(fh);

    // Creating second list
    n = new Node("B", 15.0);
    insertNode(sh, st, n);
    n = new Node("B", 25.0);
    insertNode(sh, st, n);
    n = new Node("B", 26.0);
    insertNode(sh, st, n);
    n = new Node("B", 45.0);
    insertNode(sh, st, n);
    n = new Node("B", 47.0);
    insertNode(sh, st, n);
    cout << "Second List:" << endl;
    printList(sh);

    mergeLinkedLists(fh, sh);
    cout << "Merged List:" << endl;
    printList(head);

    return 0;
}
