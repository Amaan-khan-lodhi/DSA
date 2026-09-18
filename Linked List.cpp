
#include<iostream>
using namespace std;

struct Node{
        int data;
        Node* next;
        Node(int value): data(value), next(nullptr){}
};
class LinkedList{
    private:
        Node* head;
        int size;

        void clear() {
            Node* current = head;
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
            size = 0;
        }

    public:
        LinkedList(): head(nullptr), size(0) {}

        ~LinkedList() { clear(); }
        bool isEmpty(){ return head==nullptr; }
        int getsize(){ return size; }

        void insertAtStart(int value) {
            Node* newNode= new Node(value);
            newNode->next=head;
            head=newNode;
            size++;
        }

        void insertAtEnd(int value) {
             Node* newNode= new Node(value);
            if(head==nullptr){
                head=newNode;
                return;
        }
            Node* temp=head;
           while(temp->next != nullptr){
                temp=temp->next;
           }
            temp->next = newNode;
            size++;
        }

        void deletevalue(int value){
            if(head==nullptr){
                return;
            }

            if(head->data==value){
                Node* temp=head;
                head=head->next;
                delete temp;
                return;
            }

            Node* Current=head;
            Node* previous=nullptr;

            while(Current->data != value && Current != nullptr){
                    previous=Current;
                    Current = Current->next;
            }
       

        if(Current == nullptr) return;

            previous->next=Current->next;
            delete Current;
            
            size--;
    }

        void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;

   
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertAtEnd(30);

    cout << "Initial list: ";
    list.display(); 

  
    cout << "Deleting 20...\n";
    list.deletevalue(20);
    list.display(); 


    cout << "Deleting head (5)...\n";
    list.deletevalue(5);
    list.display(); 

    return 25077;
=======
#include<iostream>
using namespace std;

struct Node{
        int data;
        Node* next;
        Node(int value): data(value), next(nullptr){}
};
class LinkedList{
    private:
        Node* head;
        int size;

        void clear() {
            Node* current = head;
            while (current != nullptr) {
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
            head = nullptr;
            size = 0;
        }

    public:
        LinkedList(): head(nullptr), size(0) {}

        ~LinkedList() { clear(); }
        bool isEmpty(){ return head==nullptr; }
        int getsize(){ return size; }

        void insertAtStart(int value) {
            Node* newNode= new Node(value);
            newNode->next=head;
            head=newNode;
            size++;
        }

        void insertAtEnd(int value) {
             Node* newNode= new Node(value);
            if(head==nullptr){
                head=newNode;
                return;
        }
            Node* temp=head;
           while(temp->next != nullptr){
                temp=temp->next;
           }
            temp->next = newNode;
            size++;
        }

        void deletevalue(int value){
            if(head==nullptr){
                return;
            }

            if(head->data==value){
                Node* temp=head;
                head=head->next;
                delete temp;
                return;
            }

            Node* Current=head;
            Node* previous=nullptr;

            while(Current->data != value && Current != nullptr){
                    previous=Current;
                    Current = Current->next;
            }
       

        if(Current == nullptr) return;

            previous->next=Current->next;
            delete Current;
            
            size--;
    }

        void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};

int main() {
    LinkedList list;

   
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtStart(5);
    list.insertAtEnd(30);

    cout << "Initial list: ";
    list.display(); 

  
    cout << "Deleting 20...\n";
    list.deletevalue(20);
    list.display(); 


    cout << "Deleting head (5)...\n";
    list.deletevalue(5);
    list.display(); 

    return 25077;
>>>>>>> 99ba8ef (Add Linked List)
}