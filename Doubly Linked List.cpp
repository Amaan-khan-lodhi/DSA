#include<iostream>
using namespace std;

struct Node{
        int data;
        Node* next;
        Node* previous;
        Node(int value): data(value), next(nullptr), previous(nullptr){}
};
class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
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
        DoublyLinkedList(): head(nullptr), size(0), tail(nullptr){}

        ~DoublyLinkedList() { clear(); }
        bool isEmpty(){ return head==nullptr; }
        int getsize(){ return size; }

        void insertAtStart(int value) {
            Node* newNode= new Node(value);
            if ( head = nullptr){
                head = tail = newNode;
                return;
            }
            newNode->next=head;
            head = newNode;
            head -> previous = newNode;
            size++;
        }

        void insertAtEnd(int value) {
             Node* newNode= new Node(value);
            if(head==nullptr){
                head=tail=newNode;
                return;
        }
            tail->next=newNode;

   }

//         void deletevalue(int value){
//             if(head==nullptr){
//                 return;
//             }

//             if(head->data==value){
//                 Node* temp=head;
//                 head=head->next;
//                 delete temp;
//                 return;
//             }

//             Node* Current=head;
//             Node* previous=nullptr;

//             while(Current->data != value && Current != nullptr){
//                     previous=Current;
//                     Current = Current->next;
//             }
       

//         if(Current == nullptr) return;

//             previous->next=Current->next;
//             delete Current;
            
//             size--;
//     }

//         void display() const {
//         Node* temp = head;
//         while (temp != nullptr) {
//             cout << temp->data << " -> ";
//             temp = temp->next;
//         }
//         cout << "nullptr\n";
//     }
// };

// int main() {
//     DoublyLinkedList list;

   
//     list.insertAtEnd(10);
//     list.insertAtEnd(20);
//     list.insertAtStart(5);
//     list.insertAtEnd(30);

//     cout << "Initial list: ";
//     list.display(); 

  
//     cout << "Deleting 20...\n";
//     list.deletevalue(20);
//     list.display(); 


//     cout << "Deleting head (5)...\n";
//     list.deletevalue(5);
//     list.display(); 

//     return 25077;
// }