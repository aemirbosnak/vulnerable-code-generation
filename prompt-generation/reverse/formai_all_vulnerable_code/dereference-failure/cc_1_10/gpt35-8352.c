//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <string.h>

// Function to check if year is leap year or not
int isLeapYear(int year) {
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

// Function to convert C natural language date to date string
char* convertToDate(char* dateInput) {
    char month[10];
    int day, year, monthNum;
    sscanf(dateInput, "%s %d, %d", month, &day, &year);
    char* result = (char*) malloc(sizeof(char) * 11);  // allocate memory for date string
    if(strcmp(month, "January") == 0) {
        monthNum = 1;
    } else if(strcmp(month, "February") == 0) {
        monthNum = 2;
    } else if(strcmp(month, "March") == 0) {
        monthNum = 3;
    } else if(strcmp(month, "April") == 0) {
        monthNum = 4;
    } else if(strcmp(month, "May") == 0) {
        monthNum = 5;
    } else if(strcmp(month, "June") == 0) {
        monthNum = 6;
    } else if(strcmp(month, "July") == 0) {
        monthNum = 7;
    } else if(strcmp(month, "August") == 0) {
        monthNum = 8;
    } else if(strcmp(month, "September") == 0) {
        monthNum = 9;
    } else if(strcmp(month, "October") == 0) {
        monthNum = 10;
    } else if(strcmp(month, "November") == 0) {
        monthNum = 11;
    } else if(strcmp(month, "December") == 0) {
        monthNum = 12;
    } else {
        return "Invalid month input!";
    }
    sprintf(result, "%02d/%02d/%04d", monthNum, day, year);
    return result;
}

// Function to convert C natural language date to Julian day
int convertToJulianDay(char* dateInput) {
    char month[10];
    int day, year, monthNum, daysInMonth;
    sscanf(dateInput, "%s %d, %d", month, &day, &year);
    if(strcmp(month, "January") == 0) {
        monthNum = 1;
        daysInMonth = 31;
    } else if(strcmp(month, "February") == 0) {
        monthNum = 2;
        if(isLeapYear(year)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if(strcmp(month, "March") == 0) {
        monthNum = 3;
        daysInMonth = 31;
    } else if(strcmp(month, "April") == 0) {
        monthNum = 4;
        daysInMonth = 30;
    } else if(strcmp(month, "May") == 0) {
        monthNum = 5;
        daysInMonth = 31;
    } else if(strcmp(month, "June") == 0) {
        monthNum = 6;
        daysInMonth = 30;
    } else if(strcmp(month, "July") == 0) {
        monthNum = 7;
        daysInMonth = 31;
    } else if(strcmp(month, "August") == 0) {
        monthNum = 8;
        daysInMonth = 31;
    } else if(strcmp(month, "September") == 0) {
        monthNum = 9;
        daysInMonth = 30;
    } else if(strcmp(month, "October") == 0) {
        monthNum = 10;
        daysInMonth = 31;
    } else if(strcmp(month, "November") == 0) {
        monthNum = 11;
        daysInMonth = 30;
    } else if(strcmp(month, "December") == 0) {
        monthNum = 12;
        daysInMonth = 31;
    } else {
        return -1;
    }
    int julianDay = day;
    for(int i = 1; i < monthNum; i++) {
        julianDay += daysInMonth;
    }
    return julianDay;
}

int main() {
    char* dateInput = "January 1, 2022";
    printf("Date Input: %s\n", dateInput);
    char* dateStr = convertToDate(dateInput);
    printf("Date String: %s\n", dateStr);
    int julianDay = convertToJulianDay(dateInput);
    printf("Julian Day: %d\n", julianDay);
    return 0;
}