#include <stdio.h>
#include "utils.h"

/*
    You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
    How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

    https://projecteuler.net/problem=19
*/

enum Month {JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER};

int DaysInMonth(enum Month month,int year) {
    switch (month) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:{
            return 31;
        }break;
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:{
            return 30;
        }break;
        case FEBRUARY:{
            return ((year%100==0)&&(year%400!=0))?28:(year%4==0)?29:28;
        }break;
    }
}

int main(int argc,char**argv) {
    int day=1;
    enum Month month=1;
    int year=1900;
    enum Weekday{
        SUNDAY,
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
    } weekday=MONDAY;

    int sundayCount=0;

    while((day!=31)||(month!=12)||(year!=2000)) {
        printf("Date: %d/%d/%d\n",month,day,year);
        if (year>=1901) {
            //Start counting Sundays.
            if (weekday==SUNDAY&&day==1) {
                sundayCount++;
            }
        }
        //Increment the day.
        if (day+1<=DaysInMonth(month,year)) {
            day++;
        } else 
        if (month+1<=12){
            //It's a new month.
            month++;
            day=1;
        } else {
            //It's a new year!
            year++;
            day=1;
            month=1;
            //printf("The year is now %d...\n",year);
        }
        weekday=((weekday+1)<=SATURDAY)?weekday+1:SUNDAY;
    }

    printf("\n\n%d Sundays were on the 1st of the month.",sundayCount);
    return 0;
}