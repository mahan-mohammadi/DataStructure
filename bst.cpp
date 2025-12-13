class Node{
  friend class BST;
  int value;
  Node* left;
  Node* right;

  public:
    Node(int val){
      value = val;
    }

    
};


class BST{
  Node* root;

  void insert(int val){
    Node* n = new Node(val);
    
    
  }

  Node* find(int key){
    Node* curr = root;

    while( curr!= nullptr){
      if(curr ->value == key){
        return curr;
      }
      else if(curr->value < key){
        curr = curr->right;
      }
      else{
        curr = curr->left;
      }
    }
    return curr;
  }

  Node* succ(Node * n){
    n = n->right;
    while(n->left != nullptr){
      n = n->left;
    }
    return n;
    
  }

  void recursiveremove(int key , Node* root){
    Node* found = find(key);
    //todelete is seprated so we can replace the location it points to..... to be deleted removes the previous location data
    Node* todelete = found;

    if(found != nullptr){
      if(found->right == nullptr){
        found = found->left;
        delete todelete;
      }
      else if(found->left== nullptr){
        found = found -> right;
        delete todelete;
      }
      else{
        Node* s = succ(found);

        //we replace the values (litreallly)
        found->value = s->value;
        //since the succ is in the right tree it is only needed to search there
        recursiveremove(s->value , found->right);
      }
    }
  }

  void remove(int key){
    recursiveremove(key,root);
  }
  
};
