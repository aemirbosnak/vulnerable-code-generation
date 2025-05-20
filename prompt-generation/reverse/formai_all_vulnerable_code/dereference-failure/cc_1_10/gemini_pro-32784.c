//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Date struct
typedef struct Date {
    int day;
    int month;
    int year;
} Date;

// Function to convert a string to a date
Date stringToDate(char *s) {
    // Check if the string is valid
    if (strlen(s) != 10) {
        fprintf(stderr, "Invalid date string: %s\n", s);
        exit(1);
    }

    // Convert the string to a date
    Date date;
    date.day = atoi(s);
    date.month = atoi(s + 3);
    date.year = atoi(s + 6);

    // Return the date
    return date;
}

// Function to convert a date to a string
char *dateToString(Date date) {
    // Allocate memory for the string
    char *s = malloc(11);

    // Convert the date to a string
    sprintf(s, "%02d/%02d/%04d", date.day, date.month, date.year);

    // Return the string
    return s;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a date
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <date>\n", argv[0]);
        exit(1);
    }

    // Convert the date to a string
    Date date = stringToDate(argv[1]);

    // Display the date in the MM/DD/YYYY format
    printf("Date: %s\n", dateToString(date));

    // Free the memory allocated for the string
    free(dateToString(date));

    return 0;
}