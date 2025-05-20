//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORD_LENGTH 20
#define MAX_DATE_LENGTH 20

typedef struct {
    char month[MAX_WORD_LENGTH];
    int day;
    int year;
} date;

void parse_date(char* input, date* result);
int is_valid_date(date* date);

int main() {
    char input[MAX_DATE_LENGTH];
    date parsed_date;
    int is_valid;

    printf("Enter a date in the format 'Month Day, Year':\n");
    fgets(input, MAX_DATE_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Parse input into a date struct
    parse_date(input, &parsed_date);

    // Check if the date is valid
    is_valid = is_valid_date(&parsed_date);

    if (is_valid) {
        printf("Valid date: %s %d, %d\n", parsed_date.month, parsed_date.day, parsed_date.year);
    } else {
        printf("Invalid date\n");
    }

    return 0;
}

void parse_date(char* input, date* result) {
    char* month_str;
    char* day_str;
    char* year_str;

    // Find the month
    month_str = strtok(input, " ");
    strcpy(result->month, month_str);

    // Find the day
    day_str = strtok(NULL, " ");
    result->day = atoi(day_str);

    // Find the year
    year_str = strtok(NULL, " ");
    result->year = atoi(year_str);
}

int is_valid_date(date* date) {
    struct tm parsed_time;
    time_t result;

    // Set the day and month
    parsed_time.tm_year = date->year - 1900;
    parsed_time.tm_mon = 0;
    parsed_time.tm_mday = date->day;

    // Check if the day and month are valid
    if (parsed_time.tm_mday < 1 || parsed_time.tm_mday > 31) {
        return 0;
    }

    switch (parsed_time.tm_mon) {
        case 0:
        case 2:
        case 4:
        case 6:
        case 7:
        case 9:
        case 11:
            parsed_time.tm_mon++;
            break;
        default:
            parsed_time.tm_mon -= 1;
            break;
    }

    // Check if the month is valid
    if (parsed_time.tm_mon < 1 || parsed_time.tm_mon > 12) {
        return 0;
    }

    // Set the year
    parsed_time.tm_year += 1900;

    // Convert the tm struct to a time_t
    result = mktime(&parsed_time);

    // Check if the time_t is valid
    if (result == -1) {
        return 0;
    }

    return 1;
}