//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int day, month, year;
} Date;

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void stringToDate(char* dateStr, Date* date) {
    int i, day, month, year;
    int len = strlen(dateStr);

    day = 0;
    month = 0;
    year = 0;

    for (i = 0; i < len && isdigit(dateStr[i]); i++) {
        day = day * 10 + (dateStr[i] - '0');
        if (i == 2) {
            month = day;
            day = 0;
        }
        if (i > 2 && (dateStr[i - 1] == '/' || dateStr[i - 1] == '-')) {
            if (i == len - 1) {
                year = day;
            } else {
                for (int j = i + 1; j < len && isdigit(dateStr[j]); j++) {
                    year = year * 10 + (dateStr[j] - '0');
                }
            }
            break;
        }
    }

    if (month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Invalid date format: %s\n", dateStr);
        exit(1);
    }

    if (month == 2) {
        if (isLeapYear(year)) {
            date->day = day;
            date->month = month;
            date->year = year;
        } else if (day > 29) {
            printf("Invalid date: %s\n", dateStr);
            exit(1);
        }
    } else if (isLeapYear(year) && month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            printf("Invalid date: %s\n", dateStr);
            exit(1);
        }
    } else if (day > 31) {
        printf("Invalid date: %s\n", dateStr);
        exit(1);
    }

    date->day = day;
    date->month = month;
    date->year = year;
}

void printDate(Date date) {
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("%d %s %d\n", date.day, months[date.month - 1], date.year);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s date_string (e.g.: 12/31/2021 or January 31, 2021)\n", argv[0]);
        return 1;
    }

    Date date;
    stringToDate(argv[1], &date);
    printDate(date);

    return 0;
}