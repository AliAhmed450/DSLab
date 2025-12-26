#include <iostream>
using namespace std;

struct Node
{
	string companyName;
	float stockPrice;
	Node *next = NULL;
	Node(string c,float s)
	{
		companyName = c;
		stockPrice =  s;
		next = NULL;
	}
};

Node *head = NULL;
Node *tail= NULL;

void insertNode( Node*& _head, Node*& _tail,Node* node)
{
	if(_head == NULL)
	{
		_head = node;
		_tail = node;
	}
	else {
		_tail->next = node;
		_tail = node;
	}
}


void addUntilNull(Node*& addFrom,Node*& addAt)
{
	while(addFrom != NULL)
	{
		addAt->next = addFrom;
		addFrom = addFrom->next;
		addAt = addAt->next;
	}
}

void mergeLinkedLists(Node*& fl_head, Node*& sl_head)
{
	Node* l1 = fl_head;
	Node* l2 = sl_head;
	if(fl_head->stockPrice < sl_head->stockPrice)
	{
		head = fl_head;
		l1 = fl_head->next;
	}
	else {
		head = sl_head;
		l2 = sl_head->next;
	}

	Node* temp = head;
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->stockPrice < l2->stockPrice )
		{
			temp->next = l1;
			l1 = l1->next;
			if(l1 == NULL) 
				addUntilNull(l2,temp);
		}
		else  
		{
			temp->next = l2;
			l2 = l2->next;
			if(l2 == NULL)
				addUntilNull(l1,temp);
		}
		temp = temp->next;
	}
}
void printList(Node *h) {
	Node *temp = h;
	while (temp != NULL) {
		cout << temp->stockPrice << " -> ";
		temp=temp->next;
	}
}
int main()
{
	Node* fh = NULL;
	Node *ft = NULL; 
	Node *sh = NULL;
	Node *st = NULL;
	Node *n = new Node("A",10.0);
	insertNode(fh,ft, n);
	n = new Node("A",20);
	insertNode(fh,ft, n);
	n = new Node("A",30);
	insertNode(fh,ft, n);
	n = new Node("A",40);
	insertNode(fh,ft, n);
	n = new Node("A",50);
	insertNode(fh,ft, n);
	n = new Node("B",15);
	insertNode(sh,st, n);
	n = new Node("B",25);
	insertNode(sh,st, n);
	n = new Node("B",26);
	insertNode(sh,st, n);
	n = new Node("B",45);
	insertNode(sh,st, n);
	n = new Node("B",47);
	insertNode(sh,st, n);
	mergeLinkedLists(fh,sh);
	printList(head);

}
