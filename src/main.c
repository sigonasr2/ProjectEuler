#include <stdio.h>
#include <stdlib.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

https://projecteuler.net/problem=4
*/

char*numberToString(int numb) {
    int placeValues=0;
    int tempNumb=numb;
    while (tempNumb>0) {
        tempNumb/=10;
        placeValues++;
    }
    char*finalStr=malloc(placeValues+1);
    tempNumb=numb;
    int marker=placeValues-1;
    while (tempNumb>0) {
        finalStr[marker--]='0'+(tempNumb%10);
        tempNumb/=10;
    }
    return finalStr;
}

int main(int argc,char**argv) {
    int numb1=999;
    int numb2=999;
    int maxPal=0;

    printf("S:%s",numberToString(numb1));

    return 0;
}