#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;    
    int count;    

public:
    Stack() {
        top = nullptr;
        count = 0;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int size() {
        return count;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;   
        top = newNode;        
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top -> ";
        for (Node* cur = top; cur != nullptr; cur = cur->next) {
            cout << cur->data << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();                                  
    cout << "Top: " << s.peek() << endl;          
    cout << "Size: " << s.size() << endl;         

    s.pop();
    s.display();                                  

    s.pop();
    s.pop();
    s.display();                                
    s.pop();                                      

    s.push(5);                                    
    s.display();                                  

    return 0;
}