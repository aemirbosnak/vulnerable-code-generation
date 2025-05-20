//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIMEMACHINE_SIZE 10

typedef struct TimeMachine {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    time_t timestamp;
} TimeMachine;

TimeMachine* createTimeMachine() {
    TimeMachine* tm = (TimeMachine*)malloc(sizeof(TimeMachine));
    tm->year = 2023;
    tm->month = 12;
    tm->day = 25;
    tm->hour = 12;
    tm->minute = 0;
    tm->second = 0;
    tm->timestamp = time(NULL);
    return tm;
}

void travelToTime(TimeMachine* tm, int year, int month, int day, int hour, int minute, int second) {
    tm->year = year;
    tm->month = month;
    tm->day = day;
    tm->hour = hour;
    tm->minute = minute;
    tm->second = second;
    tm->timestamp = time(NULL);
}

void printTime(TimeMachine* tm) {
    printf("%d-%d-%d %d:%d:%d %d", tm->year, tm->month, tm->day, tm->hour, tm->minute, tm->second);
    printf("\n");
}

int main() {
    TimeMachine* tm = createTimeMachine();
    travelToTime(tm, 1999, 1, 1, 10, 0, 0);
    printTime(tm);
    travelToTime(tm, 2023, 12, 25, 12, 0, 0);
    printTime(tm);
    return 0;
}