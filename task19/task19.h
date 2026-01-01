#include <iostream>
using namespace std;

struct list19 {
    int data;
    list19* next;
    list19(int x) { 
        data = x;
        next = NULL;
    }
};


struct task19{
list19* addLists(list19* l1, list19* l2) {
    list19* dummy = new list19(0);
    list19* curr = dummy;
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
        curr->next = new list19(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}


void insertNode(list19*& head, int data) {
    list19* newNode = new list19(data);
    if (!head) {
        head = newNode;
        return;
    }
    list19* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}


void display(list19* head) {
    if (head == NULL) {
        cout << "No nodes";
        return;
    } else {
        list19* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
        cout<<endl;
        return;
    }
}


int main() {
    list19* head1 = NULL;
    list19* head2 = NULL;


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

    list19* sumList = addLists(head1, head2);
    cout << "Sum List: ";
    display(sumList);

    return 0;
}
};
