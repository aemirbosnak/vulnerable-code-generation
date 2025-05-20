//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <locale.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_NAME_LENGTH 20
#define MAX_MONTH_NAME 12

enum {
    INVALID_DATE = -1,
    VALID_DATE = 0
};

struct tm get_current_time() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    return *timeinfo;
}

int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0) {
        return true;
    }
    return false;
}

int get_month_days(int month, int year) {
    switch(month) {
        case 2:
            if (is_leap_year(year)) {
                return 29;
            }
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int get_weekday(struct tm date) {
    return date.tm_wday;
}

char* get_month_name(int month) {
    static char month_names[MAX_MONTH_NAME][MAX_MONTH_NAME_LENGTH] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if (month >= 0 && month < MAX_MONTH_NAME) {
        return month_names[month];
    }
    return "Invalid month";
}

char* get_date_string(struct tm date) {
    char* date_string = malloc(MAX_DATE_LENGTH * sizeof(char));
    strftime(date_string, MAX_DATE_LENGTH, "%A, %B %d, %Y", &date);
    return date_string;
}

int main() {
    setlocale(LC_TIME, "");
    struct tm date = get_current_time();
    char* date_string = get_date_string(date);
    int weekday = get_weekday(date);
    printf("Today is %s, %s %d, %d.\n", get_month_name(date.tm_mon), date_string, weekday, date.tm_mday);
    return 0;
}