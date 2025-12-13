#include <stdio.h>


class Node
{
    friend class BST;
    Node*left{nullptr};
    Node*right{nullptr};
    int val{0};
};

class BST
{
    Node* head{nullptr};
    Node* getSucc(Node *n) {
        n = n->right;
        while(n->left != nullptr) {
            n = n->left;
        }
        return n;
    }

    void printInorder(Node* n) {
        if (!n)
        {
              return;
        }
        printInorder(n->left);
        printf("%d ", n->val);
        printInorder(n->right);
    }


    Node* searchIterative(int key){
        Node* t = head;


//we used t instead of t->left or t->right since if we found it it is not t == nullpre but key == t->val and if we dont it would return nullptr 
        while(t != nullptr || key != t->val){
            if(key  > t->val){
                t = t->right;
                
            }

            else if(key  < t->val){
                t = t->left;
            }
        }
        return t;
    }



    
    //if we dont return the modified node we can only change the
    // ptr node locally not globally and we need to edit it on the previous levlel
    // so we can update it the previous node to point to it
    Node* recursiveRemove(int val, Node * ptr) {
        if(ptr->val > val) {
            ptr->left = recursiveRemove(val,ptr->left);
        }
        else if(ptr->val < val) {
            ptr->right = recursiveRemove(val,ptr->right);
        } else {
            if(ptr->left == nullptr) {
                Node * toBeDeleted{ptr};
                ptr = ptr->right;
                delete toBeDeleted;
                return ptr;
            }
            else if(ptr->right ==nullptr) {
                Node * toBeDeleted{ptr};
                ptr = ptr->left;
                delete toBeDeleted;
                return ptr;
            }
            else {
                Node* succ{getSucc(ptr)};
                ptr->val = succ->val;
                ptr->right = recursiveRemove(succ->val, ptr->right);
            }
        }
        return ptr;
    }

public:

    void insert(int val)
    {
        Node* newNode{new Node()};
        newNode->val = val;
        if (!head) {
            head= newNode;
            return;
        }

        Node* current{head};
        Node* parent{nullptr};

        while (current) {
            parent = current;
            if (val < current->val) {
                current = current->left;
            } else if(val > current->val) {
                current = current->right;
            } else {
                return;
            }
        }

        if (val < parent->val) {
            parent->left = newNode;
        } else {
            // sicne we did return for the equality case we dont need to check for that here anymore
            parent->right = newNode;

        }
    }
    void remove(int val ) {
        head = recursiveRemove(val,head);
    }


    void print() {
        printInorder(head);
        printf("\n");
    }

};



int main() {
    BST tree{};
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.print();

    tree.remove(70);
    tree.print();
    tree.remove(50);
    tree.print();

    return 0;
}
