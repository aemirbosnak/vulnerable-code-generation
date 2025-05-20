//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date* create_date(int day, int month, int year) {
    Date* date = malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

void destroy_date(Date* date) {
    free(date);
}

int is_valid_date(Date* date) {
    if (date->day < 1 || date->day > 31) {
        return 0;
    }
    if (date->month < 1 || date->month > 12) {
        return 0;
    }
    if (date->year < 1900 || date->year > 2999) {
        return 0;
    }
    return 1;
}

int compare_dates(Date* date1, Date* date2) {
    if (date1->year != date2->year) {
        return date1->year - date2->year;
    }
    if (date1->month != date2->month) {
        return date1->month - date2->month;
    }
    return date1->day - date2->day;
}

int days_between_dates(Date* date1, Date* date2) {
    int days = 0;
    int i;
    int j;
    for (i = date1->year; i < date2->year; i++) {
        for (j = 1; j <= 12; j++) {
            days += 31;
            if (j == 2) {
                if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
                    days++;
                }
            }
        }
    }
    for (i = 1; i < date2->month; i++) {
        days += 31;
        if (i == 2) {
            if ((date2->year % 4 == 0 && date2->year % 100 != 0) || date2->year % 400 == 0) {
                days++;
            }
        }
    }
    days += date2->day - date1->day;
    return days;
}

int main() {
    Date* date1 = create_date(1, 1, 2000);
    Date* date2 = create_date(31, 12, 2022);
    int days = days_between_dates(date1, date2);
    printf("The number of days between %d-%d-%d and %d-%d-%d is %d\n", date1->day, date1->month, date1->year, date2->day, date2->month, date2->year, days);
    destroy_date(date1);
    destroy_date(date2);
    return 0;
}