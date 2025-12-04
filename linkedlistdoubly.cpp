class Node{
    friend class list;
    private:

    int value;

    //u have to use two * here
    Node* prev , *next;

    public:
    Node(){
        value = 0;
        prev = nullptr , next = nullptr;
    }

    
};


class list{

    Node* head{};

    public:

    list(){
        head = nullptr;
    }

    void addAtTheBeginning(int val){
        Node *n = new Node();
        n->prev = nullptr;
        n->value = val;
        if(head == nullptr){
            head = n;
            head->prev = nullptr;
            head->next = nullptr;
            return;
        }

        head->prev = n;
        n->next = head;
        head = n;

    }

    void addAtTheEnd(int value){
        Node *n = new Node();
        if(head == nullptr){
            n->value = value;
            n->prev = nullptr;
            n->next = nullptr;
            head = n;
            return;
        }
        Node *p = head;
        while(p->next != nullptr){
            p = p->next;
        }  

        p->next = n;
        n->prev = p;
        n->next = nullptr;
        n->value = value;
    }

    void deleteAfterNode(Node* other){
        Node* tobedeleted = other->next;
        other->next = tobedeleted->next;
        other->next->prev = other;
        delete tobedeleted;
    }

    void addAfterANode(int value , Node* other){
        Node* n = new Node();
        n->value = value;
        n->prev = other;
        n->next = other->next;
        other->next->next->prev = n;
        other->next = n;
    }

    void deleteFirstNode(){
        if(nullptr   == head){
            return;
        }

        if(head->next == nullptr){
            delete head;
            head=nullptr;
            return;
        }

        Node *p = head;
        head = head->next;
        head->prev = nullptr;
        delete p;
    }


    void deleteLastNode(){
        if(head == nullptr){
            return;
        }
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }

        Node *p = head;

        while(p->next->next != nullptr){
            p = p->next;
        }
        Node *tobedeleted = p->next;
        p->next = nullptr;


        delete tobedeleted;

    }
};