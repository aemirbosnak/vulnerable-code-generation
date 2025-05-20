//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel machine
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
    tm->year = 1985;
    tm->month = 10;
    tm->day = 21;
    tm->hour = 10;
    tm->minute = 0;
    tm->second = 0;
    return tm;
}

// Destroy the time machine
void destroy_time_machine(TimeMachine* tm) {
    free(tm);
}

// Set the time machine's date
void set_time_machine_date(TimeMachine* tm, int year, int month, int day) {
    tm->year = year;
    tm->month = month;
    tm->day = day;
}

// Set the time machine's time
void set_time_machine_time(TimeMachine* tm, int hour, int minute, int second) {
    tm->hour = hour;
    tm->minute = minute;
    tm->second = second;
}

// Travel to the future
void travel_to_future(TimeMachine* tm, int years) {
    tm->year += years;
}

// Travel to the past
void travel_to_past(TimeMachine* tm, int years) {
    tm->year -= years;
}

// Print the current time
void print_current_time(TimeMachine* tm) {
    printf("The current time is: %d-%d-%d %d:%d:%d\n", tm->year, tm->month, tm->day, tm->hour, tm->minute, tm->second);
}

int main() {
    // Create a new time machine
    TimeMachine* tm = create_time_machine();

    // Print the current time
    print_current_time(tm);

    // Travel to the future
    travel_to_future(tm, 10);

    // Print the current time
    print_current_time(tm);

    // Travel to the past
    travel_to_past(tm, 5);

    // Print the current time
    print_current_time(tm);

    // Destroy the time machine
    destroy_time_machine(tm);

    return 0;
}