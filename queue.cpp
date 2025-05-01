#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int size;
public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void push(int value) {
        if (rear == size - 1) {
            cout << "Queue is full! Can't push " << value << endl;
        }
        else {
            rear++;
            arr[rear] = value;
        }
    }

    int pop() {
        if (front > rear) {
            cout << "Queue is empty! Can't dequeue." << endl;
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if (front > rear) {
            cout << "Queue is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[front];
    }
};


int main() {
    Queue qu(5);

    qu.push(10);
    qu.push(20);
    qu.push(60);
    qu.push(30);
    qu.push(40);


    for (int i = 0; i < 5; ++i) {
        cout << qu.peek() << endl;
        qu.pop();
    }

    return 0;
}
