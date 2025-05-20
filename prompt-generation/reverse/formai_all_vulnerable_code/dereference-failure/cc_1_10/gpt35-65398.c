//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert month name to number
int month_to_number(char* month) {
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++) {
        if (strcmp(months[i], month) == 0) {
            return i + 1;
        }
    }

    return -1; // invalid month name
}

// function to check if year is a leap year
int is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    else if (year % 400 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// main function
int main() {
    char input_date[20];
    int day, month, year, days_in_month, total_days = 0;

    printf("Enter date in natural language (e.g. January 19, 2022): ");
    fgets(input_date, 20, stdin);

    // remove newline character
    input_date[strcspn(input_date, "\n")] = '\0';

    // parse input date
    char* token = strtok(input_date, " ");

    // get month and convert to number
    month = month_to_number(token);

    // check if month is valid
    if (month == -1) {
        printf("Invalid month name\n");
        return 1;
    }

    // get day
    token = strtok(NULL, " ");
    day = atoi(token);

    // get year
    token = strtok(NULL, " ");
    year = atoi(token);

    // check if year is valid
    if (year < 0) {
        printf("Invalid year\n");
        return 1;
    }

    // calculate total number of days since 1/1/1
    for (int i = 1; i < year; i++) {
        if (is_leap_year(i)) {
            total_days += 366;
        }
        else {
            total_days += 365;
        }
    }

    // calculate total number of days in current year
    for (int i = 1; i < month; i++) {
        switch (i) {
            case 2:
                if (is_leap_year(year)) {
                    days_in_month = 29;
                }
                else {
                    days_in_month = 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                days_in_month = 30;
                break;
            default:
                days_in_month = 31;
        }

        total_days += days_in_month;
    }

    total_days += day;

    printf("%s is day number %d of the year %d\n", input_date, total_days, year);

    return 0;
}