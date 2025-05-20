//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the futuristic date format
typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} futuristic_date;

// Convert a futuristic date to a time_t value
time_t futuristic_date_to_time_t(futuristic_date date) {
    struct tm tm;
    tm.tm_year = date.year - 1900;
    tm.tm_mon = date.month - 1;
    tm.tm_mday = date.day;
    tm.tm_hour = date.hour;
    tm.tm_min = date.minute;
    tm.tm_sec = date.second;
    tm.tm_isdst = -1;  // Don't know if daylight savings time is in effect
    return mktime(&tm);
}

// Convert a time_t value to a futuristic date
futuristic_date time_t_to_futuristic_date(time_t time) {
    struct tm *tm = localtime(&time);
    futuristic_date date;
    date.year = tm->tm_year + 1900;
    date.month = tm->tm_mon + 1;
    date.day = tm->tm_mday;
    date.hour = tm->tm_hour;
    date.minute = tm->tm_min;
    date.second = tm->tm_sec;
    return date;
}

// Print a futuristic date
void print_futuristic_date(futuristic_date date) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", date.year, date.month, date.day, date.hour, date.minute, date.second);
}

// Get the current futuristic date
futuristic_date get_current_futuristic_date() {
    time_t now = time(NULL);
    return time_t_to_futuristic_date(now);
}

// Main function
int main() {
    // Get the current futuristic date
    futuristic_date date = get_current_futuristic_date();

    // Print the current futuristic date
    printf("Current date:\n");
    print_futuristic_date(date);

    return 0;
}