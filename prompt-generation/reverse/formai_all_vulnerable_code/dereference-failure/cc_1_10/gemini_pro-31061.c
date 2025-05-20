//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LEN 20

struct date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int days_in_month(int month, int year) {
    if (month == 2) {
        return is_leap_year(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    char date_str[MAX_DATE_LEN];
    struct date date;

    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", date_str);

    // Split the date string into day, month, and year
    char *day_str = strtok(date_str, "/");
    char *month_str = strtok(NULL, "/");
    char *year_str = strtok(NULL, "/");

    // Convert the strings to integers
    date.day = atoi(day_str);
    date.month = atoi(month_str);
    date.year = atoi(year_str);

    // Check if the date is valid
    if (date.day < 1 || date.day > days_in_month(date.month, date.year)) {
        printf("Invalid day: %d\n", date.day);
        return -1;
    }
    if (date.month < 1 || date.month > 12) {
        printf("Invalid month: %d\n", date.month);
        return -1;
    }
    if (date.year < 1) {
        printf("Invalid year: %d\n", date.year);
        return -1;
    }

    // Print the date in the format yyyy-mm-dd
    printf("Date in yyyy-mm-dd format: %d-%d-%d\n", date.year, date.month, date.day);

    return 0;
}