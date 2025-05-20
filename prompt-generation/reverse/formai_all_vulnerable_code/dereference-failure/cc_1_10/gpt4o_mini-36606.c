//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

void printHelp() {
    printf("\nWelcome to the Natural Language Date Converter! 🎉\n");
    printf("You can input dates in various formats like:\n");
    printf(" - 'today'\n");
    printf(" - 'tomorrow'\n");
    printf(" - 'next Monday'\n");
    printf(" - '3 days from now'\n");
    printf(" - 'February 14, 2021'\n");
    printf("Type 'exit' to quit the program. Let's have some fun with dates! 🚀\n\n");
}

void getCurrentDate(int *day, int *month, int *year) {
    time_t now;
    struct tm *tm_info;

    time(&now);
    tm_info = localtime(&now);

    *day = tm_info->tm_mday;
    *month = tm_info->tm_mon + 1; // Months are 0-11 in tm struct
    *year = tm_info->tm_year + 1900; // Years since 1900
}

void parseNaturalDate(char *input) {
    int day, month, year;
    char monthName[20];
    
    // Get current date first
    getCurrentDate(&day, &month, &year);
    
    if (strcmp(input, "today") == 0) {
        printf("Today's date is: %02d-%02d-%d\n", day, month, year);
    } else if (strcmp(input, "tomorrow") == 0) {
        printf("Tomorrow's date is: %02d-%02d-%d\n", day + 1, month, year);
    } else if (strncmp(input, "next", 4) == 0) {
        sscanf(input, "next %s", monthName);
        printf("Next %s falls on: %02d-%02d-%d\n", monthName, day + 7, month, year);
    } else if (strstr(input, "days from now")) {
        int days;
        sscanf(input, "%d days from now", &days);
        printf("%d days from now is: %02d-%02d-%d\n", days, day + days, month, year);
    } else if (sscanf(input, "%s %d, %d", monthName, &day, &year) == 3) {
        if (strcmp(monthName, "January") == 0) month = 1;
        else if (strcmp(monthName, "February") == 0) month = 2;
        else if (strcmp(monthName, "March") == 0) month = 3;
        else if (strcmp(monthName, "April") == 0) month = 4;
        else if (strcmp(monthName, "May") == 0) month = 5;
        else if (strcmp(monthName, "June") == 0) month = 6;
        else if (strcmp(monthName, "July") == 0) month = 7;
        else if (strcmp(monthName, "August") == 0) month = 8;
        else if (strcmp(monthName, "September") == 0) month = 9;
        else if (strcmp(monthName, "October") == 0) month = 10;
        else if (strcmp(monthName, "November") == 0) month = 11;
        else if (strcmp(monthName, "December") == 0) month = 12;

        printf("The date you entered: %s %d, %d is: %02d-%02d-%d\n", monthName, day, year, day, month, year);
    } else {
        printf("Oh no! I couldn't quite understand that date. Try something like 'today', 'tomorrow', or a specific date! 💔\n");
    }
}

int main() {
    char input[MAX_INPUT];

    printHelp();
    
    while (1) {
        printf("Please enter a date in natural language: ");
        fgets(input, MAX_INPUT, stdin);
        
        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the program. Bye! 🌟\n");
            break;
        }

        parseNaturalDate(input);
    }
    
    return 0;
}