//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100
#define MAX_DATE_SIZE 20

// Function to convert month name to its corresponding number
int monthToNumber(const char *month) {
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(months[i], month) == 0) {
            return i + 1; // return month number (1-12)
        }
    }
    return -1; // invalid month
}

// Function to parse a date from a natural language format
int parseDate(const char *input, struct tm *date) {
    char month[20], day[3], year[5];
    
    // Example input: "5th of October, 2023" or "October 5, 2023"
    if (sscanf(input, "%2s of %19s, %4s", day, month, year) == 3) {
        // If the format is like "5th of October, 2023"
        date->tm_mday = atoi(day);
        date->tm_mon = monthToNumber(month) - 1; // month is 0-11
        date->tm_year = atoi(year) - 1900; // years since 1900
    } else if (sscanf(input, "%19s %2s, %4s", month, day, year) == 3) {
        // If the format is like "October 5, 2023"
        date->tm_mday = atoi(day);
        date->tm_mon = monthToNumber(month) - 1; // month is 0-11
        date->tm_year = atoi(year) - 1900; // years since 1900
    } else {
        return -1; // parse error
    }
    
    return 0; // success
}

// Function to display the date in a standard format
void displayDate(struct tm *date) {
    char buffer[MAX_DATE_SIZE];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Converted Date: %s\n", buffer);
}

// Main function to run the natural language date converter
int main() {
    char input[MAX_INPUT_SIZE];
    struct tm date = {0}; // zero-initialized tm structure

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date (e.g. '5th of October, 2023' or 'October 5, 2023'): ");
    
    // Read a line of input from the user
    fgets(input, sizeof(input), stdin);
    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Parse the date from the input
    if (parseDate(input, &date) == 0) {
        // Successfully parsed the date
        displayDate(&date);
    } else {
        // Failed to parse the date
        fprintf(stderr, "Error: Invalid date format.\n");
    }

    return 0;
}