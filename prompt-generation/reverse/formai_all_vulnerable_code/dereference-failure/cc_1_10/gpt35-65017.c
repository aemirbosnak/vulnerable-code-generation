//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the year entered is a leap year or not
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
        case 1:
            return 31;
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return -1;
    }
}

// Function to convert the date from natural language to numeric format
void naturalToNumeric(char *date)
{
    char month[10], day[5], year[10];
    int i, j=0, k=0, l=0;
    int dd=0, mm=0, yyyy=0;

    // Splitting the natural language date into month, day and year
    for (i=0; i<strlen(date); i++)
    {
        if (date[i] == ' ')
        {
            j++;
            k = 0;
            l = i+1;
        }
        else
        {
            if (j == 0)
                month[k++] = date[i];
            else if (j == 1)
                day[k++] = date[i];
            else if (j == 2)
                year[k++] = date[i];
        }
    }
    month[k] = '\0';
    day[k] = '\0';
    year[k] = '\0';

    // Converting the month, day and year from string to integer
    dd = atoi(day);
    mm = (strcmp(month, "January") == 0) ? 1 :
         (strcmp(month, "February") == 0) ? 2 :
         (strcmp(month, "March") == 0) ? 3 :
         (strcmp(month, "April") == 0) ? 4 :
         (strcmp(month, "May") == 0) ? 5 :
         (strcmp(month, "June") == 0) ? 6 :
         (strcmp(month, "July") == 0) ? 7 :
         (strcmp(month, "August") == 0) ? 8 :
         (strcmp(month, "September") == 0) ? 9 :
         (strcmp(month, "October") == 0) ? 10 :
         (strcmp(month, "November") == 0) ? 11 : 12;
    yyyy = atoi(year);

    // Checking if the date entered is valid or not
    if (dd > getDaysInMonth(mm, yyyy) || mm < 1 || mm > 12 || yyyy < 1)
    {
        printf("Invalid date!\n");
        exit(0);
    }

    // Printing the date in numeric format
    printf("The date in numeric format is:\n");
    printf("%02d-%02d-%04d\n", dd, mm, yyyy);
}

int main()
{
    char date[20];
    printf("Enter a date in natural language (example: September 15th, 2021): ");
    fgets(date, 20, stdin);
    naturalToNumeric(date);
    return 0;
}