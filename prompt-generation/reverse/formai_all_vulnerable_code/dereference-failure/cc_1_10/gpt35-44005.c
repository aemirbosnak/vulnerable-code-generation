//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t curr_time;
    struct tm *time_info;
    int year, month, day, hour, minute, second;

    // Get current time
    time(&curr_time);

    // Convert to local time
    time_info = localtime(&curr_time);

    // Save current year
    year = time_info->tm_year + 1900;

    // Ask user for a year
    printf("Enter a year to time travel to: ");
    scanf("%d", &year);

    // Save current month, day, hour, minute, and second
    month = time_info->tm_mon;
    day = time_info->tm_mday;
    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;

    // Set new year in time_info
    time_info->tm_year = year - 1900;

    // Check if new year is valid
    if (mktime(time_info) == -1) {
        printf("Invalid year\n");
        return 1;
    }

    // Adjust month if necessary
    if (month == 1 && day == 29 && !is_leap(year)) {
        day = 28;
    }

    // Update time_info
    time_info->tm_mon = month;
    time_info->tm_mday = day;
    time_info->tm_hour = hour;
    time_info->tm_min = minute;
    time_info->tm_sec = second;

    // Print new time
    printf("The time machine is now set to: %s", asctime(time_info));
    
    return 0;
}

// Check if year is a leap year
int is_leap(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}