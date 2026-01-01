#include <iostream>
using namespace std;

struct PatientNode {
  string name;
  string disease;

  int priority = 0;
  PatientNode *next;
  PatientNode(string name, string disease) {
    this->name = name;
    this->disease = disease;
    priority = 0;
  }
  PatientNode(string name, string disease, int p) {
    this->name = name;
    this->disease = disease;
    priority = p;
  }
};
struct task3 {
  int count;
  PatientNode *head;
  PatientNode *tail;

  PatientNode *Dequeue() {
    if (head == NULL) {
      return NULL;
    }
    PatientNode *temp = head->next;
    if (head->next != NULL) {
      head = temp->next;
    } else {
      head = nullptr;
    }
    PatientNode *i = temp;

    return i;
  }
  void Enqueue(PatientNode *node) {
    count++;
    if (head == NULL) {
      head = node;
      tail = node;
      return;
    } else if (head->priority > node->priority) {
      node->next = head;
      head = node;
      return;
    }
    PatientNode *temp = head;
    while (temp != NULL) {
      if (temp->priority >= node->priority) {
        node->next = temp->next;
        temp->next = node;
        return;
      }
      temp = temp->next;
    }
    tail->next = node;
    tail = node;
  }

  void DisplayQueue() {
    PatientNode *temp = head;
    if (head == NULL) {
      return;
    }
    while (temp != NULL) {
      cout << endl << temp->name << " " << temp->priority;
      temp = temp->next;
    }
  }

  int main() {
    PatientNode *f = new PatientNode("fawad", "nazla", 5);
    PatientNode *m = new PatientNode("muneeb", "injury", 1);
    PatientNode *h = new PatientNode("hassan", "sugar", 7);
    PatientNode *s = new PatientNode("Salman", "khansi", 6);

    cout << "List after " << f->name;
    Enqueue(f);
    DisplayQueue();
    cout << endl;
    cout << endl;
    cout << "List after " << m->name;
    Enqueue(m);
    DisplayQueue();
    cout << endl;
    cout << endl;
    cout << "List after " << h->name;
    Enqueue(h);
    DisplayQueue();
    cout << endl;
    cout << endl;
    cout << "List after " << s->name;
    Enqueue(s);
    DisplayQueue();
    cout << endl;
    return 0;
  }
};
