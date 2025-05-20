//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* monthNames[] = {
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

int day_of_month(int month, int year) {
    switch (month) {
        case 2:
            if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                return 29;
            }
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s \"March 12, 2020\"\n", argv[0]);
        return 1;
    }

    struct tm date;
    if (strptime(argv[1], "%B %d, %Y", &date) == NULL) {
        printf("Invalid date format: %s\n", argv[1]);
        return 1;
    }

    time_t epoch_time = mktime(&date);

    printf("Date entered: %s\n", argv[1]);
    printf("Date in epoch time: %ld\n", epoch_time);

    struct tm* converted_date = localtime(&epoch_time);
    int month = converted_date->tm_mon;
    int year = converted_date->tm_year + 1900;
    int day = converted_date->tm_mday;

    printf("Date in C natural language: %s %d, %d\n", monthNames[month], day, year);
    printf("Days in this month: %d\n", day_of_month(month + 1, year));

    return 0;
}