//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date {
    int year;
    int month;
    int day;
};

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 ==0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int days_in_leap_year_month(int month) {
    if (month == 2) {
        return 29;
    } else {
        return days_in_month[month];
    }
}

int days_in_month_in_year(int month, int year) {
    if (is_leap_year(year)) {
        return days_in_leap_year_month(month);
    } else {
        return days_in_month[month];
    }
}

long int day_number(struct date date) {
    long int days = date.day;

    for (int i = 1; i < date.month; i++) {
        days += days_in_month_in_year(i, date.year);
    }

    for (int i = 1; i < date.year; i++) {
        if (is_leap_year(i)) {
            days += 366;
        } else {
            days += 365;
        }
    }

    return days;
}

struct date date_from_day_number(long int dn) {
    struct date date;
    int year = 1;
    int month = 1;

    while (1) {
        int days_in_year = 365;

        if (is_leap_year(year)) {
            days_in_year = 366;
        }

        if (dn - days_in_year < 0) {
            break;
        }

        year++;
        dn -= days_in_year;
    }

    while (1) {
        int days_in_month = days_in_month_in_year(month, year);

        if (dn - days_in_month < 0) {
            break;
        }

        month++;
        dn -= days_in_month;
    }

    date.year = year;
    date.month = month;
    date.day = dn;

    return date;
}

int main() {
    char input[100];

    printf("Enter a date in the format (MM/DD/YYYY): ");
    fgets(input, 100, stdin);

    char *month_str = strtok(input, "/");
    char *day_str = strtok(NULL, "/");
    char *year_str = strtok(NULL, "");

    int month = atoi(month_str);
    int day = atoi(day_str);
    int year = atoi(year_str);

    struct date date;
    date.year = year;
    date.month = month;
    date.day = day;

    long int dn = day_number(date);
    struct date result_date = date_from_day_number(dn);

    printf("Converted date: %02d/%02d/%04d\n", result_date.month, result_date.day, result_date.year);

    return 0;
}