//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to store the date
typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function to convert a string to a date
Date stringToDate(char *str) {
    Date date;

    // Get the year
    date.year = atoi(strtok(str, "-"));

    // Get the month
    date.month = atoi(strtok(NULL, "-"));

    // Get the day
    date.day = atoi(strtok(NULL, "-"));

    return date;
}

// Function to convert a date to a string
char *dateToString(Date date) {
    char *str = malloc(sizeof(char) * 11);

    // Convert the year to a string
    sprintf(str, "%d-", date.year);

    // Convert the month to a string
    sprintf(str, "%s%d-", str, date.month);

    // Convert the day to a string
    sprintf(str, "%s%d", str, date.day);

    return str;
}

// Main function
int main() {
    // Get the input date
    char *str = "2020-12-31";

    // Convert the string to a date
    Date date = stringToDate(str);

    // Print the date
    printf("The date is: %s\n", dateToString(date));

    return 0;
}