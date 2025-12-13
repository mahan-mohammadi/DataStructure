#include <cstdio>
#include <stack>

class treearr {
    int size;     // allocated size = tree size + 1
    int* arr;     // 1-based array tree

public:
    // Constructor
    treearr(int size) {
        this->size = size + 1;
        arr = new int[this->size];

        // initialize all nodes as empty (-1)
        for (int i = 0; i < this->size; i++)
            arr[i] = -1;
    }

    // Destructor
    ~treearr() {
        delete[] arr;
    }

    // Set a value at index (1-based)
    void set(int index, int value) {
        if (index < size)
            arr[index] = value;
    }

    // ----- Traversals -----

    // Inorder: left, node, right
    void inorder(int i = 1) {
        if (i >= size || arr[i] == -1) return;

        inorder(2 * i);
        printf("%d ", arr[i]);
        inorder(2 * i + 1);
    }

    void inorderiterative(){
        int i = 1;
        std::stack<int> s;
        while((arr[i] != -1 && i < size) || !s.empty()){
            if(arr[i] != -1 && i < size){
                s.push(i);
                i = i *2;
            }
            else{
                i = s.top();
                s.pop();

                printf("%d" , arr[i]);
                i = i*2 + 1;
            }
        }
        
    }


    void preorderiter(){
        //reverse the tree then preorder
    }

    // Preorder: node, left, right
    void preorder(int i = 1) {
        if (i >= size || arr[i] == -1) return;

        printf("%d ", arr[i]);
        preorder(2 * i);
        preorder(2 * i + 1);
    }

    // Postorder: left, right, node
    void postorder(int i = 1) {
        if (i >= size || arr[i] == -1) return;

        postorder(2 * i);
        postorder(2 * i + 1);
        printf("%d ", arr[i]);
    }
};

int main() {
    treearr t(10);

    // fill tree
    t.set(1, 10); // root
    t.set(2, 20); // left
    t.set(3, 30); // right
    t.set(4, 40); // left-left
    t.set(5, 50); // left-right

    printf("Inorder: ");
    t.inorder();
    printf("\n");

    printf("Preorder: ");
    t.preorder();
    printf("\n");

    printf("Postorder: ");
    t.postorder();
    printf("\n");
}
