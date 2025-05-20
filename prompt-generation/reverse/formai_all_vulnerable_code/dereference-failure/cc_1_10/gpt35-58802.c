//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a year is a leap year
int isLeapYear(int year)
{
    if (year % 400 == 0)
        return 1;
    if (year % 100 == 0)
        return 0;
    if (year % 4 == 0)
        return 1;
    return 0;
}

// Function to get the number of days in a particular month
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 31;
    }
}

// Function to convert a date from a string to integers
void stringToInt(char* str, int* day, int* month, int* year)
{
    *day = atoi(strtok(str, "/"));
    *month = atoi(strtok(NULL, "/"));
    *year = atoi(strtok(NULL, "/"));
}

// Function to convert a date from integers to a string
void intToString(int day, int month, int year, char* str)
{
    sprintf(str, "%02d/%02d/%04d", day, month, year);
}

// Function to add a certain number of days to a date
void addDays(int* day, int* month, int* year, int days)
{
    int i;
    for (i = 1; i <= days; i++)
    {
        // increase the day by 1
        (*day)++;
        if (*day > getDaysInMonth(*month, *year))
        {
            // if the day is beyond the number of days in the month, reset to 1 and increment the month
            *day = 1;
            (*month)++;
            if (*month > 12)
            {
                // if the month is beyond December, reset to January and increment the year
                *month = 1;
                (*year)++;
            }
        }
    }
}

int main()
{
    // Configuration options
    int daysToAdd = 30;
    char dateFormat[] = "%02d/%02d/%04d"; // format for printing dates

    // Get the input date
    char inputDate[11];
    printf("Enter a date in the format dd/mm/yyyy: ");
    scanf("%s", inputDate);

    // Convert the input date to integers
    int day, month, year;
    stringToInt(inputDate, &day, &month, &year);

    // Add the specified number of days to the input date
    addDays(&day, &month, &year, daysToAdd);

    // Convert the result back to a string and print it
    char result[11];
    intToString(day, month, year, result);
    printf("The date %s plus %d days is: ", inputDate, daysToAdd);
    printf(dateFormat, day, month, year);

    return 0;
}