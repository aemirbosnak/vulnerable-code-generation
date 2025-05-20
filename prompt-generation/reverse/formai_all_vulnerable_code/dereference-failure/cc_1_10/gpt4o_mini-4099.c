//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256

// Function prototypes
void get_current_date(char *date_str);
int parse_date(const char *date_str, struct tm *date);
void print_date(const struct tm *date);

int main() {
    char input[BUFFER_SIZE];
    struct tm date;
    
    // Get the current date
    char current_date[BUFFER_SIZE];
    get_current_date(current_date);
    printf("Current Date: %s\n", current_date);

    // User input
    printf("Enter a date in the format 'YYYY-MM-DD': ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse the date
        if (parse_date(input, &date) != 0) {
            printf("Invalid date format. Please try again.\n");
            return EXIT_FAILURE;
        }

        // Print the parsed date
        print_date(&date);
    } else {
        printf("Error reading input.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// Function to get the current date and format it as "YYYY-MM-DD"
void get_current_date(char *date_str) {
    time_t t = time(NULL);
    struct tm* current_time = localtime(&t);
    strftime(date_str, BUFFER_SIZE, "%Y-%m-%d", current_time);
}

// Function to parse the date from string to struct tm
int parse_date(const char *date_str, struct tm *date) {
    char year[5], month[3], day[3];
    
    // Extract year, month and day from string
    if (sscanf(date_str, "%4s-%2s-%2s", year, month, day) != 3) {
        return -1; // Failed to parse
    }

    // Convert strings to integers
    date->tm_year = atoi(year) - 1900; // Year since 1900
    date->tm_mon = atoi(month) - 1;     // Month is zero-based
    date->tm_mday = atoi(day);           // Day of the month
    date->tm_hour = 0;
    date->tm_min = 0;
    date->tm_sec = 0;
    date->tm_isdst = -1; // Not considering daylight saving time

    // Validate date
    if (mktime(date) == -1) {
        return -1; // Invalid date
    }

    return 0; // Success
}

// Function to print the date in a more human-readable format
void print_date(const struct tm *date) {
    char date_str[BUFFER_SIZE];
    strftime(date_str, BUFFER_SIZE, "Parsed Date: %A, %B %d, %Y", date);
    printf("%s\n", date_str);
}