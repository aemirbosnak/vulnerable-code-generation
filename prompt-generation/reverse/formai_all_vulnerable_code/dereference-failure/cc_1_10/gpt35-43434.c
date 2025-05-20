//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a year is a leap year
int isLeapYear(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 1;
    else
        return 0;
}

// Function to convert date to day of year
int dateToDay(int day, int month, int year)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = 0;

    for (int i = 0; i < month - 1; i++)
    {
        dayOfYear += daysInMonth[i];
        if (i == 1 && isLeapYear(year))
            dayOfYear++;
    }

    dayOfYear += day;

    return dayOfYear;
}

// Function to convert day of year to date
void dayToDate(int dayOfYear, int year, int *day, int *month)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    *month = 1;

    if (isLeapYear(year))
        daysInMonth[1]++;

    while (dayOfYear > daysInMonth[*month - 1])
    {
        dayOfYear -= daysInMonth[*month - 1];
        (*month)++;
    }

    *day = dayOfYear;
}

int main()
{
    // Get user input
    char dateString[11];
    printf("Enter date in format DD/MM/YYYY: ");
    fgets(dateString, 11, stdin);

    // Extract day, month, year
    int day = atoi(strtok(dateString, "/"));
    int month = atoi(strtok(NULL, "/"));
    int year = atoi(strtok(NULL, "/"));

    // Convert to day of year
    int dayOfYear = dateToDay(day, month, year);

    // Convert back to date and print
    int newDay, newMonth;
    dayToDate(dayOfYear, year, &newDay, &newMonth);
    printf("\nDay of year: %d", dayOfYear);
    printf("\nConverted date: %02d/%02d/%04d", newDay, newMonth, year);

    return 0;
}