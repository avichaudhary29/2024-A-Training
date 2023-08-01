#include <iostream>

const int MAX_SIZE = 100;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1; // Initialize top to -1 to indicate an empty stack
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (!isFull()) {
            data[++top] = value;
        } else {
            std::cout << "Stack overflow! Cannot push " << value << std::endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            std::cout << "Stack underflow! Cannot pop from an empty stack." << std::endl;
            return -1; // You can throw an exception or use a different error handling mechanism here.
        }
    }

    int peek() {
        if (!isEmpty()) {
            return data[top];
        } else {
            std::cout << "The stack is empty. No element to peek." << std::endl;
            return -1; // You can throw an exception or use a different error handling mechanism here.
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Peek: " << myStack.peek() << std::endl; // Should print 3

    while (!myStack.isEmpty()) {
        std::cout << "Popped: " << myStack.pop() << std::endl;
    }

    return 0;
}
