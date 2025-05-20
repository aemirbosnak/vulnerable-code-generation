//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 10
#define MAX_DATE_LENGTH 20
#define MAX_MONTHS 12

// Struct for date
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function prototypes
char* extract_month(char* date_string);
int extract_day(char* date_string);
int extract_year(char* date_string);
Date* parse_date(char* date_string);
void print_date(Date* date);

// Main function
int main() {
    char input[MAX_DATE_LENGTH];
    Date* date;

    // Prompt user for input
    printf("Enter a date (DD/MM/YYYY): ");
    fgets(input, MAX_DATE_LENGTH, stdin);

    // Parse date
    date = parse_date(input);

    // Print parsed date
    printf("Parsed date: ");
    print_date(date);

    return 0;
}

// Extract month from date string
char* extract_month(char* date_string) {
    char* month_string = strtok(date_string, "/");
    return month_string;
}

// Extract day from date string
int extract_day(char* date_string) {
    char* day_string = strtok(NULL, "/");
    int day = atoi(day_string);
    return day;
}

// Extract year from date string
int extract_year(char* date_string) {
    char* year_string = strtok(NULL, "/");
    int year = atoi(year_string);
    return year;
}

// Parse date from input string
Date* parse_date(char* date_string) {
    Date* date = malloc(sizeof(Date));

    // Extract month
    char* month_string = extract_month(date_string);
    strcpy(date->month, month_string);

    // Extract day
    int day = extract_day(date_string);
    date->day = day;

    // Extract year
    int year = extract_year(date_string);
    date->year = year;

    return date;
}

// Print parsed date
void print_date(Date* date) {
    printf("%s %d, %d\n", date->month, date->day, date->year);
}