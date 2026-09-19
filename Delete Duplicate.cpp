#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


Node* removeDuplicates(Node* head) {
    Node* cur = head;

    while (cur != nullptr && cur->next != nullptr) {
        if (cur->data == cur->next->data) {
            Node* temp = cur->next;   
            cur->next = temp->next;   
            delete temp;              
        } else {
            cur = cur->next;          
        }
    }
    return head;
}

Node* build(const vector<int>& v) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int x : v) {
        Node* n = new Node(x);
        if (head == nullptr) {
            head = n;
            tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return head;
}

void print(Node* head) {
    if (head == nullptr) {
        cout << "(empty)" << endl;
        return;
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << " -> ";
    }
    cout << "NULL" << endl;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = build({1, 1, 2, 3, 3});
    cout << "Before: ";
    print(head);
    head = removeDuplicates(head);
    cout << "After:  ";
    print(head);                        
    freeList(head);
                    
    return 0;
}