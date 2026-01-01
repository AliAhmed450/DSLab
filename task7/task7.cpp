#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node* head;

void removeConsecutives( int k) {
    if (!head || k <= 0) return;

    Node dummy;
    dummy.next = head;

    Node* prev = &dummy;
    Node* curr = head;

    while (curr) {
        Node* start = curr;
        int count = 0;

        // Count consecutive zeros
        while (curr && curr->data == 0) {
            count++;
            curr = curr->next;
        }

        // Remove if count >= k
        if (count >= k) {
            prev->next = curr;
        } 

        // Move prev to the last non-zero node
        curr = curr->next;
        if (count < k) {
            while (prev->next != curr)
                prev = prev->next;
        }
    }

    head = dummy.next;
}

Node* createNode(int data) {
    Node* n = new Node();
    n->data = data;
    n->next = NULL;
    return n;
}

void insertEnd(int data) {
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


int main(){
  insertEnd(1);
  insertEnd(0);
  insertEnd(0);
  insertEnd(0);
  insertEnd(1);
  insertEnd(0);
  insertEnd(0);
  insertEnd(1);
  printList(head);
  removeConsecutives(3);
  printList(head);
}
