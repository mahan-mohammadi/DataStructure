#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack;

template <typename T>
class Node {

    template <typename> friend class Stack;
private:

    T data{};
    Node<T>* next{};
public:
    Node(T new_data) : data(new_data), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    Node<T>* head{};
public:
    Stack() : head(nullptr) {}
    bool isEmpty() {
        if(head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    void push(T new_data) {
        Node<T>* newNode{new Node<T>{new_data}};
        newNode->next = head;
        head = newNode;
    }

    T top() {

        if (isEmpty()) {
            cout << "stack is empty. returning default value\n";
            return T{};
        }
        return head->data;
    }
    T pop() {
        if(isEmpty()) {
            cout << "stack is empty. can't pop anything so return the default value \n";
            return T{};
        }
        Node<T>* temp = head;
        T value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int priority(char c) {
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string InfixToPostfix(string s) {
    Stack<char> st{};
    string result{};

    for(int i = 0 ; s[i] ; i++ ) {

        if ((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z'))
            result += s[i];

        else if(s[i] == '(')
            st.push('(');

        else if (s[i] == ')') {
            while (!st.isEmpty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else {

            while (!st.isEmpty() && st.top() != '(' &&
                    priority(st.top()) >= priority(s[i])) {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.isEmpty()) {
        result += st.top();
        st.pop();
    }

    return result;
}


string PostfixToInfix(string s) {

    Stack<string> st{};
    string result{};

    for(int i=0 ; s[i] ; i++) {
        if(s[i] <= 'z' && s[i] >= 'a'||
                s[i] <= 'Z' && s[i] >= 'A')
            st.push(string{s[i]});
        //to check if something is a operator or not i can also use the priority function instead of a big if
        else if(priority(s[i]) != -1) {
            string second{st.pop()};
            string first{st.pop()};
            st.push("(" + first + s[i] + second + ")");
        }
    }

    result = st.pop();

    return result;


}



string reverse(string s) {

    string result{};
    char*last{&s[0]};
    while(*last) {
        last += sizeof(s[0]);
    }
    last-=sizeof(s[0]);

    while(&s[0] <= last) {
        if(*last == '(') {
            result.push_back(')');
        }
        else if(*last == ')') {
            result.push_back('(');
        }
        else {
            result.push_back(*last);
        }
        last -= sizeof(s[0]);

    }

    return result;
}

string InfixToPrefix(string s) {
    string reversed{reverse(s)};
    string postfix{InfixToPostfix(reversed)};
    return reverse(postfix);
}


string PrefixToInfix(string s) {
    Stack<string> st{};
    int last{s.length()-1};
    for(int i = last ; i >= 0 ; i--) {
        if(s[i] <= 'z' && s[i] >= 'a'||
                s[i] <= 'Z' && s[i] >= 'A')
            st.push(string{s[i]});
        else if(priority(s[i]) != -1) {
            string first{st.pop()};
            string second{st.pop()};
            st.push("(" + first + s[i]  + second + ")");
        }
    }
    return st.pop();
}

int main() {
    string infix{"a*(b+c)/d+e"};
    string postfix{InfixToPostfix(infix)};
    cout << postfix << '\n';
    string infix2{PostfixToInfix(postfix)};
    cout << infix2 << '\n';
    string prefix{InfixToPrefix(infix)};
    cout << prefix << '\n';
    string infix3{PrefixToInfix(prefix)};
    cout << infix3 << '\n';

}
