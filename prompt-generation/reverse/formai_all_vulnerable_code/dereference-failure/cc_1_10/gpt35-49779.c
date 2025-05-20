//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: irregular
#include <stdio.h>
#include <string.h>

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 100 == 0) {
        return 0;
    }
    if (year % 4 == 0) {
        return 1;
    }
    return 0;
}

// Function to get the number of days in a given month and year
int getDaysOfMonth(int month, int year) {
    switch(month) {
        case 1:
            return 31;
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return -1;
    }
}

// Function to convert a date string to a date object
void convertToDate(int day, char *monthName, int year) {
    int month;
    if (strcmp(monthName, "January") == 0) {
        month = 1;
    } else if (strcmp(monthName, "February") == 0) {
        month = 2;
    } else if (strcmp(monthName, "March") == 0) {
        month = 3;
    } else if (strcmp(monthName, "April") == 0) {
        month = 4;
    } else if (strcmp(monthName, "May") == 0) {
        month = 5;
    } else if (strcmp(monthName, "June") == 0) {
        month = 6;
    } else if (strcmp(monthName, "July") == 0) {
        month = 7;
    } else if (strcmp(monthName, "August") == 0) {
        month = 8;
    } else if (strcmp(monthName, "September") == 0) {
        month = 9;
    } else if (strcmp(monthName, "October") == 0) {
        month = 10;
    } else if (strcmp(monthName, "November") == 0) {
        month = 11;
    } else if (strcmp(monthName, "December") == 0) {
        month = 12;
    } else {
        printf("Invalid month name.\n");
        return;
    }
    
    if (day < 1 || day > getDaysOfMonth(month, year)) {
        printf("Invalid day.\n");
        return;
    }
    
    printf("%d-%02d-%02d\n", year, month, day);
}

// Main function to handle user input and output
int main() {
    int day, year;
    char *monthName = (char*) malloc(10 * sizeof(char));
    
    printf("Enter date in natural language (e.g. March 15, 2022): ");
    scanf("%s %d, %d", monthName, &day, &year);
    
    convertToDate(day, monthName, year);
    
    free(monthName);
    return 0;
}