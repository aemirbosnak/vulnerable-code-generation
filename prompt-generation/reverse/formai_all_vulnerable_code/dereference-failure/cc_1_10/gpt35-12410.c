//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Function to check if the given year is a leap year or not
int isLeapYear(int year) {
    if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0))) {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert the given date from natural language into a date string
char *convertToDateString(char *naturalLanguageDate) {
    int day, month, year;

    // Parse the natural language date and extract the day, month and year
    sscanf(naturalLanguageDate, "%d %*s %d %*s %d", &day, &month, &year);

    // Check if the given year is a leap year
    int isLeap = isLeapYear(year);

    // Initialize the number of days in each month
    int daysInMonth[] = {31, 28 + isLeap, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check if the given date is valid
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > daysInMonth[month - 1]) {
        return "Invalid Date";
    }

    // Initialize the array of month names
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Create a string to hold the formatted date
    char *dateString = (char *) malloc(sizeof(char) * 30);

    // Format the date string
    sprintf(dateString, "%d %s, %d", day, monthNames[month - 1], year);

    // Return the formatted date string
    return dateString;
}

int main() {
    // Test the function with some example dates
    char *date1 = "20th April 1992";
    char *date2 = "29th February 2000";
    char *date3 = "31st June 2021";
    char *date4 = "32nd January 1990";

    printf("%s\n", convertToDateString(date1));
    printf("%s\n", convertToDateString(date2));
    printf("%s\n", convertToDateString(date3));
    printf("%s\n", convertToDateString(date4));

    return 0;
}