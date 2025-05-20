//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 100

// Struct to hold date information
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Function prototypes
void printWelcome();
char* getUserInput();
Date parseDate(char* input);
void displayDate(Date date);
int isLeapYear(int year);
int getDaysInMonth(int month, int year);
int stringToMonth(char* monthStr);
char* monthToString(int month);

int main() {
    printWelcome();

    char* userInput = getUserInput();
    Date date = parseDate(userInput);
    displayDate(date);

    free(userInput);
    return 0;
}

void printWelcome() {
    printf("Welcome to the C Natural Language Date Converter!\n");
    printf("Please input date in the format:\n");
    printf("1. '1 January 2023'\n");
    printf("2. 'February 15, 2023'\n");
    printf("3. '2023-03-25'\n");
    printf("\nYou can also use phrases like 'today', 'tomorrow', or 'yesterday'.\n\n");
}

char* getUserInput() {
    char* input = (char*)malloc(MAX_INPUT * sizeof(char));
    printf("Enter your date: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    return input;
}

Date parseDate(char* input) {
    Date parsedDate;
    struct tm datetime;
    char monthStr[20];
    char* token = strtok(input, " ,");
    int tokenCount = 0;

    while(token != NULL) {
        if (strcmp(token, "today") == 0) {
            time_t now = time(NULL);
            struct tm* current = localtime(&now);
            parsedDate.day = current->tm_mday;
            parsedDate.month = current->tm_mon + 1;
            parsedDate.year = current->tm_year + 1900;
            return parsedDate;
        } else if (strcmp(token, "tomorrow") == 0) {
            time_t now = time(NULL) + 86400; // 86400 seconds = 1 day
            struct tm* current = localtime(&now);
            parsedDate.day = current->tm_mday;
            parsedDate.month = current->tm_mon + 1;
            parsedDate.year = current->tm_year + 1900;
            return parsedDate;
        } else if (strcmp(token, "yesterday") == 0) {
            time_t now = time(NULL) - 86400; // 1 day before
            struct tm* current = localtime(&now);
            parsedDate.day = current->tm_mday;
            parsedDate.month = current->tm_mon + 1;
            parsedDate.year = current->tm_year + 1900;
            return parsedDate;
        }
        // Check for numeric date "1 January 2023"
        if (tokenCount == 0) {
            parsedDate.day = atoi(token);
        } else if (tokenCount == 1) {
            strcpy(monthStr, token);
        } else if (tokenCount == 2) {
            parsedDate.year = atoi(token);
            parsedDate.month = stringToMonth(monthStr);
        }
        token = strtok(NULL, " ,");
        tokenCount++;
    }

    // Check for date format "February 15, 2023"
    if (tokenCount == 3) {
        parsedDate.day = atoi(strtok(NULL, ","));
        parsedDate.month = stringToMonth(token);
        parsedDate.year = atoi(strtok(NULL, " "));
    }
    
    // Check for format "2023-03-25"
    if (tokenCount == 1 && strstr(input, "-")) {
        sscanf(input, "%d-%d-%d", &parsedDate.year, &parsedDate.month, &parsedDate.day);
    }

    return parsedDate;
}

void displayDate(Date date) {
    printf("Parsed Date: %02d/%02d/%d\n", date.day, date.month, date.year);
    if (isLeapYear(date.year)) {
        printf("The year %d is a leap year.\n", date.year);
    } else {
        printf("The year %d is not a leap year.\n", date.year);
    }
    printf("Days in the month %s of %d: %d\n", monthToString(date.month), date.year, getDaysInMonth(date.month, date.year));
}

int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) return 1;
            return 0;
        }
        return 1;
    }
    return 0;
}

int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 0; // Invalid month
    }
}

int stringToMonth(char* monthStr) {
    char* months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthStr, months[i]) == 0) {
            return i + 1;
        }
    }
    return 0; // Invalid month
}

char* monthToString(int month) {
    if (month < 1 || month > 12) return "Invalid month";
    char* months[] = {"January", "February", "March", "April", "May", "June", 
                      "July", "August", "September", "October", "November", "December"};
    return months[month - 1];
}