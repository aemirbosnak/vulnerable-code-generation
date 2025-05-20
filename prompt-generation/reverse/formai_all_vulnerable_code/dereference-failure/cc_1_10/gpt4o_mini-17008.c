//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MAX_FORMAT_SIZE 50

// Function signatures
void printWelcomeMessage();
char* getCurrentDate();
void convertToDate(char *input);
void extractDate(char *input, int *day, int *month, int *year);
void formatOutput(int day, int month, int year);

int main() {
    printWelcomeMessage();
    
    char input[BUFFER_SIZE];
    while (1) {
        printf("Please enter a natural language date (or type 'exit' to quit): ");
        fgets(input, BUFFER_SIZE, stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        convertToDate(input);
    }

    return 0;
}

void printWelcomeMessage() {
    printf("============================================\n");
    printf("            C Natural Language Date         \n");
    printf("               Converter Program             \n");
    printf("============================================\n");
}

char* getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    static char dateStr[11];
    sprintf(dateStr, "%02d-%02d-%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    return dateStr;
}

void convertToDate(char *input) {
    int day, month, year;
    char *formattedInput = strdup(input);
    
    // Convert to lowercase for uniformity
    for (char *p = formattedInput; *p; ++p) {
        *p = tolower(*p);
    }

    // Debugging output to show the formatted input
    printf("Input received: %s\n", formattedInput);

    // Simple parsing algorithm
    if (strstr(formattedInput, "today")) {
        sscanf(getCurrentDate(), "%d-%d-%d", &day, &month, &year);
        formatOutput(day, month, year);
    } else if (strstr(formattedInput, "yesterday")) {
        sscanf(getCurrentDate(), "%d-%d-%d", &day, &month, &year);
        if (--day < 1) { // change to previous month
            month--;
            if (month < 1) {
                month = 12;
                year--;
                day = 31; // Simplified, change accordingly for actual month days
            } else {
                day = 30; // Simplified
            }
        }
        formatOutput(day, month, year);
    } else if (strstr(formattedInput, "tomorrow")) {
        sscanf(getCurrentDate(), "%d-%d-%d", &day, &month, &year);
        if (++day > 31) { // Simplified, change accordingly for actual month days
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        formatOutput(day, month, year);
    } else {
        extractDate(formattedInput, &day, &month, &year);
        formatOutput(day, month, year);
    }
    
    free(formattedInput);
}

void extractDate(char *input, int *day, int *month, int *year) {
    char *token = strtok(input, " ");
    *day = *month = *year = 0;

    // Simple token-based extraction, expecting format like "15 May 2023"
    int count = 0;
    while (token != NULL && count < 3) {
        if (count == 0) {
            *day = atoi(token);
        } else if (count == 1) {
            if (strcmp(token, "january") == 0) *month = 1;
            else if (strcmp(token, "february") == 0) *month = 2;
            else if (strcmp(token, "march") == 0) *month = 3;
            else if (strcmp(token, "april") == 0) *month = 4;
            else if (strcmp(token, "may") == 0) *month = 5;
            else if (strcmp(token, "june") == 0) *month = 6;
            else if (strcmp(token, "july") == 0) *month = 7;
            else if (strcmp(token, "august") == 0) *month = 8;
            else if (strcmp(token, "september") == 0) *month = 9;
            else if (strcmp(token, "october") == 0) *month = 10;
            else if (strcmp(token, "november") == 0) *month = 11;
            else if (strcmp(token, "december") == 0) *month = 12;
        } else if (count == 2) {
            *year = atoi(token);
        }
        token = strtok(NULL, " ");
        count++;
    }
}

void formatOutput(int day, int month, int year) {
    printf("Converted Date: %02d-%02d-%04d\n", day, month, year);
}