#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.

https://projecteuler.net/problem=1
*/
int main(int argc,char**argv) {
    int counter1=0;
    int counter2=0;
    int sum=0;
    while (counter1<1000||counter2<1000) {
        counter1+=3;
        if (counter1!=counter2&&counter1<1000) {
            sum+=counter1;
            printf("Sum is %d (+%d) [3]\n",sum,counter1);
        }
        if (counter1>counter2) {
            counter2+=5;
            if (counter1!=counter2&&counter2<1000) {
                sum+=counter2;
                printf("Sum is %d (+%d) [5]\n",sum,counter2);
            }
        }
    }
    printf("%d",sum);
    return 0;
}