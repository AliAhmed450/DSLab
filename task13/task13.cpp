#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueues {
private:
    queue<int> queue1;  
    queue<int> queue2;  

public:
    void push(int x) {
        queue1.push(x);

        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }

        queue1.swap(queue2);
    }

        int pop() {
        if (queue1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;  
		}

        int top = queue1.front();
        queue1.pop();
        return top;
    }

    int peek() {
        if (queue1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1; 
		}
        return queue1.front();
    }

    bool empty() {
        return queue1.empty();
    }
};

int main() {
    StackUsingQueues stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    cout << "Top element: " << stack.peek() << endl;  
    cout << "Popped element: " << stack.pop() << endl;  
    cout << "Popped element: " << stack.pop() << endl;  

    cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << endl;  
    return 0;
}
