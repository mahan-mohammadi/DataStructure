#include <iostream>
using namespace std;

class Node {
    friend class List;
private:
    int data{};
    Node* next{};
};

class List {
private:
    Node* last{};
public:
    int remove_from_beginning();
    int remove_from_end();
    int remove_after_node(Node*);
    void add_from_beginning(int);
    void add_from_end(int);
    void add_after_node(Node*, int);
    int size();
    void print();
};

void List::add_from_beginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!last) { 
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void List::add_from_end(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (!last) { 
        last = newNode;
        last->next = last;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

void List::add_after_node(Node* node, int value) {
    if (!node) {
        cout << "Invalid node pointer\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = node->next;
    node->next = newNode;
    if (node == last)
        last = newNode;
}

int List::remove_from_beginning() {
    if (!last) {
        cout << "List is empty\n";
        return -1;
    }

    Node* first = last->next;
    int val = first->data;

    if (first == last) { 
        delete first;
        last = nullptr;
    } else {
        last->next = first->next;
        delete first;
    }

    return val;
}

int List::remove_from_end() {
    if (!last) {
        cout << "List is empty\n";
        return -1;
    }

    Node* current = last->next;
    int val = last->data;

    if (current == last) { 
        delete last;
        last = nullptr;
    } else {
        while (current->next != last)
            current = current->next;
        current->next = last->next;
        delete last;
        last = current;
    }

    return val;
}

int List::remove_after_node(Node* node) {
    if (!node || !last) {
        cout << "Invalid operation\n";
        return -1;
    }

    Node* temp = node->next;
    int val = temp->data;

    if (temp == node && temp == last) {
        delete temp;
        last = nullptr;
        return val;
    }

    node->next = temp->next;
    if (temp == last)
        last = node;
    delete temp;

    return val;
}

int List::size() {
    if (!last) return 0;
    int count = 0;
    Node* current = last->next;
    do {
        count++;
        current = current->next;
    } while (current != last->next);
    return count;
}

void List::print() {
    if (!last) {
        cout << "List is empty\n";
        return;
    }
    Node* current = last->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != last->next);
    cout << endl;
}

int main() {
    List l;
    l.add_from_end(4);
    l.add_from_end(20);
    l.add_from_beginning(1000);
    l.print(); 

    cout << l.remove_from_beginning() << endl;
    l.print(); 

    cout << l.remove_from_end() << endl; 
    l.print();  

    cout << "Size: " << l.size() << endl;
}
