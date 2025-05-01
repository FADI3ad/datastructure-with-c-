#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int *arr;
public:

    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack is full" << endl;
        }
        else {
            top++;
            arr[top] = value;
        }



    }



    int pop() {
        if (top == -1) {
            cout << "Stack is empty! Can't pop." << endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[top];
    }

};





int main() {


    Stack st(5);
    st.push(10);
    st.push(40);
    st.push(50);
    st.push(0);
    st.push(70);

    for (int i = 0; i < 5; ++i) {
        cout << st.peek() << endl;
        st.pop();
    }


}

