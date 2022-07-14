#include <stdio.h>
#include <stdlib.h>

/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

https://projecteuler.net/problem=4
*/

struct String{
    int length;
    char*str;
};

struct String numberToString(int numb) {
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
    struct String str={placeValues,finalStr};
    return str;
}

int main(int argc,char**argv) {
    int numb1=999;
    int numb2=999;
    int maxPal=0;

    printf("%s : %d",numberToString(numb1*numb2).str,numberToString(numb1*numb2).length);

    /*
    if (isPalindrome(numberToString(numb1*numb2))) {
        printf("%d is a Palindrome!",numb1*numb2);
    }*/

    return 0;
}