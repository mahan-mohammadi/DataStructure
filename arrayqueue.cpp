/*while this queue can reuse old space when fully empty
it still might run out of space when there is even one element and the two
pointers are at the end of the queue ar. imagine we have 100 sized array
our last element is in the index 99. we are wasting the other 99 empty elements of the
array for that one element in the end. so it is better to use the circular design
*/


class Queue{
  int front;
  int back;
  int *arr;
  int size;

  public:
    Queue(){
      front = -1;
      back = -1;
      size = 0;
    }
    Queue(int size){
      this->size = size;
      arr = new int[size];
      front = -1;
      back = -1;
    }
    bool isEmpty(){
      return front == -1 || front > back ;
    }
    bool isFull(){
      return back == size - 1;
    }
    // add value
    void enqueue(int val){
      if(isFull()){
        return;
      }
      if(isEmpty()){
        front++;
      }
      arr[++back] = val;
    }
    int dequeue(){
      if(isEmpty()){
        return -1;
      }

      /*we didnt immediatly return the answer because if the
        queue becomes empty then we have to reset the back
         and front to zero to not watse space the front++
          makes front higer than the back
          (in a queue with one element both pointers point to one element)
           so the isempty returns true 
      */
      
      int ans =  arr[front++];

      if(isEmpty()){
        front = back = -1;
      }

      return ans;
    }
    ~Queue(){
      delete[] arr;
    }
};
