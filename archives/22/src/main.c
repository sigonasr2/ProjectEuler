#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include <string.h>

/*
    Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

    For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

    What is the total of all the name scores in the file?

    https://projecteuler.net/problem=22
*/

int nameScore(int pos,char*str) {
    int myScore=0;
    int marker=0;
    while (str[marker]!='\0') {
        myScore+=str[marker]-'A'+1;
        marker++;
    }
    return myScore*pos;
}

int main(int argc,char**argv) {
    FILE*file = fopen("p022_names.txt","r");
    int pointer=0;
    int nameCount=0;
    while (!feof(file)) {
        if (fgetc(file)=='"') {
            while (fgetc(file)!='"') {
            }
            nameCount++;
        }
    }
    fseek(file,0,0);
    char*names[nameCount];
    int currentCount=0; 
    while (!feof(file)) {
        if (fgetc(file)=='"') {
            //Start reading the name.
            char*newName=malloc(1);
            char c=' ';
            int length=1;
            while ((c=fgetc(file))!='"') {
                newName=realloc(newName,++length);
                newName[length-2]=c;
                newName[length-1]='\0';
            }
            if (currentCount<2) {
                if (currentCount==1) {
                    if (strcmp(names[0],newName)<0) {
                        names[1]=newName;
                    } else {
                        names[1]=names[0];
                        names[0]=newName;
                    }
                } else {
                    names[0]=newName;
                }
            } else {
                int low=0;
                int high=currentCount;
                int pos=0;
                int mid=low+(high-low)/2;
                while (low<=high) {
                    mid=low+(high-low)/2;
                    if (mid>=currentCount) {
                        break;
                    }
                    int diff=strcmp(names[mid],newName);
                    if (diff<0) {
                        low=mid+1;
                        //printf("%s is after %s... New low:%d\n",newName,names[mid],low);
                    } else {
                        high=mid-1;
                        //printf("%s is before %s... New high:%d\n",newName,names[mid],high);
                    }
                }
                pos=low+(high-low)/2;
                //printf("Position of %s is %d Count:%d.\n",newName,pos,currentCount);
                if (pos==currentCount) {
                    names[currentCount]=newName;
                } else {
                    for (int j=currentCount;j>=pos;j--) {
                        names[j]=names[j-1];
                    }
                    names[pos]=newName;
                }
            }
            currentCount++;
        }
    }
    long nameScores=0;
    for (int i=0;i<nameCount;i++) {
        //Assign scores.
        nameScores+=nameScore(i+1,names[i]);
        printf("%d - %s: %d\n",i+1,names[i],nameScore(i+1,names[i]));
    }
    printf("\nThe total score of all names is: %ld",nameScores);
    return 0;
}