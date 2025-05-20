//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Function prototypes
void getCurrentTime(struct tm *tm);
char* convertDate(char *inputDate);
void addDaysToDate(struct tm *tm, int days);
int parseNaturalLanguage(char *input, struct tm *tm);

int main() {
    char input[100];
    struct tm currentTime;
    
    // Let's get the ball rolling!
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in natural language (e.g., 'next Friday', '5 days from now'):\n");
    
    // Get user input
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    // Get the current time
    getCurrentTime(&currentTime);

    // Convert the date based on natural language input
    char* result = convertDate(input);
    
    // If conversion is valid, print the result
    if (result) {
        printf("Converted Date: %s\n", result);
        free(result);
    } else {
        printf("Failed to convert the date. Please try again with a different format.\n");
    }

    return 0;
}

// Get current time and store it in a tm structure
void getCurrentTime(struct tm *tm) {
    time_t t = time(NULL);
    *tm = *localtime(&t);
}

// Convert the date based on input
char* convertDate(char *inputDate) {
    struct tm resultTime;
    memset(&resultTime, 0, sizeof(resultTime));

    int parsed = parseNaturalLanguage(inputDate, &resultTime);
    if (parsed) {
        // Allocate memory for the output string
        char *output = (char *)malloc(30 * sizeof(char));
        strftime(output, 30, "%Y-%m-%d", &resultTime);
        return output;
    }
    return NULL; // Indicate failure
}

// Function to add days to a given tm structure
void addDaysToDate(struct tm *tm, int days) {
    time_t rawtime = mktime(tm);
    rawtime += days * 24 * 60 * 60; // days to seconds
    *tm = *localtime(&rawtime);
}

// Parsing natural language input
int parseNaturalLanguage(char *input, struct tm *tm) {
    char *token = strtok(input, " ");
    int days = 0;
    int found = 0;

    while (token) {
        if (strcasecmp(token, "today") == 0) {
            // Today, nothing modifies the date
            found = 1;
        } else if (strcasecmp(token, "tomorrow") == 0) {
            addDaysToDate(tm, 1);
            found = 1;
        } else if (strcasecmp(token, "next") == 0) {
            token = strtok(NULL, " "); // Get the next word
            if (token) {
                if (strcasecmp(token, "Monday") == 0) {
                    // Assume next Monday is in the range of days
                    found = 1; // Specify logic if needed
                    // Add logic to calculate next Monday's date
                } else if (strcasecmp(token, "Friday") == 0) {
                    // Assume next Friday
                    found = 1; // Specify logic if needed
                    // Add logic to calculate next Friday's date
                }
            }
        } else if (isdigit(token[0])) {
            // Simply digits mean days
            days += atoi(token);
            found = 1;
        }
        token = strtok(NULL, " "); // Go to the next word
    }

    // If we found any days, add them to the current date
    if (found && days > 0) {
        addDaysToDate(tm, days);
        return 1; // Success
    } else if (found) {
        return 1; // Just found today (or similar)
    }
    return 0; // Failed to parse
}