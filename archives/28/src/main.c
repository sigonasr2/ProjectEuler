#include <stdio.h>
#include "utils.h"

/*
    Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

    21 22 23 24 25
    20  7  8  9 10
    19  6  1  2 11
    18  5  4  3 12
    17 16 15 14 13

    It can be verified that the sum of the numbers on the diagonals is 101.

    What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

    https://projecteuler.net/problem=28
*/

enum dir{RIGHT,DOWN,LEFT,UP};

#define SPIRAL_SIZE 1001

int main(int argc,char**argv) {
    //Move the number repeatedly in a spiral. Anytime the number in both the X and Y coordinates match, you sum.
    int x=0;
    int y=0;
    int number=1;
    long sum=0;
    boolean adjust=false;
    int maxCounter=1;
    int counter=maxCounter;
    enum dir dir=0;
    while (x<=SPIRAL_SIZE/2&&y<=SPIRAL_SIZE/2&&x>=-SPIRAL_SIZE/2&&y>=-SPIRAL_SIZE/2) {
        if (x==y||-x==y||x==-y||-x==-y) {
            sum+=number;
            printf("Added %d at (%d,%d). Sum:%ld\n",number,x,y,sum);
        }
        switch (dir) {
            case RIGHT:{
                x++;
            }break;
            case DOWN:{
                y++;
            }break;
            case LEFT:{
                x--;
            }break;
            case UP:{
                y--;
            }break;
        }
        if (--counter==0) {
            if (!adjust) {
                adjust=true;
            } else {
                adjust=false;
                maxCounter++;
            }
            dir=(dir+1)%4;
            counter=maxCounter;
        }
        number++;
        //printf("(%d,%d)\n",x,y);
    }
    printf("\n\nFinal Sum:%ld",sum);
    return 0;
}