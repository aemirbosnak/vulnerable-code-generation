//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100
#define MAX_BUFFER_LENGTH 256

// Function Declarations
void convertNaturalLanguageDate(const char *inputDate);
int isLeapYear(int year);
char *trimWhitespace(char *str);
void parseDateComponents(const char *input, int *day, int *month, int *year);
void printFormattedDate(int day, int month, int year);

// Main Function
int main() {
    char input[MAX_DATE_LENGTH];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in natural language (e.g., 'March 5, 2023'):\n");

    // Input reading loop
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        convertNaturalLanguageDate(input);
    }

    return 0;
}

// Convert the natural language date into a recognizable format
void convertNaturalLanguageDate(const char *inputDate) {
    int day = 0, month = 0, year = 0;

    // Clean the input string
    char cleanInput[MAX_DATE_LENGTH];
    strcpy(cleanInput, trimWhitespace((char *)inputDate));

    // Parse the date components
    parseDateComponents(cleanInput, &day, &month, &year);

    // Check for validity
    if (day <= 0 || month <= 0 || month > 12 || year < 1900) {
        printf("Invalid date provided. Please try again.\n");
        return;
    }

    // Print the formatted date
    printFormattedDate(day, month, year);
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    }
    return 0; // Not a leap year
}

// Function to trim whitespace from a string
char *trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after last non-whitespace character
    *(end + 1) = '\0';

    return str;
}

// Function to parse the input string for day, month, and year
void parseDateComponents(const char *input, int *day, int *month, int *year) {
    struct tm tm = {0};
    char monthName[20];
    char format[MAX_BUFFER_LENGTH];

    // Try to match the pattern with sscanf
    if (sscanf(input, "%s %d, %d", monthName, day, year) == 3) {
        // Convert month name to month number
        strptime(monthName, "%B", &tm); // Full month name
        *month = tm.tm_mon + 1; // tm_mon is 0-11
    } else if (sscanf(input, "%d/%d/%d", day, month, year) == 3) {
        // Already in numerical format (DD/MM/YYYY)
    } else {
        printf("Cannot understand the date format. Please try again.\n");
        *day = 0;
        *month = 0;
        *year = 0;
    }
}

// Function to print the formatted date
void printFormattedDate(int day, int month, int year) {
    char *monthNames[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    // Check for month validity based on days
    static const int monthDays[] = { 31, 28, 31, 30, 31, 30, 
                                      31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year)) {
        if (day > 29) {
            printf("Invalid date: February can only have 29 days in a leap year.\n");
            return;
        }
    } else if (day > monthDays[month - 1]) {
        printf("Invalid date: Month %d can only have %d days.\n", month, monthDays[month - 1]);
        return;
    }

    printf("Formatted Date: %s %d, %d\n", monthNames[month - 1], day, year);
}