
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};


Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur != nullptr) {
        Node* nextNode = cur->next;   
        cur->next = prev;             
        prev = cur;
        cur = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    
    Node* second = reverseList(slow->next);

    
    Node* p1 = head;
    Node* p2 = second;
    bool result = true;
    while (p2 != nullptr) {
        if (p1->data != p2->data) {
            result = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    
    slow->next = reverseList(second);

    return result;
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
        cout << "(empty)";
        return;
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->data << " -> ";
    }
    cout << "NULL";
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void test(const vector<int>& v) {
    Node* head = build(v);
    print(head);
    cout << "   ->   ";
    if (isPalindrome(head)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << "   (list after check: ";
    print(head);
    cout << ")" << endl;
    freeList(head);
}

int main() {
    test({1, 2, 2, 1});      
                   

    return 0;
}