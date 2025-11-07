
#include <iostream>
using namespace std;

class Node {
    friend class List;
    int data{};
    Node* next{};
    Node* prev{};
};

class List {
    Node* head{};
public:
    void push(int val) {
        Node* n = new Node;
        n->data = val;
        n->next = head;
        n->prev = nullptr;
        if (head) head->prev = n;
        head = n;
    }

    void reverse() {
        Node* curr = head;
        Node* temp = nullptr;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp)
            head = temp->prev;
    }

    void print() {
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    List l;
    for (int i = 1; i <= 5; ++i) l.push(i);
    l.print();
    l.reverse();
    l.print();
}
