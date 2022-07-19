#include <stdio.h>
#include "utils.h"
#include <stdlib.h>

/*
    Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

    For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

    What is the total of all the name scores in the file?

    https://projecteuler.net/problem=22
*/

int main(int argc,char**argv) {
    FILE*file = fopen("p022_names.txt","r");
    printf("%s\n",add(BigNumber(38195431534281091050778),BigNumber(381918429378)).str);
    /*int pointer=0;
    int nameCount=0;
    char**names = malloc(sizeof(char*));
    while (!feof(file)) {
        if (fgetc(file)=='"') {
            //Start reading the name.
            char*newName=malloc(1);
            char c=' ';
            int length=0;
            while ((c=fgetc(file))!='"') {
                newName=realloc(newName,++length);
                newName[length-2]=c;
                newName[length-1]='\0';
            }
            nameCount++;
            names=realloc(names,sizeof(char*)*nameCount);
            names[nameCount-1]=newName;
        }
    }
    for (int i=0;i<nameCount;i++) {
        printf("%s\n",names[i]);
    }*/
    return 0;
}