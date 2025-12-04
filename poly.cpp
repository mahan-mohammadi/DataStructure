#include <stdio.h>


class poly{
  int size;
  int *terms;
  public:
  poly(){
    size =0;
  }
  poly(int maxDeg){
    size = maxDeg+1;
    terms = new int[size]{};
  }




  //this one is important we use terms[i] becasue size-1-i would revrese the array again
  void print(){
    for(int i=0 ; i< size ; i++){
      printf("%dx^%d + ",terms[i] , size-1-i);
    }
    printf("\n");
  }

  void setTerm(int deg , int coeff){
    if(deg < size){
      terms[size-1-deg] = coeff;
    }
  }


  poly add(poly other){
    int deg1 = size-1;
    int deg2 = other.size-1;
    int maxDeg;

    int maxSize = (size > other.size) ? size : other.size;
    poly res(maxSize - 1); // degree = maxSize-1
    int i = 0 ,j =0 , k=0;;
    while(i <= deg1 && j <= deg2){
      int pow1 = deg1- i;
      int pow2 = deg2 - j;

      if(pow1 == pow2){
        res.terms[k] = terms[i] + other.terms[j];
        i++;
        j++;
      }
      else if(pow1 > pow2){
        res.terms[k] = terms[i];
        i++;
      }
      else{
        res.terms[k] = other.terms[j];
        j++;
      }
      k++;
    }    

      while(i<=deg1){
        res.terms[k] = terms[i];
        i++;
        k++;
      }

      while(j<=deg2){
        res.terms[k] = other.terms[j];
        j++;
        k++;
      }


    return res;
  }
};





int main() {
    poly p(3);
    p.setTerm(0, 1);
    p.setTerm(1, 2);
    p.setTerm(3, 5);

    p.print();
    poly k(3);
    k.setTerm(0, 1);
    k.setTerm(1, 2);
    k.setTerm(3, 5);
    
    printf("Polynomial K: ");
    k.print();

    poly sum;
    sum = k.add(p);
    
    printf("Sum: ");
    sum.print();
}
