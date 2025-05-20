//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_SIZE 256
#define MAX_DATE_PARTS 3

// Structure to hold date information
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function declarations
void get_input(char *input);
void parse_date(const char *input, Date *date);
void convert_to_date_format(const Date *date, char *formatted_date);
void get_current_date(Date *current_date);
void print_date(const char *formatted_date);

int main() {
    char input[MAX_INPUT_SIZE];
    Date date;
    char formatted_date[50];

    // Get natural language date input from user
    get_input(input);

    // Parse the date into a Date structure
    parse_date(input, &date);

    // Convert the parsed date to a formatted string
    convert_to_date_format(&date, formatted_date);

    // Print the formatted date
    print_date(formatted_date);

    return 0;
}

// Function to get input from the user
void get_input(char *input) {
    printf("Enter a date (e.g., 'March 15, 2022' or 'today'): ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
}

// Function to get the current date
void get_current_date(Date *current_date) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_date->day = tm.tm_mday;
    current_date->month = tm.tm_mon + 1; // tm_mon is 0-11
    current_date->year = tm.tm_year + 1900; // tm_year is years since 1900
}

// Function to parse natural language date into Date structure
void parse_date(const char *input, Date *date) {
    Date current_date;
    get_current_date(&current_date);

    // Check if input is "today"
    if (strcasecmp(input, "today") == 0) {
        date->day = current_date.day;
        date->month = current_date.month;
        date->year = current_date.year;
        return;
    }

    // Try to parse generic date formats
    sscanf(input, "%d %*[^0-9]%d, %d", &date->month, &date->day, &date->year);
    
    // If parsing failed, use today's date
    if (date->year < 1900 || date->month < 1 || date->month > 12) {
        date->day = current_date.day;
        date->month = current_date.month;
        date->year = current_date.year;
    }
}

// Function to convert Date structure into formatted string
void convert_to_date_format(const Date *date, char *formatted_date) {
    snprintf(formatted_date, 50, "%02d-%02d-%04d", date->day, date->month, date->year);
}

// Function to print the formatted date
void print_date(const char *formatted_date) {
    printf("Formatted Date: %s\n", formatted_date);
}