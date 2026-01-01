#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

void removeDuplicates(Node* head) {
    if (!head) return;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            delete curr;
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

// Utility function
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(5);

    cout << "Before: ";
    printList(head);

    removeDuplicates(head);

    cout << "After: ";
    printList(head);
}
