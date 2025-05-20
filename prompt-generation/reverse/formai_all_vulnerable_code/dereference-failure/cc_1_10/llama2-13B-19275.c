//LLAMA2-13B DATASET v1.0 Category: Digital Diary ; Style: retro
// Retro Digital Diary v1.0

#include <stdio.h>
#include <string.h>
#include <time.h>

#define DAY_NAMES "Sunday Monday Tuesday Wednesday Thursday Friday Saturday"
#define MONTH_NAMES "January February March April May June July August September October November December"

// Global variables
int day, month, year;
char name[10];

// Function declarations
void greet(void);
void set_date(void);
void log_entry(char *message);

// Main program
int main(void)
{
    set_date();
    while (1)
    {
        printf("--- Retro Digital Diary v1.0 ---\n");
        printf("Current date: %s %s %d\n", DAY_NAMES[day], MONTH_NAMES[month], year);
        printf("What would you like to do? (q/Q to quit): ");
        scanf("%s", name);

        // Process user input
        if (strcmp(name, "q") == 0 || strcmp(name, "Q") == 0)
            break;

        log_entry(name);
    }

    return 0;
}

// Set current date
void set_date(void)
{
    time_t now;
    struct tm *lt;

    now = time(0);
    lt = localtime(&now);
    day = lt->tm_mday;
    month = lt->tm_mon + 1; // 0-based indexing
    year = lt->tm_year + 1900; // 1900 is the epoch for C standard time
}

// Log entry function
void log_entry(char *message)
{
    char line[100];
    int i;

    // Format the log entry
    for (i = 0; i < 100; i++)
        line[i] = message[i];
    line[i] = '\0';

    // Print the log entry
    printf("[%s %s %d] %s\n", DAY_NAMES[day], MONTH_NAMES[month], year, line);
}

// Greet the user
void greet(void)
{
    printf("Welcome to Retro Digital Diary v1.0!\n");
}