//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 1000

typedef struct TimeCapsule {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeCapsule;

TimeCapsule* createTimeCapsule(int year, int month, int day, int hour, int minute, int second) {
    TimeCapsule* capsule = malloc(sizeof(TimeCapsule));
    capsule->year = year;
    capsule->month = month;
    capsule->day = day;
    capsule->hour = hour;
    capsule->minute = minute;
    capsule->second = second;
    return capsule;
}

int main() {
    TimeCapsule* capsule = createTimeCapsule(2023, 11, 12, 12, 0, 0);
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);

    int year = tm->tm_year + 1900;
    int month = tm->tm_mon + 1;
    int day = tm->tm_mday;
    int hour = tm->tm_hour;
    int minute = tm->tm_min;
    int second = tm->tm_sec;

    printf("Current Time:");
    printf("\nYear: %d", year);
    printf("\nMonth: %d", month);
    printf("\nDay: %d", day);
    printf("\nHour: %d", hour);
    printf("\nMinute: %d", minute);
    printf("\nSecond: %d", second);

    printf("\nTime Capsule Contents:");
    printf("\nYear: %d", capsule->year);
    printf("\nMonth: %d", capsule->month);
    printf("\nDay: %d", capsule->day);
    printf("\nHour: %d", capsule->hour);
    printf("\nMinute: %d", capsule->minute);
    printf("\nSecond: %d", capsule->second);

    return 0;
}