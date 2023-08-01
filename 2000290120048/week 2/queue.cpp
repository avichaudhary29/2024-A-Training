#include <iostream>

const int MAX_SIZE = 100;

class Queue {
private:
    int data[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1; // Initialize front and rear to -1 to indicate an empty queue
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % MAX_SIZE;
            }
            data[rear] = value;
        } else {
            std::cout << "Queue overflow! Cannot enqueue " << value << std::endl;
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int item = data[front];
            if (front == rear) {
                front = rear = -1; // If only one element, reset front and rear to indicate an empty queue
            } else {
                front = (front + 1) % MAX_SIZE;
            }
            return item;
        } else {
            std::cout << "Queue underflow! Cannot dequeue from an empty queue." << std::endl;
            return -1; // You can throw an exception or use a different error handling mechanism here.
        }
    }

    int peek() {
        if (!isEmpty()) {
            return data[front];
        } else {
            std::cout << "The queue is empty. No element to peek." << std::endl;
            return -1; // You can throw an exception or use a different error handling mechanism here.
        }
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    std::cout << "Peek: " << myQueue.peek() << std::endl; // Should print 1

    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    }

    return 0;
}
