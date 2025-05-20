//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMEMACHINE_SIZE 100

typedef struct TimeMachine {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeMachine;

TimeMachine* createTimeMachine() {
    TimeMachine* tm = (TimeMachine*)malloc(sizeof(TimeMachine));
    tm->year = 2023;
    tm->month = 12;
    tm->day = 25;
    tm->hour = 12;
    tm->minute = 0;
    tm->second = 0;
    return tm;
}

void printTime(TimeMachine* tm) {
    printf("%d-%d-%d %d:%d:%d", tm->year, tm->month, tm->day, tm->hour, tm->minute, tm->second);
}

void travelToTime(TimeMachine* tm, int year, int month, int day, int hour, int minute, int second) {
    tm->year = year;
    tm->month = month;
    tm->day = day;
    tm->hour = hour;
    tm->minute = minute;
    tm->second = second;
}

int main() {
    TimeMachine* tm = createTimeMachine();
    printTime(tm);

    travelToTime(tm, 2022, 1, 1, 13, 0, 0);

    printTime(tm);

    free(tm);
    return 0;
}