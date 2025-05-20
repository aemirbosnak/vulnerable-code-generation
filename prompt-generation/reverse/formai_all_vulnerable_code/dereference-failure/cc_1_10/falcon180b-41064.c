//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DATE_LENGTH 100
#define DAY_IN_SECONDS 86400

// Function to convert date string to time_t
time_t string_to_time(char *date_str) {
    struct tm tm;
    strptime(date_str, "%Y-%m-%d", &tm);
    return mktime(&tm);
}

// Function to convert time_t to date string
void time_to_string(time_t time, char *date_str) {
    struct tm tm = *localtime(&time);
    strftime(date_str, MAX_DATE_LENGTH, "%Y-%m-%d", &tm);
}

// Function to calculate number of days between two dates
int days_between_dates(time_t date1, time_t date2) {
    return (int)difftime(date2, date1) / DAY_IN_SECONDS;
}

// Function to print usage instructions
void print_usage() {
    printf("Usage:./date_converter [date1] [date2]\n");
    printf("      ./date_converter -h\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-h") == 0)) {
        print_usage();
        return 0;
    }

    time_t date1, date2;
    char date_str1[MAX_DATE_LENGTH], date_str2[MAX_DATE_LENGTH];

    // Convert command line arguments to time_t
    if (argc == 3) {
        date1 = string_to_time(argv[1]);
        date2 = string_to_time(argv[2]);
    } else {
        printf("Error: Invalid number of arguments\n");
        print_usage();
        return 1;
    }

    // Print original dates
    printf("Original dates:\n");
    time_to_string(date1, date_str1);
    printf("Date 1: %s\n", date_str1);
    time_to_string(date2, date_str2);
    printf("Date 2: %s\n", date_str2);

    // Calculate number of days between dates
    int days_diff = days_between_dates(date1, date2);

    // Print number of days between dates
    printf("Number of days between dates: %d\n", days_diff);

    return 0;
}