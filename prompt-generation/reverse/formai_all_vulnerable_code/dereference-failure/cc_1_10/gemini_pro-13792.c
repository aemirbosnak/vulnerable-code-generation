//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A leap year is a year that is divisible by 4, but not by 100, or is divisible by 400.
int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// The number of days in each month, for non-leap years.
int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// The number of days in each month, for leap years.
int days_in_leap_month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Convert a date from the Gregorian calendar to the Julian calendar.
void gregorian_to_julian(int year, int month, int day, int *julian_year, int *julian_month, int *julian_day) {
    int days_since_epoch = 0;

    // Add the days in the years up to the current year.
    for (int i = 1; i < year; i++) {
        days_since_epoch += is_leap_year(i) ? 366 : 365;
    }

    // Add the days in the months up to the current month.
    for (int i = 1; i < month; i++) {
        days_since_epoch += is_leap_year(year) ? days_in_leap_month[i - 1] : days_in_month[i - 1];
    }

    // Add the days in the current month.
    days_since_epoch += day;

    // Convert the days since the epoch to the Julian calendar.
    *julian_year = days_since_epoch / 365.25;
    *julian_month = (days_since_epoch - (*julian_year * 365.25)) / 30.6;
    *julian_day = days_since_epoch - (*julian_year * 365.25) - (*julian_month * 30.6);
}

// Convert a date from the Julian calendar to the Gregorian calendar.
void julian_to_gregorian(int year, int month, int day, int *gregorian_year, int *gregorian_month, int *gregorian_day) {
    int days_since_epoch = 0;

    // Add the days in the years up to the current year.
    for (int i = 1; i < year; i++) {
        days_since_epoch += 365.25;
    }

    // Add the days in the months up to the current month.
    for (int i = 1; i < month; i++) {
        days_since_epoch += 30.6;
    }

    // Add the days in the current month.
    days_since_epoch += day;

    // Convert the days since the epoch to the Gregorian calendar.
    *gregorian_year = days_since_epoch / 365.2425;
    *gregorian_month = (days_since_epoch - (*gregorian_year * 365.2425)) / 30.44;
    *gregorian_day = days_since_epoch - (*gregorian_year * 365.2425) - (*gregorian_month * 30.44);
}

int main() {
    // Get the current date and time.
    time_t now = time(NULL);
    struct tm *current_time = gmtime(&now);

    // Convert the current date to the Julian calendar.
    int julian_year, julian_month, julian_day;
    gregorian_to_julian(current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, &julian_year, &julian_month, &julian_day);

    // Print the current date in the Julian calendar.
    printf("The current date in the Julian calendar is: %d-%d-%d\n", julian_year, julian_month, julian_day);

    // Convert the current date to the Gregorian calendar.
    int gregorian_year, gregorian_month, gregorian_day;
    julian_to_gregorian(julian_year, julian_month, julian_day, &gregorian_year, &gregorian_month, &gregorian_day);

    // Print the current date in the Gregorian calendar.
    printf("The current date in the Gregorian calendar is: %d-%d-%d\n", gregorian_year, gregorian_month, gregorian_day);

    return 0;
}