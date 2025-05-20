//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if given year is a leap year
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

// Function to get number of days in a month of a year
int getDaysInMonth(int year, int month)
{
    // Standard number of days in a month
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If leap year, February has 29 days
    if (month == 2 && isLeapYear(year))
        return 29;
    else
        return days_in_month[month - 1];
}

// Function to convert natural language date to ISO date format
void convertDate(char* natural_lang_date)
{
    // Tokenize the input string
    char* tokens[10];
    int count = 0;
    char* token = strtok(natural_lang_date, " ");
    while (token != NULL)
    {
        tokens[count++] = token;
        token = strtok(NULL, " ");
    }

    // Get day, month and year values from tokens
    int day = atoi(tokens[1]);
    int month = 0;
    char* month_string = tokens[0];
    if (strcmp(month_string, "January") == 0)
        month = 1;
    else if (strcmp(month_string, "February") == 0)
        month = 2;
    else if (strcmp(month_string, "March") == 0)
        month = 3;
    else if (strcmp(month_string, "April") == 0)
        month = 4;
    else if (strcmp(month_string, "May") == 0)
        month = 5;
    else if (strcmp(month_string, "June") == 0)
        month = 6;
    else if (strcmp(month_string, "July") == 0)
        month = 7;
    else if (strcmp(month_string, "August") == 0)
        month = 8;
    else if (strcmp(month_string, "September") == 0)
        month = 9;
    else if (strcmp(month_string, "October") == 0)
        month = 10;
    else if (strcmp(month_string, "November") == 0)
        month = 11;
    else if (strcmp(month_string, "December") == 0)
        month = 12;

    int year = atoi(tokens[2]);

    // Check if input date is valid
    if (day <= 0 || month <= 0 || month > 12 || year <= 0)
    {
        printf("Invalid date.\n");
        return;
    }

    // Check if day is valid for given month and year
    int days_in_month = getDaysInMonth(year, month);
    if (day > days_in_month)
    {
        printf("Invalid date.\n");
        return;
    }

    // Print ISO date format
    printf("%04d-%02d-%02d\n", year, month, day);
}

int main()
{
    char natural_lang_date[256];
    printf("Enter natural language date (e.g. August 25 2021): ");
    fgets(natural_lang_date, 256, stdin);
    natural_lang_date[strcspn(natural_lang_date, "\n")] = '\0'; // Remove trailing newline

    convertDate(natural_lang_date);

    return 0;
}