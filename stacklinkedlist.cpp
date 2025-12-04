class Node{ 
  friend class Stack;
  Node* next{};
  int val{};
  public:
    Node(){
      next = nullptr;
      val = 0;
    }
};

class Stack{
  Node* top{};
  public:
    Stack(){
      top = nullptr;
    }
    ~Stack(){
      while(top!= nullptr){
        Node* ptr = top->next;
        delete top;
        top = ptr;
      }
    }
    bool isEmpty(){
      return !top;
    }

    void push(int x){
      Node *newNode{new Node()};
      newNode->val = x;

      if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
        return;
      }
      
      newNode->next = top;
      top = newNode;
    }

    void pop(){
      if(isEmpty()){
        return;
      }
      
      if(top->next == nullptr){
        delete top;
        top = nullptr;
        return;
      }

      Node* p = top->next;
      delete top;
      top = p;
    }

    int peek(){
      if(isEmpty()){
        return -1;
      }
      return top->val;
    }
};
