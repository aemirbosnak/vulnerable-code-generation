//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dateConverter(char *);
void getCurrentDate();

int main() {
    printf("Enter the date in natural language (dd month yyyy): ");
    char date[20];

    fgets(date, 20, stdin);
    dateConverter(date);

    return 0;
}

// Function to convert natural language date to numeric date
void dateConverter(char *date) {
    const char *months[] = {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
    char *day, *month, *year, *p;

    day = strtok(date, " ");
    month = strtok(NULL, " ");
    year = strtok(NULL, " ");

    // Converting month to its respective numeric value
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            month = i + 1;
            break;
        }
    }

    // Pasting day, month and year into numeric date format
    char numericDate[11];
    sprintf(numericDate, "%s/%d/%s", month, atoi(day), year);

    printf("Numeric date: %s\n", numericDate);
}

// Function to get current date
void getCurrentDate() {
    time_t currentTime;
    struct tm *localTime;

    // Getting current time of system
    currentTime = time(NULL);

    // Converting current time to local time
    localTime = localtime(&currentTime);

    // Printing current date
    printf("Current date: %d/%d/%d", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
}