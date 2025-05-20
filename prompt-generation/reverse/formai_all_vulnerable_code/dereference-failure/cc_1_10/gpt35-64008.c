//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * For this program to work, the user must input a date in the format
 * "day month year", for example "1 January 2020".
 */

const char *months[12] = {"January", "February", "March", "April", "May",
                          "June", "July", "August", "September", "October",
                          "November", "December"};

int numberOfDays(int month, int year) {
    /*
     * Calculates the number of days in a given month and year.
     */
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int main() {
    char input[20]; // Store input from user
    int day, month, year, i;

    printf("Please enter a date (format: day month year): ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\r\n")] = 0; // Remove newline character from input

    char *token = strtok(input, " ");
    day = atoi(token);
    token = strtok(NULL, " ");
    for (i = 0; i < 12; i++) {
        if (strcmp(token, months[i]) == 0) {
            month = i + 1;
            break;
        }
    }
    token = strtok(NULL, " ");
    year = atoi(token);

    // Convert date to number of days since January 1, 1 AD
    int totalDays = 0;
    for (i = 1; i < year; i++) {
        int daysInYear = (i % 4 == 0 && i % 100 != 0) || i % 400 == 0 ? 366 : 365;
        totalDays += daysInYear;
    }
    for (i = 1; i < month; i++) {
        totalDays += numberOfDays(i, year);
    }
    totalDays += day;

    // Convert number of days since January 1, 1 AD to new date
    int newDay = totalDays % 31;
    int newMonth = (totalDays / 31) % 12;
    int newYear = (totalDays / 31) / 12 + 1;

    printf("That date in C natural language is: %d %s %d\n", newDay, months[newMonth], newYear);

    return 0;
}