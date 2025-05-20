//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isLeapYear(int year);
int getMonthDays(int year, int month);
int convertMonthToInt(char month[10]);
void convertDate(char date[20]);

int main()
{
    char date[20];

    printf("Enter a date in natural language (e.g. January 1st, 2022): ");
    fgets(date, 20, stdin);

    convertDate(date);

    return 0;
}

bool isLeapYear(int year)
{
    if(year % 400 == 0)
        return true;
    if(year % 100 == 0)
        return false;
    if(year % 4 == 0)
        return true;
    return false;
}

int getMonthDays(int year, int month)
{
    int days;

    switch(month)
    {
        case 2:
            days = isLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
    }

    return days;
}

int convertMonthToInt(char month[10])
{
    if(strcmp(month, "January") == 0)
        return 1;
    else if(strcmp(month, "February") == 0)
        return 2;
    else if(strcmp(month, "March") == 0)
        return 3;
    else if(strcmp(month, "April") == 0)
        return 4;
    else if(strcmp(month, "May") == 0)
        return 5;
    else if(strcmp(month, "June") == 0)
        return 6;
    else if(strcmp(month, "July") == 0)
        return 7;
    else if(strcmp(month, "August") == 0)
        return 8;
    else if(strcmp(month, "September") == 0)
        return 9;
    else if(strcmp(month, "October") == 0)
        return 10;
    else if(strcmp(month, "November") == 0)
        return 11;
    else if(strcmp(month, "December") == 0)
        return 12;
    else
        return -1;
}

void convertDate(char date[20])
{
    char *month, *day, *year, *suffix;
    int intMonth, intDay, intYear, days;

    month = strtok(date, " ");
    day = strtok(NULL, " ");
    strtok(NULL, " ");
    year = strtok(NULL, " ");
    suffix = strstr(day, "th");

    if(suffix == NULL)
        suffix = strstr(day, "st");
    if(suffix == NULL)
        suffix = strstr(day, "nd");
    if(suffix == NULL)
        suffix = strstr(day, "rd");

    if(suffix != NULL)
        *suffix = '\0';

    intMonth = convertMonthToInt(month);
    intDay = atoi(day);
    intYear = atoi(year);

    days = getMonthDays(intYear, intMonth);

    if(intDay > days || intDay < 1)
    {
        printf("Invalid date, please enter a valid date.\n");
        return;
    }

    printf("The converted date is: %02d/%02d/%d\n", intMonth, intDay, intYear);
}