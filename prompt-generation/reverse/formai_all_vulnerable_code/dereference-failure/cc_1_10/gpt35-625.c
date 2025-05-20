//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DATE_INPUT_LENGTH 20

// Function to check if the given year is a leap year or not
bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else {
        return true;
    }
}

// Function to calculate the number of days in a given month and year
int getDaysInMonth(int month, int year) {
    int daysInMonth;
    if (month == 2) {
        daysInMonth = isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    }
    else {
        daysInMonth = 31;
    }
    return daysInMonth;
}

// Function to convert a date string in natural language to a date in DD/MM/YYYY format
char* convertDate(char* inputDate) {
    int day, month, year;
    char* date = (char*) malloc(sizeof(char) * 11);

    // tokenize the input date string
    char* token = strtok(inputDate, " ");
    if (token != NULL) {
        // extract the day
        day = atoi(token);
        token = strtok(NULL, " ");
        if (token != NULL) {
            // extract the month
            if (strcmp(token, "January") == 0) {
                month = 1;
            }
            else if (strcmp(token, "February") == 0) {
                month = 2;
            }
            else if (strcmp(token, "March") == 0) {
                month = 3;
            }
            else if (strcmp(token, "April") == 0) {
                month = 4;
            }
            else if (strcmp(token, "May") == 0) {
                month = 5;
            }
            else if (strcmp(token, "June") == 0) {
                month = 6;
            }
            else if (strcmp(token, "July") == 0) {
                month = 7;
            }
            else if (strcmp(token, "August") == 0) {
                month = 8;
            }
            else if (strcmp(token, "September") == 0) {
                month = 9;
            }
            else if (strcmp(token, "October") == 0) {
                month = 10;
            }
            else if (strcmp(token, "November") == 0) {
                month = 11;
            }
            else if (strcmp(token, "December") == 0) {
                month = 12;
            }
            else {
                return "Error: Invalid month name in input!";
            }

            token = strtok(NULL, " ");
            if (token != NULL) {
                //extract the year
                year = atoi(token);
            }
            else {
                return "Error: Year not found in input!";
            }
        }
        else {
            return "Error: Month not found in input!";
        }
    }
    else {
        return "Error: Day not found in input!";
    }

    // check if the input date is valid
    if (day < 1 || day > getDaysInMonth(month, year)) {
        return "Error: Invalid day for month and year!";
    }
    else {
        sprintf(date, "%02d/%02d/%d", day, month, year);
        return date;
    }
}

// main program
int main() {
    char inputDate[MAX_DATE_INPUT_LENGTH];
    printf("Enter a date in natural language (e.g. 1st January 2022): ");
    fgets(inputDate, MAX_DATE_INPUT_LENGTH, stdin);

    // remove trailing newline character from input
    inputDate[strcspn(inputDate, "\n")] = 0;

    char* outputDate = convertDate(inputDate);
    printf("%s\n", outputDate);
    free(outputDate);

    return 0;
}