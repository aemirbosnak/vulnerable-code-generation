//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day;
    int month;
    int year;
};

int getMonth(char* monthStr) {
    if (strcmp(monthStr, "January") == 0) return 1;
    if (strcmp(monthStr, "February") == 0) return 2;
    if (strcmp(monthStr, "March") == 0) return 3;
    if (strcmp(monthStr, "April") == 0) return 4;
    if (strcmp(monthStr, "May") == 0) return 5;
    if (strcmp(monthStr, "June") == 0) return 6;
    if (strcmp(monthStr, "July") == 0) return 7;
    if (strcmp(monthStr, "August") == 0) return 8;
    if (strcmp(monthStr, "September") == 0) return 9;
    if (strcmp(monthStr, "October") == 0) return 10;
    if (strcmp(monthStr, "November") == 0) return 11;
    if (strcmp(monthStr, "December") == 0) return 12;
    return -1; // invalid month
}

int isLeapYear(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0; // invalid date
    }
    if (month == 2) { // February
        if (isLeapYear(year) && day > 29) {
            return 0; // invalid date
        } else if (day > 28) {
            return 0; // invalid date
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) { // 30-day months
        if (day > 30) {
            return 0; // invalid date
        }
    } else { // 31-day months
        if (day > 31) {
            return 0; // invalid date
        }
    }
    return 1; // valid date
}

int main() {
    char input[100];
    printf("Enter a date in natural language format (e.g. \"December 31, 2021\"): ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0'; // remove newline character
    
    char* monthStr = strtok(input, " ,");
    int day = atoi(strtok(NULL, " ,"));
    int year = atoi(strtok(NULL, " ,"));
    
    int month = getMonth(monthStr);
    if (month == -1) {
        printf("Invalid month name\n");
        return 0;
    }
    
    if (!isValidDate(day, month, year)) {
        printf("Invalid date\n");
        return 0;
    }
    
    char date[11];
    sprintf(date, "%04d-%02d-%02d", year, month, day);
    printf("Converted date: %s\n", date);
    
    return 0;
}