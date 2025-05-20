//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

struct tm get_current_time() {
    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    return *time_info;
}

char* get_day_of_week(int day_of_week) {
    switch(day_of_week) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Invalid day of week";
    }
}

char* get_month_name(int month) {
    switch(month) {
        case 0:
            return "January";
        case 1:
            return "February";
        case 2:
            return "March";
        case 3:
            return "April";
        case 4:
            return "May";
        case 5:
            return "June";
        case 6:
            return "July";
        case 7:
            return "August";
        case 8:
            return "September";
        case 9:
            return "October";
        case 10:
            return "November";
        case 11:
            return "December";
        default:
            return "Invalid month";
    }
}

char* get_formatted_date(struct tm date, char* format) {
    char* result = malloc(MAX_STRING_LENGTH * sizeof(char));
    strftime(result, MAX_STRING_LENGTH, format, &date);
    return result;
}

int main() {
    struct tm current_date = get_current_time();
    char* day_of_week = get_day_of_week(current_date.tm_wday);
    char* month_name = get_month_name(current_date.tm_mon);
    char* formatted_date = get_formatted_date(current_date, "%A, %B %d, %Y");

    printf("Today is %s, %s %d, %s\n", day_of_week, month_name, current_date.tm_mday, formatted_date);

    free(formatted_date);
    return 0;
}