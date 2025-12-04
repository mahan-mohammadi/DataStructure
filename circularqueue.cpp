class queue{
  int front;
  int back;
  int *arr;
  int max;
  
  public:
    queue(int size){
      arr = new int[size];
      this->max= size;
      back = 0;
      front = 0;
    }
    void enqueue(int val){
      if(isFull()){
        return;
      }
      arr[back] = val;
      back = (back + 1)%max; 
    }


    int dequeue(){
      if(isEmpty()){
        return -1;
      }
      int ans = arr[front];
      front = (front + 1) % max;
      return ans;
    }

    bool isEmpty(){
      return front == back;
    }

    bool isFull(){
      return (back +1)%max == front;
    }
    
};
