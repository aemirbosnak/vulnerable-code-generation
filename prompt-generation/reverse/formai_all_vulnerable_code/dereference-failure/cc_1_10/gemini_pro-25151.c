//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    Date date;
    int hours;
    int minutes;
    int seconds;
} Time;

Time time_travel(Time t, int years, int months, int days, int hours, int minutes, int seconds) {
    t.date.year += years;
    t.date.month += months;
    t.date.day += days;
    t.hours += hours;
    t.minutes += minutes;
    t.seconds += seconds;

    // Normalize the time
    if (t.seconds >= 60) {
        t.seconds -= 60;
        t.minutes++;
    }
    if (t.minutes >= 60) {
        t.minutes -= 60;
        t.hours++;
    }
    if (t.hours >= 24) {
        t.hours -= 24;
        t.date.day++;
    }
    if (t.date.day > days_in_month(t.date.month, t.date.year)) {
        t.date.day -= days_in_month(t.date.month, t.date.year);
        t.date.month++;
    }
    if (t.date.month > 12) {
        t.date.month -= 12;
        t.date.year++;
    }

    return t;
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            return year % 4 == 0 ? 29 : 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return -1;
    }
}

int main() {
    // Get the current time
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);

    // Create a Time struct
    Time t = {
        .date = {
            .year = tm->tm_year + 1900,
            .month = tm->tm_mon + 1,
            .day = tm->tm_mday,
        },
        .hours = tm->tm_hour,
        .minutes = tm->tm_min,
        .seconds = tm->tm_sec,
    };

    // Travel forward in time
    t = time_travel(t, 1, 0, 0, 0, 0, 0);

    // Print the new time
    printf("The new time is: %d-%d-%d %d:%d:%d\n", t.date.year, t.date.month, t.date.day, t.hours, t.minutes, t.seconds);

    return 0;
}