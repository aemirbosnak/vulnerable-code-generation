//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Time Machine struct
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeMachine;

// Time Travel function
void timeTravel(TimeMachine *tm, int years, int months, int days, int hours, int minutes, int seconds) {
    tm->year += years;
    tm->month += months;
    tm->day += days;
    tm->hour += hours;
    tm->minute += minutes;
    tm->second += seconds;

    // Normalize time
    if (tm->second >= 60) {
        tm->second -= 60;
        tm->minute++;
    }
    if (tm->minute >= 60) {
        tm->minute -= 60;
        tm->hour++;
    }
    if (tm->hour >= 24) {
        tm->hour -= 24;
        tm->day++;
    }
    if (tm->day >= 31) {
        tm->day -= 31;
        tm->month++;
    }
    if (tm->month >= 12) {
        tm->month -= 12;
        tm->year++;
    }
}

// Main function
int main() {
    // Create a Time Machine object
    TimeMachine tm;

    // Initialize the Time Machine to the current time
    time_t t = time(NULL);
    struct tm *lt = localtime(&t);
    tm.year = lt->tm_year + 1900;
    tm.month = lt->tm_mon + 1;
    tm.day = lt->tm_mday;
    tm.hour = lt->tm_hour;
    tm.minute = lt->tm_min;
    tm.second = lt->tm_sec;

    // Prompt the user for the time to travel to
    int years, months, days, hours, minutes, seconds;
    printf("Enter the time to travel to (years, months, days, hours, minutes, seconds): ");
    scanf("%d %d %d %d %d %d", &years, &months, &days, &hours, &minutes, &seconds);

    // Time travel
    timeTravel(&tm, years, months, days, hours, minutes, seconds);

    // Print the new time
    printf("New time: %d-%02d-%02d %02d:%02d:%02d\n", tm.year, tm.month, tm.day, tm.hour, tm.minute, tm.second);

    return 0;
}