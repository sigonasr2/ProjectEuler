#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/*
    n! means n × (n − 1) × ... × 3 × 2 × 1

    For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
    and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

    Find the sum of the digits in the number 100!


    https://projecteuler.net/problem=20
*/


int digitCount(int numb) {
    int digitCount=1;
    while (numb>=10) {
        numb/=10;
        digitCount++;
    }
    return digitCount;
}

char*numberToString(int numb) {
    char*num=malloc(digitCount(numb));
    int counter=digitCount(numb)-1;
    while (numb!=0) {
        num[counter--]=(numb%10)+'0';
        numb/=10;
    }
    return num;
}

int main(int argc,char**argv) {
    struct String factorialSum = {1,"1"};
    int counter=2;
    while (counter<=100) {
        factorialSum=mult(factorialSum,(struct String){digitCount(counter),numberToString(counter)});
        printf("%s\n",factorialSum.str);
        counter++;
    }

    printf("%s",factorialSum.str);
    int digitSum=0;
    for (int i=0;i<factorialSum.length;i++) {
        digitSum+=factorialSum.str[i]-'0';
    }
    printf("\nThe sum of the digits are %d",digitSum);

    return 0;
}