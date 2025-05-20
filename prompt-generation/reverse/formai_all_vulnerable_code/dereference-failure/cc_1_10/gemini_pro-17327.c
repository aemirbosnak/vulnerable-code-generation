//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

typedef struct {
    int day;
    Month month;
    int year;
} Date;

Date parseDate(char *dateString) {
    Date date;
    char *dayString, *monthString, *yearString;
    int day, month, year;

    // Extract the day, month, and year strings from the date string.
    dayString = strtok(dateString, "-");
    monthString = strtok(NULL, "-");
    yearString = strtok(NULL, "-");

    // Convert the day, month, and year strings to integers.
    day = atoi(dayString);
    month = atoi(monthString);
    year = atoi(yearString);

    // Create a Date struct and initialize it with the converted values.
    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

void printDate(Date date) {
    printf("%d-%d-%d\n", date.day, date.month, date.year);
}

int main(int argc, char *argv[]) {
    Date date;

    // Parse the date string from the command line.
    date = parseDate(argv[1]);

    // Print the date in the format YYYY-MM-DD.
    printDate(date);

    return 0;
}