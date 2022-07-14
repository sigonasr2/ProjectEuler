#include <stdio.h>

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

https://projecteuler.net/problem=3
*/
int main(int argc,char**argv) {

    FILE*f=fopen("primes","w");
    
    int primeCount=1;
    long primeVal=1;
    primes[0]=2;
    fprintf(f,"long primes[1000000]={2");
    for (int i=1;i<1000000;i++) {
        if (primes[i]!=0) {
            primeCount++;
            primeVal=primes[i];
            fprintf(f,",%ld",primes[i]);
        } else {
            break;
        }
    }
    label:
    while (primeCount<1000000) {
        //find the next prime.
        char isPrime=1;
        for (int i=0;i<primeCount;i++) {
            //first try all current primes.
            if (primeVal%primes[i]==0) {
                isPrime=0;
                break;
            }
        }
        if (isPrime) {
            primes[primeCount++]=primeVal;
            printf("Generated a new prime: %ld\n",primeVal);
            fprintf(f,",%ld",primeVal);
        }
        primeVal++;
    }

    fprintf(f,",};");
    fclose(f);

    return 0;
}