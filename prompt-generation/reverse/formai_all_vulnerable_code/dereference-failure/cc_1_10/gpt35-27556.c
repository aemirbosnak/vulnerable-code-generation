//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function declarations to be used later
int is_leap_year(int year);
int days_in_month(int month, int year);

int main() {
    // define variables for input date
    int day, month, year;

    // prompt user for input date
    printf("Enter date in natural language (e.g. January 1, 2000): ");
    char input[20];
    fgets(input, 20, stdin);

    // extract month, day and year from input string
    char *month_str = strtok(input, " ");
    char *day_str = strtok(NULL, ", ");
    char *year_str = strtok(NULL, " ");
    month = atoi(month_str);
    day = atoi(day_str);
    year = atoi(year_str);

    // initialize variables for conversion
    int days = 0;
    int i;

    // count number of days since beginning of year
    for (i = 1; i < month; i++) {
        days += days_in_month(i, year);
    }
    days += day;

    // check if it is a leap year and adjust number of days accordingly
    if (is_leap_year(year) && month > 2) {
        days++;
    }

    // display result
    printf("%s%d%s%d%s%d%s%d%s", "The date ", month, "/", day, "/", year, " is equivalent to day ", days, " of the year.\n");

    return 0;
}

// function to check if a given year is a leap year
int is_leap_year(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

// function to determine number of days in a given month
int days_in_month(int month, int year) {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return is_leap_year(year) ? 29 : 28;
        default:
            return 31;
    }
}