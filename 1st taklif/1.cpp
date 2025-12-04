#include <stdio.h>

class Node{
    friend class list;
    int value{};
    Node* next{};

    public:
    Node(){
        value = 0;
        next = nullptr;
    }
};

class list{
    Node* last{};
    public:
    list(){
        last = nullptr;
    }
    void print(){
        if(last == nullptr){
            return;
        }
        Node* iterator{last->next};
        while(iterator != last){
            printf("%d - ", iterator->value);
            iterator = iterator->next;
        }
        printf("%d" , last->value);
    }

    int size(){
        if(last == nullptr){
            return 0;
        }
        int size {};
        Node* iterator{last->next};
        while(iterator != last){
            size++;
            iterator = iterator->next;
        }
        size++;

        return size;
    }

    void addToBeginnging(int value){
        Node *p{new Node()};
        p->value = value;
        if(last == nullptr){
            last = p;
            //if the the list has 1 member it should be pointing to itslef not nullptr
            p->next = p;
            return;
        }
        p->next = last->next;
        last->next = p;

    }

    void addtoEnd(int value){
        Node* p{new Node()};
                p->value = value;
        if(last == nullptr){
            last = p;
            last->next = last;
            return;
        }
        p->next = last->next;
        last->next = p;
        last = p;
    }

    void addAfterNode(int value , Node* ptr){
        
        Node* p = new Node();
        p->value = value;
        p->next = ptr->next;
        ptr->next = p;

    }

    void removeBeginning(){
        if(last == nullptr){
            return;
        }
        if(last->next == last){
            delete last;
            last = nullptr;
            return;
        }



        Node* beginging{last->next};
        last->next= beginging->next;
        delete beginging;

    }

    void removeFromEnd(){
        if(last == nullptr){
            return;
        }
        if(last==last->next){
            delete last;
            last = nullptr;
            return;

        }
        Node* current{last->next};
        while(current->next != last){
            current = current->next;
        }
        Node* first{last->next};
        delete last;
        current->next = first;
        last = current;
    }
};
int main(){

    //this is written with chatgpt i was to lazy :)))))

    list myList{};

    printf("Adding nodes to the beginning:\n");
    myList.addToBeginnging(10);
    myList.addToBeginnging(20);
    myList.addToBeginnging(30);
    myList.print();  // Expected: 30 - 20 - 10
    printf("\nSize: %d\n", myList.size());

    printf("\nAdding nodes to the end:\n");
    myList.addtoEnd(40);
    myList.addtoEnd(50);
    myList.print();  // Expected: 30 - 20 - 10 - 40 - 50
    printf("\nSize: %d\n", myList.size());

    printf("\nRemoving the first node:\n");
    myList.removeBeginning();
    myList.print();  // Expected: 20 - 10 - 40 - 50
    printf("\nSize: %d\n", myList.size());

    printf("\nRemoving the last node:\n");
    myList.removeFromEnd();
    myList.print();  // Expected: 20 - 10 - 40
    printf("\nSize: %d\n", myList.size());

    return 0;
}

