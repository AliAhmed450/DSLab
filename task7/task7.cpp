#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
};

 void removeConsecutives(Node *head, int k) {
    int i = 0;
    Node *parent = NULL;
    Node *temp = head;
    Node *seqStart = NULL;

    while (temp != NULL) {
        if (temp->value == 0) {
            i += 1;
            if (!seqStart)
                seqStart = parent;

            parent  = temp;
            temp = temp->next;
            continue;
        }

        if (i >= k) {
            i = 0;
            seqStart->next = temp;
            seqStart = NULL;
            parent = temp;
            if (temp)
                temp = temp->next;
        }
        
                parent = temp;
        if (temp)
            temp = temp->next;
    }
}

