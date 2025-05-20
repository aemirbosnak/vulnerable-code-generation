//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME_TRAVEL 1000000000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

Time *create_time(int year, int month, int day, int hour, int minute, int second) {
    Time *time = malloc(sizeof(Time));
    time->year = year;
    time->month = month;
    time->day = day;
    time->hour = hour;
    time->minute = minute;
    time->second = second;
    return time;
}

void print_time(Time *time) {
    printf("%d-%02d-%02d %02d:%02d:%02d\n", time->year, time->month, time->day, time->hour, time->minute, time->second);
}

Time *add_seconds(Time *time, int seconds) {
    time->second += seconds;
    while (time->second >= 60) {
        time->second -= 60;
        time->minute++;
    }
    while (time->minute >= 60) {
        time->minute -= 60;
        time->hour++;
    }
    while (time->hour >= 24) {
        time->hour -= 24;
        time->day++;
    }
    while (time->day > 30) {  // assuming each month has 30 days
        time->day -= 30;
        time->month++;
    }
    while (time->month > 12) {
        time->month -= 12;
        time->year++;
    }
    return time;
}

Time *subtract_seconds(Time *time, int seconds) {
    time->second -= seconds;
    while (time->second < 0) {
        time->second += 60;
        time->minute--;
    }
    while (time->minute < 0) {
        time->minute += 60;
        time->hour--;
    }
    while (time->hour < 0) {
        time->hour += 24;
        time->day--;
    }
    while (time->day < 0) {
        time->day += 30;
        time->month--;
    }
    while (time->month < 0) {
        time->month += 12;
        time->year--;
    }
    return time;
}

int main() {
    // Create a random time between 1900 and 2023.
    srand(time(NULL));
    int year = 1900 + rand() % 104;
    int month = 1 + rand() % 12;
    int day = 1 + rand() % 30;
    int hour = 0 + rand() % 24;
    int minute = 0 + rand() % 60;
    int second = 0 + rand() % 60;
    Time *time = create_time(year, month, day, hour, minute, second);

    // Print the original time.
    printf("Original time: ");
    print_time(time);

    // Travel forward in time by a random number of seconds between 0 and 1000000000.
    int seconds = rand() % MAX_TIME_TRAVEL;
    time = add_seconds(time, seconds);

    // Print the time after traveling forward.
    printf("Time after traveling forward: ");
    print_time(time);

    // Travel backward in time by the same number of seconds.
    time = subtract_seconds(time, seconds);

    // Print the time after traveling backward.
    printf("Time after traveling backward: ");
    print_time(time);

    return 0;
}