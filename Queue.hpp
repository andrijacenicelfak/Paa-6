#include <cstdlib>
#include <iostream>
using namespace std;

// A class to represent a queue
template <class X>
class Queue {
    X *arr;        // array to store queue elements
    int capacity;  // maximum capacity of the queue
    int front;     // front points to the front element in the queue (if any)
    int rear;      // rear points to the last element in the queue
    int count;     // current size of the queue

   public:
    Queue(int size = 10);  // constructor

    X dequeue();
    void enqueue(X x);
    X peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize a queue
template <class X>
Queue<X>::Queue(int size) {
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Utility function to dequeue the front element
template <class X>
X Queue<X>::dequeue() {
    // check for queue underflow
    if (isEmpty()) {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    X x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

// Utility function to add an item to the queue
template <class X>
void Queue<X>::enqueue(X item) {
    if (isFull()) {
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Utility function to return the front element of the queue
template <class X>
X Queue<X>::peek() {
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// Utility function to return the size of the queue
template <class X>
int Queue<X>::size() {
    return count;
}

// Utility function to check if the queue is empty or not
template <class X>
bool Queue<X>::isEmpty() {
    return (size() == 0);
}

// Utility function to check if the queue is full or not
template <class X>
bool Queue<X>::isFull() {
    return (size() == capacity);
}