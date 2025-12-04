class Node{
  friend class queue;
  int val = 0;
  Node* ptr = nullptr;
};

class queue{
  Node* front;
  Node* rear;
  public:
    queue(){
      front = rear = nullptr;
    }
    bool isEmpty(){
      if(front == nullptr){
        return true;
      }
      else{
        return false;
      }
    }
    void enqueue(int val){
      Node * newNode = new Node();
      newNode->val = val;
      if(isEmpty()){
        front = rear = newNode;
        newNode->ptr = nullptr;

        return;
      }
      rear->ptr = newNode;
      rear = newNode;
    }

    int dequeue(){
      if(isEmpty()){
        return -1;
      }
      Node *temp = front; //since it need to be deleeted but also updated
      int ans = temp->val;
      front = front->ptr;
      if(front == nullptr){
        rear = nullptr; //since then the list becomes empty and we need to show it in the structure
      }
      delete temp;
      return ans;
    }
};
