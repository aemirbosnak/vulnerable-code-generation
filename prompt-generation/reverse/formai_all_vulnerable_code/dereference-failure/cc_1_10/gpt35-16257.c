//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int daysInMonth(int month, int year) {
    int days;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days = 29; // Leap year calculation
        } else {
            days = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days = 30;
    } else {
        days = 31;
    }
    return days;
}

void convertToDate(int days, int year) {
    int month = 1;
    int month_days = daysInMonth(month, year);
    while (days > month_days) {
        days -= month_days;
        month++;
        month_days = daysInMonth(month, year);
    }
    printf("%d-%d-%d", year, month, days);
}

void convertToDays(int day, int month, int year) {
    int days = 0;
    for (int i = 1; i < month; i++) {
        days += daysInMonth(i, year);
    }
    days += day;
    printf("%d", days);
}

int main() {
    printf("Welcome to the visionary C natural language date converter!\n");
    printf("Please enter either a date in the format YYYY-MM-DD or a number of days: ");
    char input[11];
    fgets(input, 11, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input
    if (strchr(input, '-') != NULL) { // Date input
        strtok(input, "-"); // Ignore year
        char *month = strtok(NULL, "-");
        char *day = strtok(NULL, "-");
        convertToDays(atoi(day), atoi(month), atoi(strtok(input, "-")));
    } else { // Number of days input
        printf("Please enter the year: ");
        char year_input[5];
        fgets(year_input, 5, stdin);
        convertToDate(atoi(input), atoi(year_input));
    }
    return 0;
}