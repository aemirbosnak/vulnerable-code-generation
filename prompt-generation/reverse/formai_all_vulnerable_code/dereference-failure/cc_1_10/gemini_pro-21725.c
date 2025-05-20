//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Date structure
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// Function to convert a string to a date
Date stringToDate(char *str) {
    Date date;

    // Check if the string is valid
    if (strlen(str) != 10) {
        fprintf(stderr, "Invalid date format: %s\n", str);
        exit(EXIT_FAILURE);
    }

    // Get the day
    date.day = atoi(str);

    // Get the month
    date.month = atoi(str + 3);

    // Get the year
    date.year = atoi(str + 6);

    // Return the date
    return date;
}

// Function to convert a date to a string
char *dateToString(Date date) {
    char *str = malloc(11);

    // Convert the day to a string
    sprintf(str, "%02d", date.day);

    // Convert the month to a string
    sprintf(str + 3, "%02d", date.month);

    // Convert the year to a string
    sprintf(str + 6, "%04d", date.year);

    // Return the string
    return str;
}

// Function to print a date
void printDate(Date date) {
    printf("%s\n", dateToString(date));
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a date
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the date to a structure
    Date date = stringToDate(argv[1]);

    // Print the date
    printDate(date);

    return EXIT_SUCCESS;
}