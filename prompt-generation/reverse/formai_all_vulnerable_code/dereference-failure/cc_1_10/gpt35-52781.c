//FormAI DATASET v1.0 Category: Date and time ; Style: statistical
#include <stdio.h>
#include <time.h>

int main()
{
    struct tm *local_time;
    time_t current_time;

    char time_string[50];

    // Get current time
    current_time = time(NULL);

    // Convert to local time
    local_time = localtime(&current_time);

    // Get the year, month, and day
    int year = local_time->tm_year + 1900;
    int month = local_time->tm_mon + 1;
    int day = local_time->tm_mday;

    // Print the today's date
    printf("Today's date is: %d-%02d-%02d\n", year, month, day);

    // Get the current time
    strftime(time_string, sizeof(time_string), "%H:%M:%S", local_time);

    // Print the current time
    printf("The current time is: %s\n", time_string);

    // Create a random date
    struct tm random_time = {0};
    random_time.tm_year = 120;
    random_time.tm_mon = 6;
    random_time.tm_mday = 15;

    // Convert to time_t
    time_t random_seconds = mktime(&random_time);

    // Convert to local time
    local_time = localtime(&random_seconds);

    // Get the year, month, and day
    year = local_time->tm_year + 1900;
    month = local_time->tm_mon + 1;
    day = local_time->tm_mday;

    // Print the random date
    printf("A random date is: %d-%02d-%02d\n", year, month, day);

    // Create a random time
    random_time.tm_hour = 13;
    random_time.tm_min = 59;

    // Convert to time_t
    random_seconds = mktime(&random_time);

    // Convert to local time
    local_time = localtime(&random_seconds);

    // Get the current time
    strftime(time_string, sizeof(time_string), "%H:%M:%S", local_time);

    // Print the random time
    printf("A random time is: %s\n", time_string);

    return 0;
}