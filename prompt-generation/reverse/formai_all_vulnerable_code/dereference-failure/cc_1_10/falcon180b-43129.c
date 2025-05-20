//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 20
#define MAX_MONTH_NAME_LENGTH 10

// Function to convert a number to its string representation
char* numberToString(int number) {
    char* result = malloc(3 * sizeof(char));
    if (result == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }
    sprintf(result, "%d", number);
    return result;
}

// Function to convert a month number to its name
char* monthNumberToName(int monthNumber) {
    static char* monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    if (monthNumber < 1 || monthNumber > 12) {
        printf("Error: Invalid month number.\n");
        exit(1);
    }
    return monthNames[monthNumber - 1];
}

// Function to parse a date string and return its components
void parseDate(char* dateString, int* day, int* month, int* year) {
    char* token = strtok(dateString, " ");
    if (token == NULL) {
        printf("Error: Invalid date format.\n");
        exit(1);
    }
    *day = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Error: Invalid date format.\n");
        exit(1);
    }
    *month = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Error: Invalid date format.\n");
        exit(1);
    }
    *year = atoi(token);
}

// Function to print a date in natural language format
void printDate(int day, int month, int year) {
    char* monthName = monthNumberToName(month);
    printf("On the %s of %s, in the year %d,\n", numberToString(day), monthName, year);
}

// Function to convert a date string to natural language format
void convertDate(char* dateString) {
    int day, month, year;
    parseDate(dateString, &day, &month, &year);
    printDate(day, month, year);
}

int main() {
    char dateString[MAX_DATE_LENGTH];
    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(dateString, MAX_DATE_LENGTH, stdin);
    convertDate(dateString);
    return 0;
}