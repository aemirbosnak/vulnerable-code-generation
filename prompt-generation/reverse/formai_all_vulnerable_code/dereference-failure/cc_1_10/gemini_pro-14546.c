//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 11

typedef struct {
    int year;
    int month;
    int day;
} Date;

// Function to convert a string to a date
Date string_to_date(char *date_string) {
    Date date;

    // Check if the date string is valid
    if (strlen(date_string) != MAX_DATE_LENGTH) {
        fprintf(stderr, "Invalid date string: %s\n", date_string);
        exit(1);
    }

    // Parse the date string
    sscanf(date_string, "%d-%d-%d", &date.year, &date.month, &date.day);

    // Return the date
    return date;
}

// Function to convert a date to a string
char *date_to_string(Date date) {
    char *date_string = malloc(MAX_DATE_LENGTH + 1);

    // Format the date string
    sprintf(date_string, "%d-%d-%d", date.year, date.month, date.day);

    // Return the date string
    return date_string;
}

// Function to add days to a date
Date add_days(Date date, int days) {
    // Add the days to the date
    date.day += days;

    // Adjust the month and year if necessary
    if (date.day > 31) {
        date.day -= 31;
        date.month++;
    }
    if (date.month > 12) {
        date.month -= 12;
        date.year++;
    }

    // Return the date
    return date;
}

// Function to subtract days from a date
Date subtract_days(Date date, int days) {
    // Subtract the days from the date
    date.day -= days;

    // Adjust the month and year if necessary
    if (date.day < 1) {
        date.day += 31;
        date.month--;
    }
    if (date.month < 1) {
        date.month += 12;
        date.year--;
    }

    // Return the date
    return date;
}

// Function to compare two dates
int compare_dates(Date date1, Date date2) {
    // Compare the years
    if (date1.year != date2.year) {
        return date1.year - date2.year;
    }

    // Compare the months
    if (date1.month != date2.month) {
        return date1.month - date2.month;
    }

    // Compare the days
    return date1.day - date2.day;
}

// Main function
int main() {
    // Get the current date
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);
    Date current_date = {current_tm->tm_year + 1900, current_tm->tm_mon + 1, current_tm->tm_mday};

    // Print the current date
    printf("Current date: %s\n", date_to_string(current_date));

    // Add 10 days to the current date
    Date new_date = add_days(current_date, 10);

    // Print the new date
    printf("New date: %s\n", date_to_string(new_date));

    // Subtract 5 days from the new date
    new_date = subtract_days(new_date, 5);

    // Print the new date
    printf("New date: %s\n", date_to_string(new_date));

    // Compare the current date to the new date
    int comparison = compare_dates(current_date, new_date);
    if (comparison == 0) {
        printf("The current date is the same as the new date.\n");
    } else if (comparison > 0) {
        printf("The current date is earlier than the new date.\n");
    } else {
        printf("The current date is later than the new date.\n");
    }

    return 0;
}