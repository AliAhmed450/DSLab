#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Function to sort the bogies using one queue and one stack
void sortBogieQueue(queue<int>& queue1) {
    stack<int> stack1;
    queue<int> queue2;

	stack1.push(queue1.front());
	queue1.pop();
	while (!queue1.empty()) {

		int current = queue1.front();
		queue1.pop();

		if(stack1.top() < current)
		{
			stack1.push(current);
		}
		else 
		{
			while(!stack1.empty())
			{
				if(stack1.top() < current)
				{
					stack1.push(current);
					break;
				}
				queue2.push(stack1.top());
				stack1.pop();

				if (stack1.empty()) 
				{
					stack1.push(current);
					break;
				}
			}
		}
	}
	while (!stack1.empty()) {
	
		queue2.push(stack1.top());
		stack1.pop();
	}

	while(!queue2.empty())
	{
		stack1.push(queue2.front());
		queue2.pop();
	}
	// Now all bogies in queue2 are sorted, transfer them back to queue1
	while (!stack1.empty()) {
		queue1.push(stack1.top());
		stack1.pop();
	}
}

// Function to display the elements of the queue
void displayQueue(queue<int>& q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

int main() {
	// Create a queue with unsorted bogie numbers
	queue<int> queue1;
	queue1.push(5);
	queue1.push(2);
	queue1.push(4);
	queue1.push(1);
	queue1.push(3);

	// Sort the bogies using the described algorithm
	sortBogieQueue(queue1);

	cout << "Sorted Queue: ";
	displayQueue(queue1);

	return 0;
}
