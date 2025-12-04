#include <stdio.h>



class matrixTerm{
  friend class matrixSparse;
  int col{} , row{} , val{};
  matrixTerm(){
    
  }
  public:
  matrixTerm(int col , int row , int val){
    this->col = col;
    this->val = val;
    this->row = row;
  }
};

class matrixSparse{
  int rows{} , cols{} , terms{}/*non zero terms*/ , capacity{};
    
  matrixTerm* termArr{};
    public:
  matrixSparse(int rows , int cols , int capacity){
    this->rows = rows;
    this->cols = cols;
    this->capacity = capacity;
    termArr = new matrixTerm[capacity]{};
    //terms = 0;
  }

  void addTerm(matrixTerm other){
    int i=0;
    /*
    ignore this plz sadegh!!! this comment is for my study
    dont use this kind of logic !!!!!!!!!
    while(other.row >= termArr[i].row){
      i++;
    }
    */

    while(i < terms){                          // VERY IMPORTANT !!!!!!!!!!!!!
      if(other.row > termArr[i].row){
        i++;
        continue;
      }
      else if(other.row == termArr[i].row){
        if(other.col > termArr[i].col){
          i++;
          continue;
        }
      }
      break;
    }
    int lastIndex = terms -1;

    for(int k = lastIndex ; k >= i ; k--){
      termArr[k+1] = termArr[k];
    }

    termArr[i] = other;
    terms++;
    
  }

  
  void displayTerms() {
        printf("Sparse Matrix Terms (R, C, V): \n");
        for (int k = 0; k < terms; k++) {
            printf("(%d, %d, %d)\n", termArr[k].row, termArr[k].col, termArr[k].val);
        }
        printf("Total Terms: %d, Capacity: %d\n", terms, capacity);
    }   
  matrixSparse transpose(){

    matrixSparse s(cols , rows , capacity);

    for(int i=0 ; i < cols ; i++){
      for(int j=0 ; j < terms ; j++){
        if(termArr[j].col == i){
          s.addTerm(matrixTerm(termArr[j].row , i , termArr[j].val));
        }
      }
    }


    return s;
  }
};



int main(){


    matrixSparse m(5, 5, 2);     
    m.addTerm(matrixTerm(1, 2, 50)); 
    m.addTerm(matrixTerm(3, 2, 10)); 

    m.displayTerms();  
  return 0;
}
