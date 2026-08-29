#include <iostream>
using namespace std;
class LinearQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    LinearQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    ~LinearQueue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0; 
        }
        rear++;
        arr[rear] = value;
        cout << "Enqueued: " << value << endl;
    }
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Queue is Empty." << endl;
            return;
        }
        cout << "Linear Queue contents: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    ~CircularQueue() {
        delete[] arr;
    }
    void enqueue(int value) {
        if ((rear + 1) % capacity == front) {
            cout << "Circular Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        cout << "Circular Enqueued: " << value << endl;
    }
    void dequeue() {
        if (front == -1) {
            cout << "Circular Queue Underflow! Cannot dequeue." << endl;
            return;
        }
        cout << "Circular Dequeued: " << arr[front] << endl;
                if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
    }
    void display() {
        if (front == -1) {
            cout << "Circular Queue is Empty." << endl;
            return;
        }
        cout << "Circular Queue contents: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};
int main() {
    int N = 5; 
        cout << "--- Testing Linear Queue ---" << endl;
    LinearQueue lq(N);
    lq.enqueue(10);
    lq.enqueue(20);
    lq.enqueue(30);
    lq.display();
    lq.dequeue();
    lq.display();

    cout << "\n--- Testing Circular Queue ---" << endl;
    CircularQueue cq(N);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();
    cq.dequeue(); 
    cq.dequeue();
    cq.display();
    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();
        return 0;
}