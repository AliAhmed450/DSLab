#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

// Helper function to reverse a linked list
struct task4 {
  Node *reverseList(Node *head) {
    Node *prev = nullptr;
    Node *curr = head;
    Node *next;
    while (curr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  // Function to check palindrome
  bool isPalindrome(Node *head) {
    if (!head || !head->next)
      return true; // Empty or single node is palindrome

    // Step 1: Find the middle
    Node *slow = head;
    Node *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node *secondHalf = reverseList(slow->next);

    // Step 3: Compare first and second half
    Node *firstHalf = head;
    Node *temp = secondHalf; // to restore later
    bool palindrome = true;
    while (secondHalf) {
      if (firstHalf->data != secondHalf->data) {
        palindrome = false;
        break;
      }
      firstHalf = firstHalf->next;
      secondHalf = secondHalf->next;
    }

    // Step 4: Restore the list
    slow->next = reverseList(temp);

    return palindrome;
  }

  // Utility function to print the list
  void printList(Node *head) {
    while (head) {
      cout << head->data << " -> ";
      head = head->next;
    }
    cout << "NULL\n";
  }

  int main() {
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(7);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(1);

    printList(head);

    if (isPalindrome(head))
      cout << "The list is a palindrome.\n";
    else
      cout << "The list is not a palindrome.\n";

    cout << endl << "After Restoring ";
    printList(head); // Confirm list is restored
    return 0;
  }
};
