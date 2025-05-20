//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

// Function to check if a string is a valid date
int is_valid_date(char* date) {
    struct tm tm;
    strptime(date, "%Y-%m-%d", &tm);
    return mktime(&tm)!= -1;
}

// Function to convert a date string to a different format
char* convert_date(char* date, char* format) {
    struct tm tm;
    strptime(date, "%Y-%m-%d", &tm);
    char buffer[MAX_DATE_LENGTH];
    strftime(buffer, MAX_DATE_LENGTH, format, &tm);
    return strdup(buffer);
}

int main() {
    char input[MAX_DATE_LENGTH];
    char output[MAX_DATE_LENGTH];

    // Get input date from user
    printf("Enter a date (YYYY-MM-DD): ");
    fgets(input, MAX_DATE_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a valid date
    if (!is_valid_date(input)) {
        printf("Invalid date format.\n");
        return 1;
    }

    // Get output format from user
    printf("Enter output format (YYYY-MM-DD): ");
    fgets(output, MAX_DATE_LENGTH, stdin);

    // Remove newline character from output
    output[strcspn(output, "\n")] = '\0';

    // Convert input date to output format
    char* result = convert_date(input, output);

    // Print result
    printf("Result: %s\n", result);

    return 0;
}