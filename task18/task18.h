#include <iostream>
using namespace std;

struct list18 {
    int data;
    list18* next;
};

struct task18{
list18* head = NULL;

void insertNode(int data) {
    list18* newNode = new list18;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        list18* nodePtr = head;
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

    list18* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


void deleteMiddleNode(list18* node) {
    if (node == NULL || node->next == NULL) {
        return; 
    }

    list18* temp = node->next;
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

    
    list18* toDel = head->next->next;

    deleteMiddleNode(toDel);

    cout << "\nAfter deleting given node:" << endl;
    display();

    return 0;
}
};
