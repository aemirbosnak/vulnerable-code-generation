//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the input date is valid or not
int validateDate(int date, int month, int year)
{
    // Check for leap year
    int leap = 0;
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        leap = 1;

    // Validate month
    if (month < 1 || month > 12)
        return 0;

    // Get maximum days in the month
    int maxDays;
    if (month == 2)
        maxDays = 28 + leap;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
    else
        maxDays = 31;

    // Validate date
    if (date < 1 || date > maxDays)
        return 0;

    // If all validations pass, return 1
    return 1;
}

// Function to convert date from string format to integer format
void convertDate(char *dateStr, int *date, int *month, int *year)
{
    char *token;
    token = strtok(dateStr, "/");
    *date = atoi(token);
    token = strtok(NULL, "/");
    *month = atoi(token);
    token = strtok(NULL, "/");
    *year = atoi(token);
}

// Function to convert month from integer format to string format
char* monthToString(int month)
{
    switch(month)
    {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Invalid Month!";
    }
}

int main()
{
    // Declare variables for input date
    char dateStr[11];
    int date, month, year;

    // Get input date from user
    printf("Enter date (in dd/mm/yyyy format): ");
    fgets(dateStr, 11, stdin);

    // Convert input date from string to integer format
    convertDate(dateStr, &date, &month, &year);

    // Validate input date
    if (!validateDate(date, month, year))
    {
        printf("Invalid date entered!");
        return 1;
    }

    // Convert month from integer to string format
    char *monthStr = monthToString(month);

    // Print output date in long format
    printf("%d %s %d\n", date, monthStr, year);

    return 0;
}