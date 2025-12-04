#include <iostream>
using namespace std;

class Node {
    friend class Poly;
  private:
    int tavan{};
    int zarib{};
    Node* next{};

    Node(){
        tavan = 0;
        zarib = 0;
        next= nullptr;
    }
};


class Poly {
  private:
    Node* first{};
  public:
    void add_poly(int c,int e);
    void print();
    Poly operator+(Poly b);
    Poly operator*(Poly b);
    Poly(){
        first = nullptr;
    }
};

void Poly::add_poly(int zarib, int tavan) {
    if (zarib == 0) return;

    Node* newNode{new Node()};
    newNode->zarib = zarib;
    newNode->tavan = tavan;
    newNode->next = nullptr;

    if (!first) {
        first = newNode;
        return;
    }

    Node* current{first};
    Node* prev{nullptr};

    while (current !=nullptr && current->tavan > tavan) {
        prev = current;
        current = current->next;
    }


    if (current != nullptr && current->tavan == tavan) {
        current->zarib += zarib;
        delete newNode;

        if (current->zarib == 0) { 
            if (prev != nullptr)
                //connect the list after removing a node
                prev->next = current->next;
            else
                first = current->next;
            delete current;
        }
        return;
    }

    newNode->next = current;
    //check if it was the first member of the list
    if (prev != nullptr)
        prev->next = newNode;
    else
        first = newNode;
}

void Poly::print() {
    if (first == nullptr) {
        cout << "0\n";
        return;
    }

    Node* p = first;

    while (p != nullptr) {
        cout << p->zarib;

        if (p->tavan != 0)
            cout << "x";
        if (p->tavan > 1)
            cout << "^" << p->tavan;

        cout << " ";
        p = p->next;
    }

    cout << '\n';
}

Poly Poly::operator+(Poly b) {
    Poly r;
    Node* p=first;
    Node* q=b.first;
    while(p&&q) {
        if(p->tavan==q->tavan) {
            r.add_poly(p->zarib+q->zarib,p->tavan);
            p=p->next;
            q=q->next;
        } else if(p->tavan>q->tavan) {
            r.add_poly(p->zarib,p->tavan);
            p=p->next;
        } else {
            r.add_poly(q->zarib,q->tavan);
            q=q->next;
        }
    }
    while(p) {
        r.add_poly(p->zarib,p->tavan);
        p=p->next;
    }
    while(q) {
        r.add_poly(q->zarib,q->tavan);
        q=q->next;
    }
    return r;
}

Poly Poly::operator*(Poly b) {
    Poly r;
    for(Node* p=first; p; p=p->next)
        for(Node* q=b.first; q; q=q->next)
            r.add_poly(p->zarib*q->zarib,p->tavan+q->tavan);
    return r;
}

int main() {
    Poly first, second;

    first.add_poly(3, 3);  
    first.add_poly(2, 0); 

    second.add_poly(6, 2);  
    second.add_poly(-10, 1 );

    Poly m{first * second};
    Poly s{first + second};

    m.print(); 
    s.print();
}
