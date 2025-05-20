//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function declarations
void to_lowercase(char *str);
void parse_date(const char *input, struct tm *date);
void print_date(const struct tm *date);
int is_valid_date(int year, int month, int day);
int days_in_month(int month, int year);

int main() {
    char input[MAX_INPUT_LENGTH];
    struct tm date = {0};
    date.tm_isdst = -1; // Daylight saving time flag

    printf("Natural Language Date Converter\n");
    printf("Please input a date (e.g., 'January 5, 2023', '5th Jan 23', 'Next Friday'):\n");

    while (1) {
        printf("Enter date (or type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Exit condition
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Parse the date
        parse_date(input, &date);

        // Print the resulting date
        print_date(&date);
    }

    return 0;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void parse_date(const char *input, struct tm *date) {
    char month_str[10];
    int day, year;
    time_t t = time(NULL);
    struct tm *now = localtime(&t);
    date->tm_year = now->tm_year;
    date->tm_mon = now->tm_mon;
    date->tm_mday = now->tm_mday;

    // Convert input to lowercase for easier parsing
    char lower_input[MAX_INPUT_LENGTH];
    strcpy(lower_input, input);
    to_lowercase(lower_input);

    // Check for relative dates
    if (strstr(lower_input, "next") != NULL) {
        if (strstr(lower_input, "friday") != NULL) {
            date->tm_mday += (5 - now->tm_wday + 7) % 7 + 7; // Next Friday
        } else if (strstr(lower_input, "monday") != NULL) {
            date->tm_mday += (1 - now->tm_wday + 7) % 7 + 7;  // Next Monday
        }
    }
    // Parse specific natural language formats
    else if (sscanf(lower_input, "%s %d, %d", month_str, &day, &year) == 3) {
        // Parse full date like 'January 5, 2023'
        date->tm_year = year - 1900; // Adjusting year
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
    }
    else if (sscanf(lower_input, "%d %s %d", &day, month_str, &year) == 3) {
        // Parse date like '5th January, 2023'
        date->tm_year = year - 1900;
        date->tm_mday = day; // Day
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
    }

    // Validate date
    if (!is_valid_date(date->tm_year + 1900, date->tm_mon + 1, date->tm_mday)) {
        printf("Invalid date: %s\n", input);
        date->tm_year = now->tm_year; // Reset to today if invalid
        date->tm_mon = now->tm_mon;
        date->tm_mday = now->tm_mday;
    }
}

void print_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "Parsed date: %Y-%m-%d", date);
    printf("%s\n", buffer);
}

int is_valid_date(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1) return 0;
    if (day > days_in_month(month, year)) return 0;
    return 1;
}

int days_in_month(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: // February
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // leap year
                return 29;
            else
                return 28;
        default: return 0; // Invalid month
    }
}