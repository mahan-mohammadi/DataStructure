//make sure you account for empty lists!!!!! always


#include <iostream>
#include <stdio.h>

using namespace std;
class Node{
    friend class linkedlist;
    int value{};
    Node* next{};
    public:
    Node(){
        value = 0;
        next = nullptr;
    }
};


class linkedlist{
    Node* head{};

    void reverselist(Node* ptr){
        if(ptr->next == nullptr){
            head = ptr;
            return;
        }
        reverselist(ptr->next);
        ptr->next->next = ptr;
        ptr->next = nullptr;
    }
    public:
    linkedlist(){
        head = nullptr;
    }
    ~linkedlist(){

        while(head){
            Node* p = head->next;
            delete head;
            head = p; 
        }
    }


    void addNodebeginning(int value){
        Node* p;
        p = new Node();
        p->value = value;

        if(head == nullptr){
           
            p->next = nullptr;
            head = p;
        }
        else{
            p->next = head;

            head = p;
        }
        
    }

    void deletefirst(){

        if(head == nullptr){
            return;
        }
        Node* p = head->next;
        delete head;
        head = p;
    }

    void deleteLast(){
        Node* n = head;
        if(n == nullptr){
            return;
        }
        if(n->next == nullptr){
            delete n;
            head = nullptr;
            return;
        }

        while(n->next->next != nullptr){
            n = n->next;
        }
        Node* last = n->next;
        delete last;
        n->next = nullptr;

    }

    void printList() {
    Node* p = head;
    while(p) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

    
    void deleteAfterNode(Node* other){
        Node* p = other->next;
        other->next = p->next;
        delete p;

    }

    void addAtTheEnd(int value){
        Node* n{head};
        
        Node* p{new Node()};
        if(n == nullptr){
            p->next = nullptr;
            p->value = value;
            head = p;
            return;
        }
        while(n->next != nullptr){
            n = n->next;
        }

        p->value = value;
        p->next = nullptr;
        n->next = p;
    }

    void addAfterNode(int value , Node* other){
        Node* p{new Node()};
        Node* after = other->next;
        other->next = p;
        p->next = after;
        p->value = value;
    }

    void reverse(){
        reverselist(head);
    }
};

int main() {
    linkedlist list;

    cout << "Initial list (empty):" << endl;
    list.printList();

    list.addNodebeginning(10);
    list.addNodebeginning(20);
    list.addNodebeginning(30);

    cout << "After adding 30, 20, 10 at beginning:" << endl;
    list.printList();

    list.addAtTheEnd(40);
    list.addAtTheEnd(50);
    cout << "After adding 40, 50 at end:" << endl;
    list.printList();

    list.deletefirst();
    cout << "After deleting first:" << endl;
    list.printList();

    list.deleteLast();
    cout << "After deleting last:" << endl;
    list.printList();

    list.reverse();
    cout << "After reversing:" << endl;
    list.printList();


    return 0;
}
