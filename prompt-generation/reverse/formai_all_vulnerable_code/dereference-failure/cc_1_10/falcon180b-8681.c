//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// Function to check if a string is a valid date
bool is_valid_date(char* date) {
    struct tm tm;
    strptime(date, "%Y-%m-%d", &tm);
    return (tm.tm_year >= 1000 && tm.tm_year <= 9999 && tm.tm_mon >= 1 && tm.tm_mon <= 12 && tm.tm_mday >= 1 && tm.tm_mday <= 31);
}

// Function to convert a date string to a struct tm
struct tm date_to_tm(char* date) {
    struct tm tm;
    strptime(date, "%Y-%m-%d", &tm);
    return tm;
}

// Function to print a date in a given format
void print_date(struct tm date, char* format) {
    char buffer[100];
    strftime(buffer, sizeof(buffer), format, &date);
    printf("%s\n", buffer);
}

// Function to get user input for a date
char* get_date_input(char* prompt) {
    char input[100];
    printf("%s: ", prompt);
    fgets(input, sizeof(input), stdin);
    return strdup(input);
}

// Function to get user input for a date format
char* get_format_input(char* prompt) {
    char input[100];
    printf("%s: ", prompt);
    fgets(input, sizeof(input), stdin);
    return strdup(input);
}

// Main function
int main() {
    char* date_string;
    char* format_string;

    // Get date string from user
    date_string = get_date_input("Enter a date (YYYY-MM-DD): ");

    // Check if date string is valid
    if (!is_valid_date(date_string)) {
        printf("Invalid date\n");
        return 1;
    }

    // Get format string from user
    format_string = get_format_input("Enter a date format: ");

    // Convert date string to struct tm
    struct tm date_tm = date_to_tm(date_string);

    // Print date in given format
    print_date(date_tm, format_string);

    return 0;
}