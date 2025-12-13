#include <iostream>

class minheap{
  //we need both capacity and size so that we can have the location to the new node we want to insert
  int capacity;
  int size;
  int *arr;

  public:
    minheap(int capacity){
      this->capacity = capacity+1;
      arr = new int[this->capacity]{};
      size = 0;
    }

    void insert(int val){
      arr[++size] = val;
      int i = size;
      //not i >= since that would result to zero
      while(i >  1){
        if(arr[i/2] > arr[i]){
          int swap = arr[i/2];
          arr[i/2] = arr[i];
          arr[i] = swap;

          i /= 2;
        }
        else{
          return;
        }
      }
    }


void remove() {
    if (size == 0) return; // nothing to remove

    arr[1] = arr[size];
    size--;

    int i = 1;

    while (i * 2 <= size) {   // while at least one child exists if i*2 doesnt exist so wont the i*2+1
        int left = i * 2;
        int right = i * 2 + 1;

        int s = left;

        // choose the smaller child (if right child exists)
        if (right <= size && arr[right] < arr[left]) {
            s = right;
        }

        // if parent is already smaller, heap property satisfied
        if (arr[i] <= arr[s]) {
            return;
        }

        // swap parent with smaller child
        int tmp = arr[i];
        arr[i] = arr[s];
        arr[s] = tmp;

        i = s; // move down
    }
}
    
};
