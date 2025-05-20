//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

int main(void) {
    time_t current_time;
    struct tm *time_info;
    char date_string[MAX_LENGTH];
    char day_string[MAX_LENGTH];
    char month_string[MAX_LENGTH];
    char year_string[MAX_LENGTH];
    char hour_string[MAX_LENGTH];
    char minute_string[MAX_LENGTH];
    char second_string[MAX_LENGTH];
    char timezone_string[MAX_LENGTH];
    int day, month, year, hour, minute, second;
    int timezone_hours, timezone_minutes;

    // Get current time
    time(&current_time);

    // Convert time to struct tm
    time_info = localtime(&current_time);

    // Get date components
    day = time_info->tm_mday;
    month = time_info->tm_mon + 1;
    year = time_info->tm_year + 1900;

    // Get time components
    hour = time_info->tm_hour;
    minute = time_info->tm_min;
    second = time_info->tm_sec;

    // Get timezone components
    timezone_hours = time_info->tm_gmtoff / 3600;
    timezone_minutes = (time_info->tm_gmtoff % 3600) / 60;

    // Convert date components to strings
    strftime(date_string, MAX_LENGTH, "%A, %B %d, %Y", time_info);

    // Convert time components to strings
    strftime(hour_string, MAX_LENGTH, "%I:%M %p", time_info);

    // Convert timezone components to strings
    strftime(timezone_string, MAX_LENGTH, "%Z", time_info);

    // Convert day of week to string
    strftime(day_string, MAX_LENGTH, "%A", time_info);

    // Convert month to string
    strftime(month_string, MAX_LENGTH, "%B", time_info);

    // Convert year to string
    strftime(year_string, MAX_LENGTH, "%Y", time_info);

    // Convert hour to string
    strftime(hour_string, MAX_LENGTH, "%I", time_info);

    // Convert minute to string
    strftime(minute_string, MAX_LENGTH, "%M", time_info);

    // Convert second to string
    strftime(second_string, MAX_LENGTH, "%S", time_info);

    // Print date and time
    printf("Today is %s, %s %d, %s.\n", day_string, month_string, day, year_string);
    printf("The time is %s %s %s.\n", hour_string, minute_string, second_string);
    printf("The timezone is %s.\n", timezone_string);

    return 0;
}