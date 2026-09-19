
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


Node* mergeLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }
    return dummy.next;
}

Node* mergeSort(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return head;
    }

 
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

   
    Node* second = slow->next;
    slow->next = nullptr;

   
    Node* left = mergeSort(head);
    Node* right = mergeSort(second);
    return mergeLists(left, right);
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
    Node* head = build({4, 2, 1, 3});
    cout << "Before: ";
    print(head);
    head = mergeSort(head);
    cout << "After:  ";
    print(head);                              
    freeList(head);
    return 0;
}