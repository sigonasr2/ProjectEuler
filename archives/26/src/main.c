#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/*
    A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1
    Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

    Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

    https://projecteuler.net/problem=26
*/

boolean isPrime(int*primeList,int primeListSize,int numb) {
    for (int i=0;i<primeListSize;i++) {
        if (numb==primeList[i]) {
            return true;
        }
    }
    return false;
}

int*getFactors(int numb) {
    int*factorList=malloc(sizeof(int)*1);
    int factorListSize=2;
    factorList[0]=1;
    factorList[1]=numb;
    int max=numb;
    for (int i=2;i<max;i++) {
        if (numb%i==0) {
            factorList=realloc(factorList,sizeof(int)*++factorListSize);
            factorList[factorListSize-1]=i;
            if (numb/i!=i) {
                factorList=realloc(factorList,sizeof(int)*++factorListSize);
                factorList[factorListSize-1]=numb/i;
                max=numb/i;
            }
        }
    }
    factorList=realloc(factorList,sizeof(int)*++factorListSize);
    factorList[factorListSize-1]=0;
    return factorList;
}

boolean isFactor(int*factorList,int numb) {
    int counter=0;
    while (factorList[counter]!=0) {
        if (numb==factorList[counter]) {
            return true;
        }
        counter++;
    }
    return false;
}

const int TARGET_REPEATS_REQUIRED=100000;

int main(int argc,char**argv) {
    int divider=0;
    int divisor=2;
    int sequence[TARGET_REPEATS_REQUIRED]; //Let's assume for the sake of sanity that 100000 repeating digits is enough. I sure hope so.
    int sequenceLength=0;
    int sequenceRepeat=0;
    int sequenceMarker=-1;
    int longestCycleLength=0;
    int longestCycleDivisor=0;
    int longestSequence[TARGET_REPEATS_REQUIRED/10];
    int*primeList=malloc(sizeof(int)*0);
    int primeListSize=0;

    FILE*f = fopen("archives/primegenerator/primes","r");
    while (fgetc(f)!='{');
    while (true) {
        char c;
        int digit=0;
        while ((c=fgetc(f))!=',') {
            digit*=10;
            digit+=c-'0';
        }   
        if (digit>=1000) {
            break;
        } else {
            primeList=realloc(primeList,sizeof(int)*++primeListSize);
            primeList[primeListSize-1]=digit;
        }
    }

    while (divisor<1000) {
        divider=10; //We always start with 10.
        sequenceLength=0;
        sequenceRepeat=0;
        for (int i=0;i<sequenceLength;i++) {
            sequence[i]=0;
        }
        sequenceMarker=-1;
        while (sequenceLength<TARGET_REPEATS_REQUIRED) {
            int result=divider/divisor;
            //printf("%d/%d = %d\n",divider,divisor,result);
            divider=divider%divisor;
            sequence[sequenceLength++]=result;
            divider*=10;
            if (divider==0) {
                //We're solved.
                break;
            }
        }
        /*printf("%d:",divisor);
        for (int i=0;i<sequenceLength;i++) {
            printf("%d",sequence[i]);
        }
        printf("\n");*/
        //We need to look at all combinations of possible repeating sequences.
        //Starting from iteration loop of length 1, and an offset incrementing by 1, see if anything remains the same.
        //Then do this for iteration loop of length 2, offset incrementing by 1, etc.
        //Find it repeating at least 20 times to assume it repeats infinitely.
        boolean isP = isPrime(primeList,primeListSize,divisor);
        int*factors = getFactors(divisor-1);
        int counter=0;
        /*if (isP) {
            printf("Possible length factors of (%d-1):",divisor);
            while (factors[counter]!=0) {
                printf("%d,",factors[counter]);
                counter++;
            }
            printf("\n");
        }*/
        boolean matched=false;
        if (sequenceLength==TARGET_REPEATS_REQUIRED) {
            for (int checkLength=0;checkLength<TARGET_REPEATS_REQUIRED/10;checkLength++) {
                if (isP&&!isFactor(factors,checkLength+1)) {continue;}
                for (int offset=0;offset<sequenceLength+1-checkLength;offset++) {
                    int sequenceStore[checkLength+1];
                    int requiredCheckAmt=TARGET_REPEATS_REQUIRED/10-2;
                    for (int i=0;i<checkLength+1;i++) {
                        sequenceStore[i]=sequence[i+offset];
                        /*printf("%d:",divisor);
                        for (int i=0;i<checkLength+1;i++) {
                            printf("%d",sequenceStore[i]);
                        }
                        0010030090270812437311935807422266800401203610832497492477432296890672016048144433299899699097291875626880641925777331995987963891675025075225677031093279839518555667
                        0010030090270812437311935807422266800401203610832497492477432296890672016048144433299899699097291875626880641925777331995987963891675025075225677031093279839518555667
                        printf("\n");*/
                    }
                    //Now if this repeating sequence can be found requiredCheckAmt times, we're golden.
                    boolean allMatching=true;
                    int currentOffset=0;
                    int found=0;
                    while (requiredCheckAmt>0&&found<20) {
                        for (int i=0;i<checkLength+1;i++) {
                            //printf("  Compare %d to %d\n",sequence[offset+currentOffset+checkLength+1+i],sequenceStore[i]);
                            if (sequence[offset+currentOffset+checkLength+1+i]!=sequenceStore[i]) {
                                allMatching=false;
                                goto check;
                            }
                        }
                        requiredCheckAmt--;
                        currentOffset+=checkLength+1;
                        found++;
                        //printf("Found a repeat.");
                    }
                    check:
                    if (allMatching) {
                        printf("Longest repeating sequence for %d is of length %d: ",divisor,checkLength+1);
                        for (int i=0;i<checkLength+1;i++) {
                            printf("%d",sequenceStore[i]);
                        }
                        printf("\n");
                        if (longestCycleLength<checkLength+1) {
                            longestCycleLength=checkLength+1;
                            longestCycleDivisor=divisor;
                            for (int i=0;i<longestCycleLength;i++) {
                                longestSequence[i]=sequenceStore[i];
                            }
                        }
                        matched=true;
                        goto next;
                    }
                }
            }
        } else {
            matched=true;
            printf("Longest repeating sequence for %d is of length 0.\n",divisor);
        }
        next:
        free(factors);
        if (!matched) {
            printf("Not enough data to calculate longest repeating sequence for %d!\nQuitting...\n",divisor);
            return 1;
        }
        divisor++;
    }

    printf("\n\nThe largest repeating sequence length is from %d with %d in length.",longestCycleDivisor,longestCycleLength);
    printf("\n\tSequence: ");
    for (int i=0;i<longestCycleLength;i++) {
        printf("%d",longestSequence[i]);
    }
    printf("\n");
    
    return 0;
}