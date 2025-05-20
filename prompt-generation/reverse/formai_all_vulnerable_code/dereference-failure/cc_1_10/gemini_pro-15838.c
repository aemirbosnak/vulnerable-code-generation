//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DAYS_IN_YEAR 365
#define DAYS_IN_WEEK 7

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* newDate(int year, int month, int day) {
    Date* date = malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

void freeDate(Date* date) {
    free(date);
}

int daysBetweenDates(Date* date1, Date* date2) {
    int days_between_years = (date2->year - date1->year) * DAYS_IN_YEAR;
    int days_between_months = (date2->month - date1->month) * 30;
    int days_between_days = date2->day - date1->day;
    return days_between_years + days_between_months + days_between_days;
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    Date* date1 = newDate(2020, 1, 1);
    Date* date2 = newDate(2021, 12, 31);

    printf("Number of days between %d-%d-%d and %d-%d-%d: %d\n",
        date1->year, date1->month, date1->day,
        date2->year, date2->month, date2->day,
        daysBetweenDates(date1, date2));

    freeDate(date1);
    freeDate(date2);

    return 0;
}