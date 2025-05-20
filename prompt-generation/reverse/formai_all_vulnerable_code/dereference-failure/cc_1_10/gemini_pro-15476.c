//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to convert a date from the format "dd/mm/yyyy" to a time_t value
time_t date_to_time_t(char *date) {
    struct tm tm;
    char *ptr;

    // Parse the date string into the tm structure
    tm.tm_mday = strtol(date, &ptr, 10);
    tm.tm_mon = strtol(ptr + 1, &ptr, 10) - 1;
    tm.tm_year = strtol(ptr + 1, &ptr, 10) - 1900;

    // Set the remaining fields of the tm structure
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1;

    // Convert the tm structure to a time_t value
    return mktime(&tm);
}

// Function to convert a time_t value to a date in the format "dd/mm/yyyy"
char *time_t_to_date(time_t time_t_value) {
    struct tm *tm;
    char *date_string;

    // Convert the time_t value to a tm structure
    tm = localtime(&time_t_value);

    // Allocate memory for the date string
    date_string = malloc(11);

    // Format the date string
    sprintf(date_string, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    // Return the date string
    return date_string;
}

int main() {
    // Get the current date and time
    time_t current_time = time(NULL);

    // Convert the current date and time to a date in the format "dd/mm/yyyy"
    char *current_date = time_t_to_date(current_time);

    // Print the current date
    printf("Current date: %s\n", current_date);

    // Convert the current date back to a time_t value
    time_t converted_time = date_to_time_t(current_date);

    // Print the converted time
    printf("Converted time: %ld\n", converted_time);

    // Free the memory allocated for the date string
    free(current_date);

    return 0;
}