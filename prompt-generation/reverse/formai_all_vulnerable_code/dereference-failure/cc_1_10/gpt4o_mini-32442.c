//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100

// Function to convert a month from string to integer
int get_month(char *month) {
    if (strcasecmp(month, "january") == 0) return 1;
    else if (strcasecmp(month, "february") == 0) return 2;
    else if (strcasecmp(month, "march") == 0) return 3;
    else if (strcasecmp(month, "april") == 0) return 4;
    else if (strcasecmp(month, "may") == 0) return 5;
    else if (strcasecmp(month, "june") == 0) return 6;
    else if (strcasecmp(month, "july") == 0) return 7;
    else if (strcasecmp(month, "august") == 0) return 8;
    else if (strcasecmp(month, "september") == 0) return 9;
    else if (strcasecmp(month, "october") == 0) return 10;
    else if (strcasecmp(month, "november") == 0) return 11;
    else if (strcasecmp(month, "december") == 0) return 12;
    return -1; // invalid month
}

// Function to convert a natural language date to a standard format
void convert_date(const char *input) {
    char day[3];
    char month[10];
    char year[5];
    int d, m, y;

    // Local copy of input to avoid modifying original string
    char *input_copy = strdup(input);
    char *token = strtok(input_copy, " ");

    // Parse tokens for day, month, and year
    if (token) {
        strncpy(day, token, sizeof(day));
        token = strtok(NULL, " ");
    }

    if (token) {
        strncpy(month, token, sizeof(month));
        token = strtok(NULL, " ");
    }

    if (token) {
        strncpy(year, token, sizeof(year));
    }

    // Convert to integers
    d = atoi(day);
    m = get_month(month);
    y = atoi(year);

    // Validate and display the converted date
    if (d > 0 && m > 0 && y > 0) {
        printf("Converted Date: %04d-%02d-%02d\n", y, m, d);
    } else {
        printf("Invalid date format. Please use 'day month year' (e.g., '15 March 2023').\n");
    }

    free(input_copy);
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Natural Language Date Converter\n");
    printf("Please enter a date (format: 'day month year', e.g. '15 March 2023'):\n");
    
    while (1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input. Exiting...\n");
            return EXIT_FAILURE;
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check for exit condition
        if (strcasecmp(input, "exit") == 0) {
            printf("Exiting the Natural Language Date Converter. Goodbye!\n");
            break;
        }

        convert_date(input);
    }

    return EXIT_SUCCESS;
}