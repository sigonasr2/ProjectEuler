#include <stdio.h>
#include "utils.h"

/*
    A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

    012   021   102   120   201   210

    What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

    https://projecteuler.net/problem=24
*/

void carryover(int*arr,int digit) {
    arr[digit]=0;
    if (arr[digit-1]==9) {
        carryover(arr,digit-1);
    } else {
        arr[digit-1]++;
    }
}

void incrementDigit(int*arr) {
    int val = arr[9];
    if (arr[9]==9) {
        carryover(arr,9);
    } else {
        arr[9]++;
    }
}

boolean allUniqueDigits(int*arr) {
    boolean digits[10] = {};
    for (int i=0;i<10;i++) {
        if (!digits[arr[i]]) {
            digits[arr[i]]=true;
        } else {
            return false;
        }
    }
    return true;
}

int factorial(int numb) {
    int final=1;
    for (int i=numb;i>=1;i--) {
        final*=i;
    }
    return final;
}

int main(int argc,char**argv) {

    //For permutations, we know that there are a total of N! permutations.
    //  Which means each individual set starts at N!/N. So we can skip ahead some permutations.
    //  For 10 numbers, we get 362,880 values per permutation set. So 1000000/362880 = 2. So we'll start at permutation two.
    int setPermutationCount=factorial(10)/10;
    int permutationCount=(1000000/setPermutationCount)*setPermutationCount;
    int digits[10]={2,0,1,3,4,5,6,7,8,9};
    while ((digits[0]!=9||digits[1]!=8||digits[2]!=7||digits[3]!=6||digits[4]!=5||digits[5]!=4||digits[6]!=3||digits[7]!=2||digits[8]!=1||digits[9]!=0)&&permutationCount!=999999) {
        incrementDigit(digits);
        if (allUniqueDigits(digits)) {
            permutationCount++;
            printf("%d:",permutationCount);
            for (int i=0;i<10;i++) {
                printf(" %d ",digits[i]);
            }
            printf("\n");
        }
    }

    printf("\n\nThe one millionth lexicographic permutation is: \n\t");
    for (int i=0;i<10;i++) {
        printf("%d",digits[i]);
    }

    
    return 0;
}