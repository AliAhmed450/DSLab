#include <iostream>
using namespace std;

// Definition for singly-linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to remove duplicates from the linked list
void removeDuplicates(Node* head) {
    if (head == nullptr) return;  // Empty list

    unordered_set<int> seen;  // To track unique elements
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        // If current data is already in the set, skip the node
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;  // Remove the current node
            delete current;  // Free memory
        } else {
            seen.insert(current->data);  // Add to set if not present
            prev = current;  // Move prev to current
        }
        current = prev->next;  // Move to the next node
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to insert nodes at the end of the list
void insertNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Insert nodes into the linked list
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 10);
    insertNode(head, 30);
    insertNode(head, 20);
    insertNode(head, 40);

    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
