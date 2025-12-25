#include <iostream>
using namespace std;

struct PatientNode{
	string name;
	string disease;

	int priority = 0;
	PatientNode* next;
	PatientNode(string name,string disease)
	{
		this->name = name;
		this->disease = disease;
		priority = 0;
	}
	PatientNode(string name,string disease,int p)
	{
		this->name = name;
		this->disease = disease;
		priority = p;
	}
};

int count;
PatientNode *head;
PatientNode *tail;

PatientNode* Dequeue()
{
	if(head == NULL)
	{
		return NULL;
	}
	PatientNode *temp = head;
	if (head->next != NULL) {
		head = temp->next;
	}
	else
	{
		head = nullptr;
	}
	PatientNode *i = temp;

	return i;
}
void Enqueue(PatientNode* node)
{
	count++;
	if(head == NULL)
	{
		head = node;
		tail = node;
		return;
	}
	else if(head->priority < node->priority)
	{
		node->next = head;
		head = node;
		return;
	}
	PatientNode* temp = head;
	while (temp->next != NULL) 
	{
		if(temp->priority > node->priority && temp->next->priority <= node->priority)
		{
			node->next = temp->next;
			temp->next = node;
			return;
		}
		temp=temp->next;
	}
	tail->next = node;
	tail = node;
}

void DisplayQueue(){
	PatientNode* temp = head;
	if (head == NULL)
	{
		return;
	}
	while(temp != NULL)
	{
		cout << endl << temp->name;
		temp = temp->next;
	}
}
int main()
{
}
