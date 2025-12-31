#include <iostream>
using namespace std;

struct list {
    int data;
    list* next;
    list(int x) { 
        data = x;
        next = NULL;
    }
};


list* addLists(list* l1, list* l2) {
    list* dummy = new list(0);
    list* curr = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry;

        if (l1) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2) {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        curr->next = new list(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}


void insertNode(list*& head, int data) {
    list* newNode = new list(data);
    if (!head) {
        head = newNode;
        return;
    }
    list* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}


void display(list* head) {
    if (head == NULL) {
        cout << "No nodes";
        return;
    } else {
        list* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
        cout<<endl;
        return;
    }
}


int main() {
    list* head1 = NULL;
    list* head2 = NULL;


    insertNode(head1, 3);
    insertNode(head1, 1);
    insertNode(head1, 9);
    insertNode(head1, 9);


    insertNode(head2, 5);
    insertNode(head2, 9);
    insertNode(head2, 2);

    cout << "List 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    list* sumList = addLists(head1, head2);
    cout << "Sum List: ";
    display(sumList);

    return 0;
}
