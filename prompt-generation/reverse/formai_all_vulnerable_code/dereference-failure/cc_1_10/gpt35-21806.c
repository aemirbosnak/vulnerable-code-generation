//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// function to check if a given year is a leap year
bool isLeapYear(int year) {

    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

// function to get the number of days in a month
int getDaysInMonth(int month, int year) {

    if (month < 1 || month > 12)
        return -1;

    int days;

    switch (month) {
        case 2:
            if (isLeapYear(year))
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    return days;
}

// function to convert a C Natural Language Date to a date in ISO 8601 format (YYYY-MM-DD)
char* convertCNLDate(char* cnlDate) {

    int day, month, year;

    // convert the day
    day = cnlDate[0] - '0';
    if (isdigit(cnlDate[1]))
        day = day * 10 + cnlDate[1] - '0';

    // convert the year
    size_t len = strlen(cnlDate);
    year = cnlDate[len-4] - '0';
    for (int i=len-3; i<len; i++) {
        if (isdigit(cnlDate[i]))
            year = year * 10 + cnlDate[i] - '0';
    }

    // convert the month
    char* monthStr = strtok(cnlDate, " ");
    month = 0;

    if (strcasecmp(monthStr, "January") == 0)
        month = 1;
    else if (strcasecmp(monthStr, "February") == 0)
        month = 2;
    else if (strcasecmp(monthStr, "March") == 0)
        month = 3;
    else if (strcasecmp(monthStr, "April") == 0)
        month = 4;
    else if (strcasecmp(monthStr, "May") == 0)
        month = 5;
    else if (strcasecmp(monthStr, "June") == 0)
        month = 6;
    else if (strcasecmp(monthStr, "July") == 0)
        month = 7;
    else if (strcasecmp(monthStr, "August") == 0)
        month = 8;
    else if (strcasecmp(monthStr, "September") == 0)
        month = 9;
    else if (strcasecmp(monthStr, "October") == 0)
        month = 10;
    else if (strcasecmp(monthStr, "November") == 0)
        month = 11;
    else if (strcasecmp(monthStr, "December") == 0)
        month = 12;
    else
        return "";

    // get the number of days in the month
    int daysInMonth = getDaysInMonth(month, year);

    // if the day is invalid, or the month has the wrong number of days, return an empty string
    if (day < 1 || day > daysInMonth)
        return "";

    // format the date as YYYY-MM-DD
    char* isoDate = malloc(sizeof(char) * 11);
    sprintf(isoDate, "%04d-%02d-%02d", year, month, day);

    return isoDate;
}

// main function
int main() {

    // example CNL dates
    char* cnlDate1 = "12 January 2022";
    char* cnlDate2 = "29 February 2000";
    char* cnlDate3 = "31 November 2021";
    char* cnlDate4 = "15 October 2022";

    // convert the dates to ISO 8601 format
    char* isoDate1 = convertCNLDate(cnlDate1);
    char* isoDate2 = convertCNLDate(cnlDate2);
    char* isoDate3 = convertCNLDate(cnlDate3);
    char* isoDate4 = convertCNLDate(cnlDate4);

    // print the results
    printf("%s -> %s\n", cnlDate1, isoDate1);
    printf("%s -> %s\n", cnlDate2, isoDate2);
    printf("%s -> %s\n", cnlDate3, isoDate3);
    printf("%s -> %s\n", cnlDate4, isoDate4);

    // free the memory used by the ISO dates
    free(isoDate1);
    free(isoDate2);
    free(isoDate3);
    free(isoDate4);

    return 0;
}