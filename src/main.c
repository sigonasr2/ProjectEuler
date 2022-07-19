#include <stdio.h>
#include "utils.h"

/*
    A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

    012   021   102   120   201   210

    What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

    https://projecteuler.net/problem=24
*/

void generate(int*a,int count,boolean useNextHighest) {
    for (int i=0;i<10;i++) {
        int*newArr=malloc(sizeof(int)*(count+1));
        newArr[i]=i;
        generate(newArr,count+1,true);
        generate(newArr,count+1,false);
    }
}

int main(int argc,char**argv) {
    //X * (2^(X-2))
    //0
        //01
        //02
        //03
        //04
        //05
        //06
        //07
        //08
        //09
    //10
        //123
            //124
    //20
        //21
    //3
    //4
    //5
    //6
    //7
    //8
    //9

    boolean useNextHighest=true; //If this is true, use the next consecutive digit, otherwise skip one.
    int*numbs=malloc(sizeof(int)*0);
    generate(numbs,count,true);

    
    return 0;
}