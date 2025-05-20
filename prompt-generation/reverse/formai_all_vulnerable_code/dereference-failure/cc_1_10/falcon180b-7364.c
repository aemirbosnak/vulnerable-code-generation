//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STR_LEN 100

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef enum {
    MONTH_JANUARY,
    MONTH_FEBRUARY,
    MONTH_MARCH,
    MONTH_APRIL,
    MONTH_MAY,
    MONTH_JUNE,
    MONTH_JULY,
    MONTH_AUGUST,
    MONTH_SEPTEMBER,
    MONTH_OCTOBER,
    MONTH_NOVEMBER,
    MONTH_DECEMBER
} Month;

char* month_names[] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

char* weekday_names[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

void print_date(Date* date) {
    printf("%s %d, %d\n", month_names[date->month - 1], date->day, date->year);
}

void print_weekday(Date* date) {
    printf("%s\n", weekday_names[date->day % 7]);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <day> <month> <year>\n", argv[0]);
        return 1;
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]) - 1;
    int year = atoi(argv[3]);

    if (month < 0 || month > 11) {
        printf("Invalid month.\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 1;
    }

    if (year < 1900 || year > 2100) {
        printf("Invalid year.\n");
        return 1;
    }

    Date date = {year, month + 1, day};
    printf("Date: ");
    print_date(&date);
    printf("Weekday: ");
    print_weekday(&date);

    return 0;
}