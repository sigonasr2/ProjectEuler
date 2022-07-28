#include <stdio.h>
#include "utils.h"

/*
    In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

        1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

    It is possible to make £2 in the following way:

        1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

    How many different ways can £2 be made using any number of coins?


    https://projecteuler.net/problem=31
*/

enum Currency{
    pence1,
    pence2,
    pence5,
    pence10,
    pence20,
    pence50,
    pound1, //100 pences
    pound2, //200 pences
};

int getValue(enum Currency cur) {
    switch (cur) {
        case pence1:{
            return 1;
        }break;
        case pence2:{
            return 2;
        }break;
        case pence5:{
            return 5;
        }break;
        case pence10:{
            return 10;
        }break;
        case pence20:{
            return 20;
        }break;
        case pence50:{
            return 50;
        }break;
        case pound1:{
            return 100;
        }break;
        case pound2:{
            return 200;
        }break;
    }
}

int total(int*amts) {
    return 
        getValue(pence1)*amts[0]+
        getValue(pence2)*amts[1]+
        getValue(pence5)*amts[2]+
        getValue(pence10)*amts[3]+
        getValue(pence20)*amts[4]+
        getValue(pence50)*amts[5]+
        getValue(pound1)*amts[6]+
        getValue(pound2)*amts[7];
}

void carryover(int*amts,int placeVal) {
    amts[placeVal]++;
    if (placeVal<7&&amts[placeVal]>200/getValue(placeVal)) {
        carryover(amts,placeVal+1);
        amts[placeVal]=0;
    }
}

int main(int argc,char**argv) {
    int currencyAmts[8] = {};
    int combinationCount=0;
    int maxCurrencyVal=200;
    int currentMarker=0;

    while (currencyAmts[6]!=2) {
        if (total(currencyAmts)==200) {
            printf("Coin amts: ");
            for (int i=0;i<8;i++) {
                printf("%d ",currencyAmts[i]);
            }
            printf("\n");
            combinationCount++;
        }
        carryover(currencyAmts,0);
    }
    printf("\n\nCombination count: %d",(combinationCount+2));
    
    return 0;
}