#include <utility>
class maxheap{
  int size;
  int capacity;
  int *arr;

  public:
    maxheap(int capacity){
      this->capacity = capacity+1;
      size = 0;
      arr = new int[this->capacity];
    }

    void add(int value){
      if(capacity != size)
        arr[++size] = value;

      int i = size;
      while(i > 1){
        if(arr[i] > arr[i/2]){
          int temp = arr[i];
          arr[i] = arr[i/2];
          arr[i/2] = temp;
        }
        else{
          break;
        }
        i/=2;
      }  
    }

    void remove(){
      if(size == 0){
        return;
      }
      arr[1] = arr[size--];

      int i=1;
      while(i*2 <= size){
        //we assume the best case scenario and put the biggest the parent index
        int biggest =i;
        //the if clauses are very important
        if(i*2 <=size && arr[i*2] > arr[biggest]){
          biggest  = i*2;
        }
        //we shouldnt use else if since both clauses might run
        if(i*2+1 <= size && arr[i*2+1] >arr[biggest]){
          biggest = i*2+1;
        }

        if(biggest != i){
          std::swap(arr[biggest] , arr[i]);
        }
        if(biggest ==i){
          return;
        }
        i = biggest;
      }
    }

    
};
