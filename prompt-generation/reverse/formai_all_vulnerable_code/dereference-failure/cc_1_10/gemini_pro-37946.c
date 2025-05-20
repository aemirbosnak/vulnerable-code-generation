//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* createDate(int year, int month, int day) {
    Date* date = malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

void printDate(Date* date) {
    printf("%d-%d-%d\n", date->year, date->month, date->day);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return 28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int daysInYear(int year) {
    return 365 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int daysBetweenDates(Date* date1, Date* date2) {
    int days = 0;
    if (date1->year == date2->year) {
        for (int i = date1->month; i < date2->month; i++) {
            days += daysInMonth(i, date1->year);
        }
        days += date2->day - date1->day;
    } else {
        for (int i = date1->year + 1; i < date2->year; i++) {
            days += daysInYear(i);
        }
        for (int i = date1->month; i <= 12; i++) {
            days += daysInMonth(i, date1->year);
        }
        for (int i = 1; i < date2->month; i++) {
            days += daysInMonth(i, date2->year);
        }
        days += date2->day - date1->day;
    }
    return days;
}

int main() {
    Date* date1 = createDate(2020, 3, 8);
    Date* date2 = createDate(2021, 5, 12);
    printDate(date1);
    printDate(date2);
    printf("Days between the dates: %d\n", daysBetweenDates(date1, date2));
    return 0;
}