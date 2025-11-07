
#include <iostream>
using namespace std;

class Node {
    friend class List;
    int data{};
    Node* next{};
};

class List {
    Node* head{};
    void recursive_reverse(Node* p){
      if(p->next == nullptr ){
        head = p;
        return;
      }
      recursive_reverse(p->next);
      Node* q = p->next;
      q->next = p;
      p->next = nullptr;
    }
public:
    void push(int val) {
        Node* n = new Node;
        n->data = val;
        n->next = head;
        head = n;
    }
    void reverse() {
      recursive_reverse(head);
    }
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
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
