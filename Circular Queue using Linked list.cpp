
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear;   
    int count;    
public:
    CircularQueue() {
        rear = nullptr;
        count = 0;
    }

    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return rear == nullptr;
    }

    int size() {
        return count;
    }

   
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear == nullptr) {
            
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;   
            rear->next = newNode;        
            rear = newNode;              
        }
        count++;
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* front = rear->next;

        if (front == rear) {
            
            delete front;
            rear = nullptr;
        } else {
            rear->next = front->next;    
            delete front;
        }
        count--;
    }

    
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->next->data;
    }

    
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return rear->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* cur = rear->next;   
        cout << "Front -> ";
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != rear->next);   
        cout << "<- Rear" << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();                                   
    cout << "Front: " << q.getFront() << endl;     
    cout << "Rear: " << q.getRear() << endl;       
    cout << "Size: " << q.size() << endl;          

    q.dequeue();
    q.display();                                   

    q.enqueue(40);
    q.display();                                   

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();                                   
    q.dequeue();                                   

    q.enqueue(99);                                 
    q.display();                                   

    return 0;
}