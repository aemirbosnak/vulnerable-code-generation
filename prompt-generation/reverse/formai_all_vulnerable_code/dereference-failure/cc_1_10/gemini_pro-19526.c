//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: configurable
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

Time current_time;
Time target_time;
int time_travel_enabled = 0;

void get_current_time() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    current_time.year = tm->tm_year + 1900;
    current_time.month = tm->tm_mon + 1;
    current_time.day = tm->tm_mday;
    current_time.hour = tm->tm_hour;
    current_time.minute = tm->tm_min;
    current_time.second = tm->tm_sec;
}

void set_target_time(int year, int month, int day, int hour, int minute, int second) {
    target_time.year = year;
    target_time.month = month;
    target_time.day = day;
    target_time.hour = hour;
    target_time.minute = minute;
    target_time.second = second;
}

void print_time(Time time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

void time_travel(int years, int months, int days, int hours, int minutes, int seconds) {
    if (!time_travel_enabled) {
        printf("Time travel is not enabled. Please enable it first.\n");
        return;
    }

    current_time.year += years;
    current_time.month += months;
    current_time.day += days;
    current_time.hour += hours;
    current_time.minute += minutes;
    current_time.second += seconds;

    // Handle wrap-around
    if (current_time.month > 12) {
        current_time.month -= 12;
        current_time.year++;
    } else if (current_time.month < 1) {
        current_time.month += 12;
        current_time.year--;
    }

    if (current_time.day > 31) {
        current_time.day -= 31;
        current_time.month++;
    } else if (current_time.day < 1) {
        current_time.day += 31;
        current_time.month--;
    }

    if (current_time.hour > 23) {
        current_time.hour -= 24;
        current_time.day++;
    } else if (current_time.hour < 0) {
        current_time.hour += 24;
        current_time.day--;
    }

    if (current_time.minute > 59) {
        current_time.minute -= 60;
        current_time.hour++;
    } else if (current_time.minute < 0) {
        current_time.minute += 60;
        current_time.hour--;
    }

    if (current_time.second > 59) {
        current_time.second -= 60;
        current_time.minute++;
    } else if (current_time.second < 0) {
        current_time.second += 60;
        current_time.minute--;
    }

    printf("Time travel successful. The current time is now: ");
    print_time(current_time);
}

int main() {
    // Get the current time
    get_current_time();

    // Print the current time
    printf("Current time: ");
    print_time(current_time);

    // Set the target time
    set_target_time(2023, 1, 1, 0, 0, 0);

    // Enable time travel
    time_travel_enabled = 1;

    // Time travel to the target time
    time_travel(0, 0, 0, 0, 0, 0);

    // Print the current time
    printf("Current time: ");
    print_time(current_time);

    return 0;
}