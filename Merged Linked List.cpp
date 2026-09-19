#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value): data(value), next(nullptr){}

};

Node* mergeTwoList(Node* list1, Node* list2){
        Node temp(0);
        Node* tail=&temp;
      while( list1 && list2){
            if(list1->data <= list2->data){
                tail->next=list1;
                list1=list1->next;
            } else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
          if(list1 != nullptr){
                tail->next = list1;
        }   else{
                tail->next = list2;
}

          return temp.next;
}

Node* build(const vector<int>& v) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int x : v) {
        Node* n = new Node(x);
        if (!head) head = tail = n;
        else { tail->next = n; tail = n; }
    }
    return head;
}

void print(Node* head) {
    if (!head) { cout << "(empty)"<<endl; return; }
    for (Node* cur = head; cur; cur = cur->next)
        cout << cur->data << " -> ";
    cout << "NULL"<<endl;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    
    Node* merged = mergeTwoList(build({1, 2, 4}), build({1, 3, 4}));
    print(merged);              
    freeList(merged);

    return 0;
}