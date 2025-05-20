//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to calculate leap year
int isLeapYear(int year) {
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

//function to calculate days in the month
int daysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year)) {
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
    char input[100];
    int day, month, year, totalDays = 0;
    printf("Enter a date in natural language (e.g. January 1, 2022): ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0'; //remove the newline character at the end
    
    char* monthStr = strtok(input, " ");
    char* dayStr = strtok(NULL, " ");
    char* yearStr = strtok(NULL, " ");
    
    //convert month string to integer
    if (strcmp(monthStr, "January") == 0) {
        month = 1;
    } else if (strcmp(monthStr, "February") == 0) {
        month = 2;
    } else if (strcmp(monthStr, "March") == 0) {
        month = 3;
    } else if (strcmp(monthStr, "April") == 0) {
        month = 4;
    } else if (strcmp(monthStr, "May") == 0) {
        month = 5;
    } else if (strcmp(monthStr, "June") == 0) {
        month = 6;
    } else if (strcmp(monthStr, "July") == 0) {
        month = 7;
    } else if (strcmp(monthStr, "August") == 0) {
        month = 8;
    } else if (strcmp(monthStr, "September") == 0) {
        month = 9;
    } else if (strcmp(monthStr, "October") == 0) {
        month = 10;
    } else if (strcmp(monthStr, "November") == 0) {
        month = 11;
    } else {
        month = 12;
    }
    
    day = atoi(dayStr);
    year = atoi(yearStr);
    
    //calculate total number of days
    for (int i = 1; i < month; i++) {
        totalDays += daysInMonth(i, year);
    }
    totalDays += day;
    
    printf("%s is day %d of the year %d.\n", input, totalDays, year);
    
    return 0;
}