#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/*
    A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

    A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

    As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

    Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

    https://projecteuler.net/problem=23
*/

int main(int argc,char**argv) {
    //First find all abundant numbers.
    //Then iterate through all abundant numbers and determine which numbers are made with them. Numbers not found are to be summed together.
    int*abundantNumbers=malloc(sizeof(int)*0);
    int abundantNumberCount=0;
    for (int i=1;i<=28123;i++) {
        int factorSum=1;
        //Iterate through divisors.
        int max=i/2;
        for (int j=2;j<max;j++) {
            if (i%j==0) {
                factorSum+=j;
                if (j!=i/j) {
                    factorSum+=i/j;
                }
                max=i/j;
            }
        }
        if (factorSum>i) {
            //printf("%d is abundant...\n",i);
            abundantNumbers=realloc(abundantNumbers,sizeof(int)*(++abundantNumberCount));
            abundantNumbers[abundantNumberCount-1]=i;
        }
    }
    //Next is to sum up all integers up to 28124.
    long sum=0;
    for (int i=0;i<28124;i++) {
        sum+=i;
    }
    printf("Sum of all numbers is %ld\n",sum);

    boolean removed[28124] = {};
    
    for (int i=0;i<abundantNumberCount;i++) {
        for (int j=0;j<abundantNumberCount;j++) {
            int su=abundantNumbers[i]+abundantNumbers[j];
            if (su<28124&&!removed[su]) {
                sum-=su;
                removed[su]=true;
                printf("Removed %d...\n",su);
            }
        }
    }

    printf("Sum of only non-summed abundant integers is %ld",sum);
    return 0;
}