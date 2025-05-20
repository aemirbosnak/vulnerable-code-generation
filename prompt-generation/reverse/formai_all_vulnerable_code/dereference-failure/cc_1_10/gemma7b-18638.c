//Gemma-7B DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    int year, month, day, hour, minute, second;

    // Get the current time
    t = time(NULL);
    struct tm *tm = localtime(&t);

    // Extract the year, month, day, hour, minute, and second
    year = tm->tm_year + 1900;
    month = tm->tm_mon + 1;
    day = tm->tm_mday;
    hour = tm->tm_hour;
    minute = tm->tm_min;
    second = tm->tm_sec;

    // Display the current time
    printf("The current time is: %d-%d-%d %d:%d:%d:%d", year, month, day, hour, minute, second);

    // Simulate time travel
    printf("\nSimulating time travel...");

    // Get the target time
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the hour: ");
    scanf("%d", &hour);
    printf("Enter the minute: ");
    scanf("%d", &minute);
    printf("Enter the second: ");
    scanf("%d", &second);

    // Calculate the time difference
    t = mktime(&tm);
    tm = localtime(&t);
    int seconds_elapsed = tm->tm_sec - second;
    int minutes_elapsed = tm->tm_min - minute;
    int hours_elapsed = tm->tm_hour - hour;
    int days_elapsed = tm->tm_mday - day;
    int months_elapsed = tm->tm_mon - month;
    int years_elapsed = tm->tm_year - year;

    // Display the time elapsed
    printf("The time elapsed is: %d years, %d months, %d days, %d hours, %d minutes, %d seconds", years_elapsed, months_elapsed, days_elapsed, hours_elapsed, minutes_elapsed, seconds_elapsed);

    return 0;
}