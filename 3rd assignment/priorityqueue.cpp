#include <stdio.h>

class Node {
    friend class PriorityQueue;
    int data;
    int priority;
};

class PriorityQueue{
    Node* heap;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new Node[capacity + 1]; //+1 since zeroth index is unused
        size = 0;
    }

    void add(int val , int priority) {
        if (size == capacity) {
            return;
        }

        size++;
        heap[size].data = val;
        heap[size].priority = priority;
        int i{size};

        while (i > 1) {
            int p{i / 2}; // finding the parent index
            if (heap[p].priority < heap[i].priority) {
                Node temp{heap[p]};
                heap[p] = heap[i];
                heap[i] = temp;
                i = p;
            } else {
              //no need to compare anymore
                break;
            }
        }
    }

//we can only remove from the root node so no need for any argument
    void remove() {
        if (size == 0) {
            return;
        }

        heap[1] = heap[size];
        size--;

        int i =1;
        while (true) {
            int largest{i};
            int l{2 * i };
            int r{2 * i  + 1};

            if (l <= size && heap[l].priority > heap[largest].priority)
                largest = l;
            if (r <= size && heap[r].priority > heap[largest].priority)
                largest = r;

            if (largest != i) {
                Node temp{heap[i]};
                heap[i] = heap[largest];
                heap[largest] = temp;
                i = largest;
            } else {
                break;
            }
        }
    }

    int getTop() {
        if (size == 0) return -1; 
        return heap[1].data;
    }

};


int main(){


PriorityQueue pq(5);
pq.add(100, 2); 
pq.add(50, 5);  
pq.add(200, 1); 

printf("%d\n", pq.getTop()); 
pq.remove();
printf("%d\n", pq.getTop()); 

pq.remove();
printf("%d\n", pq.getTop()); 
}
