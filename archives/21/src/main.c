#include <stdio.h>
#include "utils.h"

/*
    Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
    If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

    For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

    Evaluate the sum of all the amicable numbers under 10000.

    https://projecteuler.net/problem=21
*/

int main(int argc,char**argv) {
    int counter=1;
    long totalSum=0;
    while (counter<10000) {
        //printf("Factor sum of %d: 1,",counter);
        int factorSum=1;
        int max=counter/2;
        for (int i=2;i<max;i++) {
            if (counter%i==0) {
                factorSum+=i;
                if (i!=(counter/i)) {
                    factorSum+=counter/i;
                }
                max=counter/i;
                //printf("%d,%d,",i,counter/i);
            }
        }
        //printf("\n");
        int factorSum2=1;
        max=factorSum/2;
        for (int i=2;i<max;i++) {
            if (factorSum%i==0) {
                factorSum2+=i;
                factorSum2+=factorSum/i;
                max=factorSum/i;
            }
        }
        if (factorSum!=factorSum2&&counter==factorSum2) {
            printf("%d\n",counter);
            totalSum+=counter;
        }
        counter++;
    }
    printf("\n\nAmicable Number sum: %ld",totalSum);
    return 0;
}