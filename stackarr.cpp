class Stack{
  int arr[100000];
  int top{};

  public:
    Stack(){
      top = -1;
    }
    bool isEmpty(){
      return top == -1;
    }
    void push(int x){
      arr[++top] = x;
    }
    void pop(){
      if(!isEmpty())
        top--;
    }
    int peek(){
      if(!isEmpty())
        return arr[top];
    return -1;
    }    
};
