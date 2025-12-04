#include <stdio.h>


class Term{
    
    friend class poly;
    int coeff{};
    int deg{};
    public:
    Term(){
        coeff=0;
        deg = 0;
    }
    Term(int coeff , int deg){
        this->coeff = coeff;
        this->deg = deg;
    }
};


class poly{
    Term* termArr{};
    int size{};
    int capacity{};

    public:
    poly(int size){
        termArr = new Term[size]{};
        this->size = size;
        capacity = 0;
    }
    void addTerm(Term t){

        // intilzie to capacity so if we dont find anything !!!!
        int index = capacity;
        for(int i=0 ; i < capacity ; i++){

            if(termArr[i].deg < t.deg){
                index = i;
                break;
            }
        }
        int lastIndex = capacity -1;
        
        for(int i = lastIndex ; i >= index ; i--){
            termArr[i+1] = termArr[i];
        }

        capacity++;
        termArr[index] = t;
    }

    void print(){
        for(int i=0 ; i < capacity ; i++){
            printf("%dx^%d + " , termArr[i].coeff , termArr[i].deg);
        }
        printf("\n");
    }

    poly add(poly p){
        
        int newSize = capacity + p.capacity;
        poly res(newSize);


        int i = 0 , j = 0;

        while(i < capacity && j < p.capacity){
            if(termArr[i].deg == p.termArr[j].deg){
                res.addTerm(Term(termArr[i].coeff + p.termArr[j].coeff , termArr[i].deg));
                i++;
                j++;
            }
            else if(termArr[i].deg > p.termArr[j].deg){
                res.addTerm(Term(termArr[i].coeff , termArr[i].deg));
                i++;
            }
            else {
                res.addTerm(Term(p.termArr[j].coeff , p.termArr[j].deg));
                j++;
            }
        }

        while(i < capacity){
             res.addTerm(Term(termArr[i].coeff , termArr[i].deg));
                i++;
        }
        while(j< p.capacity) {
                res.addTerm(Term(p.termArr[j].coeff , p.termArr[j].deg));
                j++;
        }
        return res;
    }
};


int main(){


    poly p(3);
    p.addTerm(Term(1,5));
    p.addTerm(Term(3,0));
    p.print();

    poly k(3);
    k.addTerm(Term(1,1000));
    k.addTerm(Term(1,5));
    k.addTerm(Term(1,3));
    k.print();

    poly sum = p.add(k);
    sum.print();

    return 0;
}
