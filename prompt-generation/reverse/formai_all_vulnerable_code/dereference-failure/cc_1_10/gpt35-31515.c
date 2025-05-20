//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to check if a given
// year is a leap year or not
int isLeapYear(int year) {
    // if a year is divisible by 4
    // and not divisible by 100
    // or if it's divisible by 400
    if ((year % 4 == 0 && year % 100 != 0) 
        || (year % 400 == 0))
        return 1;
    else
        return 0;
}

// function to convert a given
// date string to a number of days
int convertToDays(char* date) {
    // array of days in each month
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 
                        31, 31, 30, 31, 30, 31 };
    int day = atoi(strtok(date, "/"));
    int month = atoi(strtok(NULL, "/"));
    int year = atoi(strtok(NULL, "/"));
    int days = 0;

    // add days for each year since 1 AD
    for (int i = 1; i < year; i++) {
        if (isLeapYear(i))
            days += 366;
        else
            days += 365;
    }

    // add days for each month leading up to the given month
    for (int i = 1; i < month; i++) {
        // add one day for February if it's a leap year
        if (i == 2 && isLeapYear(year))
            days += 29;
        else
            days += monthDays[i - 1];
    }

    // add days for the given day in the given month
    days += day;

    return days;
}

// function to convert a given
// number of days to a date string
char* convertToDate(int days) {
    // array of days in each month
    int monthDays[] = { 31, 28, 31, 30, 31, 30, 
                        31, 31, 30, 31, 30, 31 };
    int year = 1;

    // subtract days for each year since 1 AD
    while (days > 365) {
        if (isLeapYear(year))
            days -= 366;
        else
            days -= 365;
        year++;
    }

    // subtract days for each month leading up to the given month
    int month = 1;
    while (days > monthDays[month - 1]) {
        if (month == 2 && isLeapYear(year))
            days -= 29;
        else
            days -= monthDays[month - 1];
        month++;
    }

    // get the day in the given month
    int day = days;

    // allocate memory for the date string
    char* date = (char*)malloc(11 * sizeof(char));

    // convert the day, month, and year to strings and concatenate them
    sprintf(date, "%02d/%02d/%04d", day, month, year);

    return date;
}

// main function to demonstrate the date converter
int main() {
    // print instructions
    printf("Please enter a date in the format DD/MM/YYYY:\n");

    // get the input date from the user
    char date[11];
    fgets(date, 11, stdin);

    // remove the newline character from the input
    date[strcspn(date, "\n")] = '\0';

    // convert the input date to a number of days and print it
    int days = convertToDays(date);
    printf("%d\n", days);

    // convert the number of days back to a date and print it
    char* newDate = convertToDate(days);
    printf("%s\n", newDate);

    // free the memory allocated for the new date string
    free(newDate);

    return 0;
}