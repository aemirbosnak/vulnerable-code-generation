//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// Function prototypes
int getMonthDays(int month, int year);
int isLeapYear(int year);
void convertDate(char input[], char output[]);

int main() {
    char input[MAX_INPUT_LENGTH], output[MAX_INPUT_LENGTH];

    printf("Enter a date in the format of dd/mm/yyyy: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    convertDate(input, output);
    printf("The date in natural language format is: %s", output);

    return 0;
}

/**
 * Returns the number of days in the given month and year.
 * Assumes year is already validated to be a valid 4-digit integer.
 */
int getMonthDays(int month, int year) {
    int days;

    switch (month) {
        case 2:
            days = isLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }

    return days;
}

/**
 * Returns 1 if the given year is a leap year, 0 otherwise.
 * Assumes year is already validated to be a valid 4-digit integer.
 */
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/**
 * Converts a date string from "dd/mm/yyyy" format to natural language format.
 */
void convertDate(char input[], char output[]) {
    char *tokens[3];
    char *ptr = strtok(input, "/");
    int i = 0;
    while(ptr != NULL) {
        tokens[i++] = ptr;
        ptr = strtok(NULL, "/");
    }

    int day = atoi(tokens[0]);
    int month = atoi(tokens[1]);
    int year = atoi(tokens[2]);

    // Validate input
    if (day < 1 || day > getMonthDays(month, year)) {
        sprintf(output, "Invalid input date: %s", input);
        return;
    }

    // Convert month to natural language
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    char monthStr[10];
    strcpy(monthStr, months[month - 1]);

    // Convert day to natural language
    char *days[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh",
                    "eighth", "ninth", "tenth", "eleventh", "twelfth", "thirteenth", "fourteenth",
                    "fifteenth", "sixteenth", "seventeenth", "eighteenth", "nineteenth",
                    "twentieth", "twenty-first", "twenty-second", "twenty-third",
                    "twenty-fourth", "twenty-fifth", "twenty-sixth", "twenty-seventh",
                    "twenty-eighth", "twenty-ninth", "thirtieth", "thirty-first"};
    char dayStr[15];
    strcpy(dayStr, days[day - 1]);

    // Convert year to natural language
    char yearStr[5];
    sprintf(yearStr, "%d", year);

    // Create output string
    sprintf(output, "%s %s %s", dayStr, monthStr, yearStr);
}