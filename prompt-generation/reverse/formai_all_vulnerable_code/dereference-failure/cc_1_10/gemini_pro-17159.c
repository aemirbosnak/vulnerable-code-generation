//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

Time* time_travel(Time* t, int years, int months, int days, int hours, int minutes, int seconds) {
    t->year += years;
    t->month += months;
    t->day += days;
    t->hour += hours;
    t->minute += minutes;
    t->second += seconds;

    // Handle overflow
    if (t->second >= 60) {
        t->second -= 60;
        t->minute++;
    }
    if (t->minute >= 60) {
        t->minute -= 60;
        t->hour++;
    }
    if (t->hour >= 24) {
        t->hour -= 24;
        t->day++;
    }
    if (t->day > 31) {
        t->day -= 31;
        t->month++;
    }
    if (t->month > 12) {
        t->month -= 12;
        t->year++;
    }

    return t;
}

int main() {
    // Initialize the current time
    Time* now = malloc(sizeof(Time));
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    now->year = tm->tm_year + 1900;
    now->month = tm->tm_mon + 1;
    now->day = tm->tm_mday;
    now->hour = tm->tm_hour;
    now->minute = tm->tm_min;
    now->second = tm->tm_sec;

    // Get the user input
    int years, months, days, hours, minutes, seconds;
    printf("How many years do you want to travel?\n");
    scanf("%d", &years);
    printf("How many months do you want to travel?\n");
    scanf("%d", &months);
    printf("How many days do you want to travel?\n");
    scanf("%d", &days);
    printf("How many hours do you want to travel?\n");
    scanf("%d", &hours);
    printf("How many minutes do you want to travel?\n");
    scanf("%d", &minutes);
    printf("How many seconds do you want to travel?\n");
    scanf("%d", &seconds);

    // Perform the time travel
    Time* future = time_travel(now, years, months, days, hours, minutes, seconds);

    // Print the future time
    printf("The future time is %d-%d-%d %d:%d:%d\n", future->year, future->month, future->day, future->hour, future->minute, future->second);

    return 0;
}