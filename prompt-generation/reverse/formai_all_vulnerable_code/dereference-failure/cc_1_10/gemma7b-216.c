//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    char *date_str;

    printf("Enter a date in the format YYYY-MM-DD: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    date_str = strchr(buffer, '-') ;
    if (date_str == NULL)
    {
        printf("Invalid date format.\n");
        return 1;
    }

    // Extract the year, month, and day from the input string
    char year_str[4];
    char month_str[2];
    char day_str[2];

    memcpy(year_str, buffer, 4);
    memcpy(month_str, date_str + 1, 2);
    memcpy(day_str, date_str + 4, 2);

    // Convert the extracted numbers to integers
    int year = atoi(year_str);
    int month = atoi(month_str);
    int day = atoi(day_str);

    // Check if the date is valid
    if (year < 1 || year > 2000)
    {
        printf("Invalid year.\n");
        return 1;
    }
    if (month < 1 || month > 12)
    {
        printf("Invalid month.\n");
        return 1;
    }
    if (day < 1 || day > 31)
    {
        printf("Invalid day.\n");
        return 1;
    }

    // Print the converted date
    printf("The date you entered is: %d-%d-%d\n", year, month, day);

    return 0;
}