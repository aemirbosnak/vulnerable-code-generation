//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    char* c_time_string;

    // Get current time
    current_time = time(NULL);

    // Convert to local time
    c_time_string = ctime(&current_time);

    printf("Current time is: %s", c_time_string);

    // Convert to struct tm
    struct tm* time_info;
    time_info = localtime(&current_time);

    // Print date and time
    printf("Current date and time is: %d-%d-%d %d:%d:%d",
           time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
           time_info->tm_hour, time_info->tm_min, time_info->tm_sec);

    // Convert back to time_t
    int year = 2022;
    int month = 12;
    int day = 31;
    int hour = 23;
    int min = 59;
    int sec = 59;

    struct tm new_time_info = {0};
    new_time_info.tm_sec = sec;
    new_time_info.tm_min = min;
    new_time_info.tm_hour = hour;
    new_time_info.tm_mday = day;
    new_time_info.tm_mon = month - 1;
    new_time_info.tm_year = year - 1900;

    time_t new_time = mktime(&new_time_info);

    // Convert to string
    char new_time_string[32];
    strftime(new_time_string, sizeof(new_time_string), "%Y-%m-%d %H:%M:%S", localtime(&new_time));

    printf("New time is: %s", new_time_string);

    return 0;
}