//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

// Function prototypes
void convert_date_format(const char *date_input, char *converted_date);
int is_valid_date(const char *date_input);
void print_usage();

int main(int argc, char *argv[]) {
    char date_input[BUFFER_SIZE];
    char converted_date[BUFFER_SIZE];

    // Check for proper usage
    if (argc < 2) {
        print_usage();
        return 1;
    }

    // Read the date input from command line argument
    strncpy(date_input, argv[1], BUFFER_SIZE);
    date_input[BUFFER_SIZE - 1] = '\0'; // Ensure null-termination

    // Validate date format
    if (!is_valid_date(date_input)) {
        printf("Invalid date format. Please use YYYY-MM-DD.\n");
        return 1;
    }

    // Convert the date format
    convert_date_format(date_input, converted_date);
    
    // Print the converted date
    printf("Converted date: %s\n", converted_date);

    return 0;
}

// Function to convert date from YYYY-MM-DD to DD/MM/YYYY format
void convert_date_format(const char *date_input, char *converted_date) {
    int year, month, day;
    sscanf(date_input, "%d-%d-%d", &year, &month, &day);

    // Format as DD/MM/YYYY
    sprintf(converted_date, "%02d/%02d/%04d", day, month, year);
}

// Function to validate the date format
int is_valid_date(const char *date_input) {
    int year, month, day;
    // Check if the format is correct and parse the values
    if (sscanf(date_input, "%d-%d-%d", &year, &month, &day) != 3) {
        return 0; // Invalid input
    }
    
    // Simple range checks
    if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }

    // Additional checks for months
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return 0;
    }

    // Check for February and leap years
    if (month == 2) {
        if (day > 29) return 0;
        if (day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
            return 0; // Not a leap year
        }
    }

    return 1; // Valid date
}

// Function to print usage instructions
void print_usage() {
    printf("Usage: date_converter <YYYY-MM-DD>\n");
    printf("Convert a date from YYYY-MM-DD format to DD/MM/YYYY format.\n");
}