//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 25 // maximum length of input string

int is_leap_year(int year)
{
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            return 1;
        else
            return 0;
    }
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

int month_days(int month, int year)
{
    int days = 31; // default value for most months
    switch (month)
    {
        case 2:
            if (is_leap_year(year))
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
    }
    return days;
}

int main()
{
    char input[MAX_LEN];
    char *day_str, *month_str, *year_str;
    int day, month, year, days_in_month;

    printf("Enter date in natural language (e.g. January 1st, 2022): ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character from input

    // tokenize input string using strtok
    day_str = strtok(input, " ,");
    month_str = strtok(NULL, " ,");
    year_str = strtok(NULL, " ,");

    // convert string inputs to integers
    day = atoi(day_str);
    year = atoi(year_str);

    // convert month string to integer
    if (strcmp(month_str, "January") == 0)
        month = 1;
    else if (strcmp(month_str, "February") == 0)
        month = 2;
    else if (strcmp(month_str, "March") == 0)
        month = 3;
    else if (strcmp(month_str, "April") == 0)
        month = 4;
    else if (strcmp(month_str, "May") == 0)
        month = 5;
    else if (strcmp(month_str, "June") == 0)
        month = 6;
    else if (strcmp(month_str, "July") == 0)
        month = 7;
    else if (strcmp(month_str, "August") == 0)
        month = 8;
    else if (strcmp(month_str, "September") == 0)
        month = 9;
    else if (strcmp(month_str, "October") == 0)
        month = 10;
    else if (strcmp(month_str, "November") == 0)
        month = 11;
    else if (strcmp(month_str, "December") == 0)
        month = 12;
    else
    {
        printf("Invalid month name\n");
        exit(1);
    }

    // determine number of days in the given month and year
    days_in_month = month_days(month, year);

    // check if the given day is valid
    if (day < 1 || day > days_in_month)
    {
        printf("Invalid day of the month\n");
        exit(1);
    }

    // print the date in the desired format
    printf("%d/%d/%d\n", month, day, year);

    return 0;
}