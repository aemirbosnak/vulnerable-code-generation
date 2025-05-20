//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    // A leap year is divisible by 4, but not 100 unless it's also divisible by 400
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int days_in_month(int month, int year) {
    // Determine number of days in the given month
    switch (month) {
        case 2:
            if (is_leap_year(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void convert_date(char input_date[11]) {
    // Extract day, month, and year from the input date string
    int day = atoi(&input_date[0]);
    int month = atoi(&input_date[3]);
    int year = atoi(&input_date[6]);

    // Check if input date is valid
    if ((day < 1) || (day > days_in_month(month, year)) || (month < 1) || (month > 12) || (year < 1)) {
        printf("Invalid date format.\n");
        return;
    }

    // Initialize variables to hold the total number of days and the number of days in each month
    int total_days = 0;
    int days_in_each_month[12] = { 31, 28 + is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Calculate the total number of days elapsed since January 1, year 1
    for (int i = 1; i < month; i++) {
        total_days += days_in_each_month[i-1];
    }
    total_days += day - 1;

    // Calculate the year, month, and day corresponding to the total number of days
    int y = 1;
    int m = 1;
    int d;
    while (total_days >= 365 + is_leap_year(y)) {
        if (is_leap_year(y)) {
            total_days -= 366;
        } else {
            total_days -= 365;
        }
        y++;
    }
    while (total_days >= days_in_each_month[m-1]) {
        total_days -= days_in_each_month[m-1];
        m++;
    }
    d = total_days + 1;

    // Print the converted date in the desired format
    printf("%d-%02d-%02d\n", y, m, d);
}

int main() {
    char input_date[11];

    // Obtain input date from user
    printf("Enter date in format dd-mm-yyyy: ");
    scanf("%10s", input_date);

    // Convert input date and print result
    convert_date(input_date);

    return 0;
}