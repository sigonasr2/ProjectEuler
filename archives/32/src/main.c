#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/*
    We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

    The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

    Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

    HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

    https://projecteuler.net/problem=32
*/

int main(int argc,char**argv) {
    int numb1=1;
    int numb2=1;
    long sumPandigital=0;
    boolean*uniqueProducts = malloc(100000000);
    for (int i=0;i<100000000;i++) {
        uniqueProducts[i]=false;
    }
    for (numb1=1;numb1<10000;numb1++) {
        for (numb2=1;numb2<10000;numb2++) {
            int prod=numb1*numb2;
            int numb=prod;
            boolean uniqueDigits[9] = {};
            while (numb>0) {
                int digit=numb%10-1;
                if (digit!=-1&&!uniqueDigits[digit]) {
                    uniqueDigits[digit]=true;
                } else {
                    goto skip;
                }
                numb/=10;
            }
            numb=numb1;
            while (numb>0) {
                int digit=numb%10-1;
                if (digit!=-1&&!uniqueDigits[digit]) {
                    uniqueDigits[digit]=true;
                } else {
                    goto skip;
                }
                numb/=10;
            }
            numb=numb2;
            while (numb>0) {
                int digit=numb%10-1;
                if (digit!=-1&&!uniqueDigits[digit]) {
                    uniqueDigits[digit]=true;
                } else {
                    goto skip;
                }
                numb/=10;
            }
            for (int i=0;i<9;i++) {
                if (!uniqueDigits[i]) {
                    goto skip;
                }
            }
            //If we got here it's a pandigital.
            if (!uniqueProducts[prod]) {
                uniqueProducts[prod]=true;
                sumPandigital+=prod;
                printf("\n%d*%d = %d is pandigital!",numb1,numb2,prod);
            }
            skip:
            continue;
        }
    }
    printf("\nSum of pandigitals: %ld",sumPandigital);
    return 0;
}
