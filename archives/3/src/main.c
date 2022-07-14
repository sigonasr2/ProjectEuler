#include <stdio.h>

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

https://projecteuler.net/problem=3
*/
int main(int argc,char**argv) {

    long primes[10000];
    int primeCount=1;
    long primeVal=3;
    long highestPrime=1;
    primes[0]=2;
    long startingNumb=600851475143;
    label:
    while (startingNumb>1) {
        //find the next prime.
        char isPrime=1;
        for (int i=0;i<primeCount;i++) {
            //first try all current primes.
            if (startingNumb%primes[i]==0) {
                //It's divisible!
                startingNumb/=primes[i];
                printf(" Factor: %ld\n",primes[i]);
                if (highestPrime<primes[i]) {
                    highestPrime=primes[i];
                }
                goto label;
            }
            if (primeVal%primes[i]==0) {
                isPrime=0;
            }
        }
        if (isPrime) {
            primes[primeCount++]=primeVal;
            //printf("Generated a new prime: %ld\n",primeVal);
            if (startingNumb%primeVal==0) {
                //It's divisible!
                startingNumb/=primeVal;
                printf(" Factor: %ld\n",primeVal);
                if (highestPrime<primeVal) {
                    highestPrime=primeVal;
                }
            }
        }
        primeVal++;
    }

    printf("Highest prime is %ld",highestPrime);

    return 0;
}