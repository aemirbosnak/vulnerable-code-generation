//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time machine structure
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeMachine;

// Create a new time machine
TimeMachine* create_time_machine() {
    TimeMachine* tm = malloc(sizeof(TimeMachine));
    tm->year = 2023;
    tm->month = 1;
    tm->day = 1;
    tm->hour = 0;
    tm->minute = 0;
    tm->second = 0;
    return tm;
}

// Destroy the time machine
void destroy_time_machine(TimeMachine* tm) {
    free(tm);
}

// Set the time machine's date and time
void set_time_machine_date_and_time(TimeMachine* tm, int year, int month, int day, int hour, int minute, int second) {
    tm->year = year;
    tm->month = month;
    tm->day = day;
    tm->hour = hour;
    tm->minute = minute;
    tm->second = second;
}

// Get the time machine's date and time
void get_time_machine_date_and_time(TimeMachine* tm, int* year, int* month, int* day, int* hour, int* minute, int* second) {
    *year = tm->year;
    *month = tm->month;
    *day = tm->day;
    *hour = tm->hour;
    *minute = tm->minute;
    *second = tm->second;
}

// Travel to the future
void travel_to_future(TimeMachine* tm, int years, int months, int days, int hours, int minutes, int seconds) {
    tm->year += years;
    tm->month += months;
    tm->day += days;
    tm->hour += hours;
    tm->minute += minutes;
    tm->second += seconds;
}

// Travel to the past
void travel_to_past(TimeMachine* tm, int years, int months, int days, int hours, int minutes, int seconds) {
    tm->year -= years;
    tm->month -= months;
    tm->day -= days;
    tm->hour -= hours;
    tm->minute -= minutes;
    tm->second -= seconds;
}

// Print the time machine's date and time
void print_time_machine_date_and_time(TimeMachine* tm) {
    printf("The time machine is currently set to: %d-%d-%d %d:%d:%d\n", tm->year, tm->month, tm->day, tm->hour, tm->minute, tm->second);
}

int main() {
    // Create a new time machine
    TimeMachine* tm = create_time_machine();

    // Print the time machine's date and time
    print_time_machine_date_and_time(tm);

    // Travel to the future
    travel_to_future(tm, 10, 0, 0, 0, 0, 0);

    // Print the time machine's date and time
    print_time_machine_date_and_time(tm);

    // Travel to the past
    travel_to_past(tm, 10, 0, 0, 0, 0, 0);

    // Print the time machine's date and time
    print_time_machine_date_and_time(tm);

    // Destroy the time machine
    destroy_time_machine(tm);

    return 0;
}