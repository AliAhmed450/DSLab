#include <iostream>
using namespace std;

struct list {
    int data;
    list* next;
};

list* head = NULL;

void insertNode(int data) {
    list* newNode = new list;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        list* nodePtr = head;
        while (nodePtr->next != NULL) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void display() {
    if (head == NULL) {
        cout << "No nodes" << endl;
        return;
    }

    list* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


void deleteMiddleNode(list* node) {
    if (node == NULL || node->next == NULL) {
        return; 
    }

    list* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}

int main() {
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);

    cout << "Original Linked List:" << endl;
    display();

    
    list* toDel = head->next->next;

    deleteMiddleNode(toDel);

    cout << "\nAfter deleting given node:" << endl;
    display();

    return 0;
}
