#include <iostream>
using namespace std;

class Node {
    friend class List;
    int data{};
    Node* next{};
    Node* prev{};
};

class List {
    Node* first{};
public:
    void push(int value) {
        Node* newNode{new Node};
        newNode->data = value;
        newNode->next = first;
        newNode->prev = nullptr;
        if (first) 
            first->prev = newNode;
        first = newNode;
    }

    void reverse() {
        Node* current{first};
        Node* temp{nullptr};
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp)
            first = temp->prev;
    }

    void print() {
        Node* t{first};
        while (t) {
            cout << t->data << ",";
            t = t->next;
        }
        cout << "\n";
    }
};

int main() {
    List l;
    for (int i = 11; i <= 20; i++) 
        l.push(i);
    l.print();
    l.reverse();
    l.print();
}
