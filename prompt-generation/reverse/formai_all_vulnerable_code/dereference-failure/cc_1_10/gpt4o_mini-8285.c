//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100

void display_welcome_message() {
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter your date in plain words, and behold the magic!\n");
    printf("Examples:\n");
    printf(" - Next Tuesday\n");
    printf(" - The first of December\n");
    printf(" - Last year on my birthday\n");
    printf(" - Tomorrow at noon\n");
    printf("Let the journey begin!\n\n");
}

void clear_buffer() {
    while (getchar() != '\n');
}

void extract_date(const char *input, struct tm *date) {
    memset(date, 0, sizeof(struct tm));
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    
    char period[MAX_LENGTH];
    if (sscanf(input, "Next %s", period) == 1) {
        // We assume adding a week for "Next"
        current_time->tm_mday += 7;
        // Find the day of the week and increment to the next desired day
        // (Simple approach for the idea of next day)
    } else if (sscanf(input, "Last %s", period) == 1) {
        // Subtracting a week for "Last"
        current_time->tm_mday -= 7;
    } else if (strstr(input, "tomorrow") != NULL) {
        current_time->tm_mday += 1;
    } else if (strstr(input, "today") != NULL) {
        // Do nothing, return current date
    } else if (strstr(input, "noon") != NULL) {
        current_time->tm_hour = 12; // Set time to noon
    }
    
    // Check for monthly or day specifics
    if (sscanf(input, "the %d of %s", &date->tm_mday, period) == 2) {
        // Month mapping
        if (strcmp(period, "January") == 0) date->tm_mon = 0;
        if (strcmp(period, "February") == 0) date->tm_mon = 1;
        if (strcmp(period, "March") == 0) date->tm_mon = 2;
        if (strcmp(period, "April") == 0) date->tm_mon = 3;
        if (strcmp(period, "May") == 0) date->tm_mon = 4;
        if (strcmp(period, "June") == 0) date->tm_mon = 5;
        if (strcmp(period, "July") == 0) date->tm_mon = 6;
        if (strcmp(period, "August") == 0) date->tm_mon = 7;
        if (strcmp(period, "September") == 0) date->tm_mon = 8;
        if (strcmp(period, "October") == 0) date->tm_mon = 9;
        if (strcmp(period, "November") == 0) date->tm_mon = 10;
        if (strcmp(period, "December") == 0) date->tm_mon = 11;
    }

    *date = *current_time;
}

void print_date(struct tm date) {
    char buffer[MAX_LENGTH];
    strftime(buffer, sizeof(buffer), "%A, %d %B %Y %H:%M:%S", &date);
    printf("Your date is: %s\n", buffer);
}

int main() {
    display_welcome_message();
    char input[MAX_LENGTH];
    
    printf("Your poetic input: ");
    fgets(input, MAX_LENGTH, stdin);
    clear_buffer(); // Clear any leftovers

    // Removenewline character, if exists
    input[strcspn(input, "\n")] = 0;

    struct tm date;
    extract_date(input, &date);
    print_date(date);

    printf("Thank you for your words, traveler of time!\n");
    return 0;
}