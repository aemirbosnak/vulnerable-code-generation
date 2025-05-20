//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100
#define DATE_FORMAT "%Y-%m-%d"

void printUsage() {
    printf("Usage: Enter a date in natural language (e.g., 'today', 'next Friday', 'January 1 2022'):\n");
}

void parseNaturalDate(char *input) {
    // Get current date
    time_t t = time(NULL);
    struct tm *currentDate = localtime(&t);
    char outputDate[11]; // YYYY-MM-DD format

    // Check for 'today'
    if (strcmp(input, "today") == 0) {
        strftime(outputDate, sizeof(outputDate), DATE_FORMAT, currentDate);
        printf("Converted date: %s\n", outputDate);
        return;
    }

    // Check for 'tomorrow'
    if (strcmp(input, "tomorrow") == 0) {
        currentDate->tm_mday++;
        mktime(currentDate); // Normalize the tm structure
        strftime(outputDate, sizeof(outputDate), DATE_FORMAT, currentDate);
        printf("Converted date: %s\n", outputDate);
        return;
    }

    // Check for 'yesterday'
    if (strcmp(input, "yesterday") == 0) {
        currentDate->tm_mday--;
        mktime(currentDate); // Normalize the tm structure
        strftime(outputDate, sizeof(outputDate), DATE_FORMAT, currentDate);
        printf("Converted date: %s\n", outputDate);
        return;
    }

    // Process for 'next' or 'last'
    char *prefix = strtok(input, " ");
    char *dayOfWeek = strtok(NULL, " ");
    char *specificDate = strtok(NULL, " ");

    if (strcmp(prefix, "next") == 0) {
        if (strcmp(dayOfWeek, "Monday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 1) % 7;
        } else if (strcmp(dayOfWeek, "Tuesday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 2) % 7;
        } else if (strcmp(dayOfWeek, "Wednesday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 3) % 7;
        } else if (strcmp(dayOfWeek, "Thursday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 4) % 7;
        } else if (strcmp(dayOfWeek, "Friday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 5) % 7;
        } else if (strcmp(dayOfWeek, "Saturday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 6) % 7;
        } else if (strcmp(dayOfWeek, "Sunday") == 0) {
            currentDate->tm_mday += (7 - currentDate->tm_wday + 0) % 7;
        }
        mktime(currentDate); // Normalize the tm structure
    } else if (strcmp(prefix, "last") == 0) {
        if (strcmp(dayOfWeek, "Monday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 1) % 7; 
        } else if (strcmp(dayOfWeek, "Tuesday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 2) % 7; 
        } else if (strcmp(dayOfWeek, "Wednesday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 3) % 7; 
        } else if (strcmp(dayOfWeek, "Thursday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 4) % 7; 
        } else if (strcmp(dayOfWeek, "Friday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 5) % 7; 
        } else if (strcmp(dayOfWeek, "Saturday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 6) % 7; 
        } else if (strcmp(dayOfWeek, "Sunday") == 0) {
            currentDate->tm_mday -= (7 + currentDate->tm_wday - 0) % 7; 
        }
        mktime(currentDate); // Normalize the tm structure
    }

    // Check for specific dates
    if (specificDate) {
        // Attempt to parse the specific date
        struct tm parsedDate = {0};
        strptime(input, "%B %d %Y", &parsedDate);
        if (parsedDate.tm_year != 0 || parsedDate.tm_mon != 0) {
            // If valid date found
            strftime(outputDate, sizeof(outputDate), DATE_FORMAT, &parsedDate);
            printf("Converted date: %s\n", outputDate);
            return;
        } else {
            printf("Could not parse the specific date.\n");
            return;
        }
    }

    // If none of the conditions matched
    printf("Unknown date format. Please try again.\n");
}

int main() {
    char input[MAX_INPUT];
    printUsage();

    printf("Enter date: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0;  // Remove newline character

    parseNaturalDate(input);
    
    return 0;
}