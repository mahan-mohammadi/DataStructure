#include <iostream>
using namespace std;

class Node {
    friend class Poly;
  private:
    int coef{};
    int exp{};
    Node* next{};
};

class Poly {
  private:
    Node* head{};
  public:
    void add_term(int c,int e);
    void print();
    Poly sum(Poly& b);
    Poly mul(Poly& b);
};

void Poly::add_term(int c, int e) {
    if (c == 0) return;

    Node* n = new Node;
    n->coef = c;
    n->exp = e;

    if (!head || e > head->exp) {
        n->next = head;
        head = n;
        return;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while (curr && curr->exp > e) {
        prev = curr;
        curr = curr->next;
    }

    if (curr && curr->exp == e) {
        curr->coef += c;
        delete n;
        if (curr->coef == 0) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            curr->next = nullptr;
            delete curr;
        }
    } else {
        n->next = curr;
        if (prev) prev->next = n;
        else head = n;
    }
}
void Poly::print() {
    if(!head) {
        cout<<"0\n";
        return;
    }
    Node* p=head;
    bool first=true;
    while(p) {
        if(!first&&p->coef>0) cout<<"+";
        first=false;
        if(p->exp==0) cout<<p->coef;
        else if(p->exp==1) {
            if(p->coef==1) cout<<"x";
            else if(p->coef==-1) cout<<"-x";
            else cout<<p->coef<<"x";
        } else {
            if(p->coef==1) cout<<"x^"<<p->exp;
            else if(p->coef==-1) cout<<"-x^"<<p->exp;
            else cout<<p->coef<<"x^"<<p->exp;
        }
        p=p->next;
    }
    cout<<endl;
}

Poly Poly::sum(Poly& b) {
    Poly r;
    Node* p=head;
    Node* q=b.head;
    while(p&&q) {
        if(p->exp==q->exp) {
            r.add_term(p->coef+q->coef,p->exp);
            p=p->next;
            q=q->next;
        } else if(p->exp>q->exp) {
            r.add_term(p->coef,p->exp);
            p=p->next;
        } else {
            r.add_term(q->coef,q->exp);
            q=q->next;
        }
    }
    while(p) {
        r.add_term(p->coef,p->exp);
        p=p->next;
    }
    while(q) {
        r.add_term(q->coef,q->exp);
        q=q->next;
    }
    return r;
}

Poly Poly::mul(Poly& b) {
    Poly r;
    for(Node* p=head; p; p=p->next)
        for(Node* q=b.head; q; q=q->next)
            r.add_term(p->coef*q->coef,p->exp+q->exp);
    return r;
}

int main() {
    Poly a, b;

    // Manually add terms
    a.add_term(3, 2);  // 3x^2
    a.add_term(1, 0);  // +1

    b.add_term(2, 1);  // 2x
    b.add_term(-1, 0); // -1

    Poly s = a.sum(b);
    Poly m = a.mul(b);

    s.print(); // expected: 3x^2 + 2x + 0  -> prints: 3x^2+2x
    m.print(); // expected: (3x^2 + 1)*(2x -1)
}
