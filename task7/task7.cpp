#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
};

void removeConsecutives(Node* &head, int k) {
    if (!head || k <= 0) return;

    Node dummy;
    dummy.next = head;

    Node* prev = &dummy;
    Node* curr = head;

    while (curr) {
        Node* start = curr;
        int count = 0;

        // Count consecutive zeros
        while (curr && curr->value == 0) {
            count++;
            curr = curr->next;
        }

        // Remove if count >= k
        if (count >= k) {
            prev->next = curr->next;
        } 

        // Move prev to the last non-zero node
        if (count < k) {
            while (prev->next != curr)
                prev = prev->next;
        }
        curr = curr->next;
    }

    head = dummy.next;
}

int main(){
  
}
