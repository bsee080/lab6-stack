#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int v) {
        data = v;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int value) {
        Node* n = new Node(value);
        n->next = top;   // new node goes above the old top
        top = n;
        cout << "Pushed " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << endl;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return -1;      // return something to show nothing is there
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }
};

int main() {

    Stack s;
    int opt, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek (Top element)\n";
        cout << "4. Check Empty\n";
        cout << "5. Exit\n";
        cout << "Enter option: ";
        cin >> opt;

        switch (opt) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                cout << "Top element: " << s.peek() << endl;
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 5:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid option! Try again.\n";
        }

    } while (opt != 5);

    return 0;
}
