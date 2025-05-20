//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Function declarations
void normalize_date_string(char *date_string);
int parse_date(const char *date_string, struct tm *date);
void print_date(const struct tm *date);
void display_help();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Invalid number of arguments.\n");
        display_help();
        return EXIT_FAILURE;
    }

    char date_string[256];
    strncpy(date_string, argv[1], sizeof(date_string) - 1);
    date_string[sizeof(date_string) - 1] = '\0'; // Ensure null termination

    normalize_date_string(date_string);

    struct tm date;
    if (parse_date(date_string, &date) == -1) {
        printf("Error: Date format not recognized.\n");
        return EXIT_FAILURE;
    }

    // Print the normalized date
    print_date(&date);
    return EXIT_SUCCESS;
}

void normalize_date_string(char *date_string) {
    // Convert the string to lower case for easier processing
    for (int i = 0; date_string[i]; i++) {
        date_string[i] = tolower(date_string[i]);
    }
    
    // Remove any extra spaces
    char *ptr = date_string;
    char *start = date_string;

    while (*ptr) {
        if (isspace(*ptr) && isspace(*(ptr + 1))) {
            ptr++;
        } else {
            *start++ = *ptr++;
        }
    }
    *start = '\0'; // Null-terminate the cleaned string
}

int parse_date(const char *date_string, struct tm *date) {
    // Reset struct tm
    memset(date, 0, sizeof(struct tm));
    int day, month, year;

    // Try to parse dates in different formats
    char month_str[20];
    if (sscanf(date_string, "%d-%d-%d", &year, &month, &day) == 3) {
        date->tm_year = year - 1900; // Years since 1900
        date->tm_mon = month - 1;    // Months from 0 to 11
        date->tm_mday = day;
    } else if (sscanf(date_string, "%d/%d/%d", &month, &day, &year) == 3) {
        date->tm_year = year - 1900;
        date->tm_mon = month - 1;
        date->tm_mday = day;
    } else if (sscanf(date_string, "%s %d, %d", month_str, &day, &year) == 3) {
        // Convert the month string to lower case
        for (int i = 0; month_str[i]; i++) {
            month_str[i] = tolower(month_str[i]);
        }

        // Map month strings to integers
        if (strcmp(month_str, "january") == 0) date->tm_mon = 0;
        else if (strcmp(month_str, "february") == 0) date->tm_mon = 1;
        else if (strcmp(month_str, "march") == 0) date->tm_mon = 2;
        else if (strcmp(month_str, "april") == 0) date->tm_mon = 3;
        else if (strcmp(month_str, "may") == 0) date->tm_mon = 4;
        else if (strcmp(month_str, "june") == 0) date->tm_mon = 5;
        else if (strcmp(month_str, "july") == 0) date->tm_mon = 6;
        else if (strcmp(month_str, "august") == 0) date->tm_mon = 7;
        else if (strcmp(month_str, "september") == 0) date->tm_mon = 8;
        else if (strcmp(month_str, "october") == 0) date->tm_mon = 9;
        else if (strcmp(month_str, "november") == 0) date->tm_mon = 10;
        else if (strcmp(month_str, "december") == 0) date->tm_mon = 11;
        else return -1; // Invalid month string
        
        date->tm_year = year - 1900;
        date->tm_mday = day;
    } else {
        return -1; // Parsing failed
    }

    // Normalize the date
    mktime(date);
    return 0; // Success
}

void print_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("Normalized Date: %s\n", buffer);
}

void display_help() {
    printf("Usage: date_converter <date_string>\n");
    printf("Supported date formats:\n");
    printf("1. YYYY-MM-DD\n");
    printf("2. MM/DD/YYYY\n");
    printf("3. Month D, YYYY (e.g., January 1, 2023)\n");
    printf("Please ensure that the input date is valid.\n");
}