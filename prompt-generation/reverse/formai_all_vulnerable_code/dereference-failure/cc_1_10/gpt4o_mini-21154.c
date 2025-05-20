//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define DATE_FORMAT "%Y-%m-%d"

// Function to get the current date in the desired format
void get_current_date(char *buffer) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    strftime(buffer, 11, DATE_FORMAT, &tm);
}

// Function to convert month string to number
int month_to_number(const char *month) {
    if (strcmp(month, "January") == 0) return 1;
    else if (strcmp(month, "February") == 0) return 2;
    else if (strcmp(month, "March") == 0) return 3;
    else if (strcmp(month, "April") == 0) return 4;
    else if (strcmp(month, "May") == 0) return 5;
    else if (strcmp(month, "June") == 0) return 6;
    else if (strcmp(month, "July") == 0) return 7;
    else if (strcmp(month, "August") == 0) return 8;
    else if (strcmp(month, "September") == 0) return 9;
    else if (strcmp(month, "October") == 0) return 10;
    else if (strcmp(month, "November") == 0) return 11;
    else if (strcmp(month, "December") == 0) return 12;
    return -1; // Invalid month
}

// Function to parse user input date
void parse_date(const char *input, char *output, const char *current_date) {
    char month[15];
    int day = 0;
    int year = 0;

    // Check current date
    sscanf(current_date, DATE_FORMAT, &year);

    // Convert phrases
    if (sscanf(input, "%d %s", &day, month) == 2) {
        int month_num = month_to_number(month);
        if (month_num != -1) { // Valid month
            sprintf(output, "%04d-%02d-%02d", year, month_num, day);
            return;
        }
    }
    
    if (strcmp(input, "today") == 0) {
        strcpy(output, current_date);
        return;
    }
    
    // Time based phrases
    char day_suffix[10];
    if (sscanf(input, "%s %s", day_suffix, month) == 2) {
        day = atoi(day_suffix);
        int month_num = month_to_number(month);
        if (month_num != -1) {
            sprintf(output, "%04d-%02d-%02d", year, month_num, day);
            return;
        }
    }
    
    // Default case
    strcpy(output, "Invalid date format");
}

// Main function
int main() {
    char input[MAX_INPUT];
    char output[11];
    char current_date[11];

    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Type 'today' for the current date.\n");
    printf("Or enter a date like '20 March' or '15 April' to convert it.\n");

    get_current_date(current_date);
    
    while (1) {
        printf("Enter date: ");
        fgets(input, MAX_INPUT, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character
        
        if (strcmp(input, "exit") == 0) {
            printf("Exiting the Date Converter. Goodbye!\n");
            break;
        }
        
        parse_date(input, output, current_date);
        printf("Converted Date: %s\n", output);
    }

    return 0;
}