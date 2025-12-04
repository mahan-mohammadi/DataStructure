//make sure you account for empty lists!!!!! always



#include <stdio.h>

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
    
    void deleteAfterNode(Node* other){
        Node* p = other->next;
        other->next = p->next;
        delete p;

    }

    void addAtTheEnd(int value){
        Node* n = head;
        
        Node* p;
        p = new Node();
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
        Node* p;
        p = new Node();
        Node* after = other->next;
        other->next = p;
        p->next = after;
        p->value = value;
    }
};

int main(){


    return 0;
}