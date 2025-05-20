//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the time travel simulator
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} TimeCapsule;

// Create a new time capsule
TimeCapsule* newTimeCapsule(int year, int month, int day, int hour, int minute, int second) {
    TimeCapsule* tc = malloc(sizeof(TimeCapsule));
    tc->year = year;
    tc->month = month;
    tc->day = day;
    tc->hour = hour;
    tc->minute = minute;
    tc->second = second;
    return tc;
}

// Print the time capsule
void printTimeCapsule(TimeCapsule* tc) {
    printf("Year: %d\n", tc->year);
    printf("Month: %d\n", tc->month);
    printf("Day: %d\n", tc->day);
    printf("Hour: %d\n", tc->hour);
    printf("Minute: %d\n", tc->minute);
    printf("Second: %d\n", tc->second);
}

// Travel to the future
TimeCapsule* travelToFuture(TimeCapsule* tc, int years, int months, int days, int hours, int minutes, int seconds) {
    tc->year += years;
    tc->month += months;
    tc->day += days;
    tc->hour += hours;
    tc->minute += minutes;
    tc->second += seconds;
    return tc;
}

// Travel to the past
TimeCapsule* travelToPast(TimeCapsule* tc, int years, int months, int days, int hours, int minutes, int seconds) {
    tc->year -= years;
    tc->month -= months;
    tc->day -= days;
    tc->hour -= hours;
    tc->minute -= minutes;
    tc->second -= seconds;
    return tc;
}

// Get the current time
TimeCapsule* getCurrentTime() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    return newTimeCapsule(tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec);
}

// Main function
int main() {
    // Create a new time capsule for the current time
    TimeCapsule* tc = getCurrentTime();

    // Print the current time
    printf("Current time:\n");
    printTimeCapsule(tc);

    // Travel to the future by 1 year, 1 month, 1 day, 1 hour, 1 minute, and 1 second
    tc = travelToFuture(tc, 1, 1, 1, 1, 1, 1);

    // Print the future time
    printf("Future time:\n");
    printTimeCapsule(tc);

    // Travel to the past by 1 year, 1 month, 1 day, 1 hour, 1 minute, and 1 second
    tc = travelToPast(tc, 1, 1, 1, 1, 1, 1);

    // Print the past time
    printf("Past time:\n");
    printTimeCapsule(tc);

    return 0;
}