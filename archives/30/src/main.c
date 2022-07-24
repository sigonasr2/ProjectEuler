#include <stdio.h>
#include "utils.h"
#include <math.h>

/*
    Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

        1634 = 14 + 64 + 34 + 44
        8208 = 84 + 24 + 04 + 84
        9474 = 94 + 44 + 74 + 44

    As 1 = 14 is not a sum it is not included.

    The sum of these numbers is 1634 + 8208 + 9474 = 19316.

    Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.


    https://projecteuler.net/problem=30
*/

int main(int argc,char**argv) {
    int counter=0;
    int currentDigit=10;
    long digitSum=0;
    while (counter<10000000) {
        int tempNumb=currentDigit;
        digitSum=0;
        long val=0;
        while (tempNumb>0) {
            int digit=tempNumb%10;
            tempNumb/=10;
            val=(long)pow(digit,5);
            digitSum+=val;
            if (digitSum>currentDigit) {
                goto next;
            }
        }
        if (digitSum==currentDigit) {
            printf("%d has a digit sum that equals its number!\n",currentDigit);
        }
        next:
        currentDigit++;
        counter++;
    }

    
    return 0;
}