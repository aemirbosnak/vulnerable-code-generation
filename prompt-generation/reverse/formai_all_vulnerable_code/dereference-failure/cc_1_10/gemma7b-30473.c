//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LEN 20

void convert_date(char *date_str)
{
    char month_str[3];
    int year, month, day;

    // Extract the year, month, and day from the date string
    year = atoi(strtok(date_str, "-"));
    month = atoi(strtok(NULL, "-"));
    day = atoi(strtok(NULL, "-"));

    // Convert the month name to a string
    switch (month)
    {
        case 1:
            month_str[0] = 'J';
            month_str[1] = 'a';
            month_str[2] = '\0';
            break;
        case 2:
            month_str[0] = 'F';
            month_str[1] = 'e';
            month_str[2] = '\0';
            break;
        case 3:
            month_str[0] = 'M';
            month_str[1] = 'a';
            month_str[2] = '\0';
            break;
        case 4:
            month_str[0] = 'A';
            month_str[1] = 'pr';
            month_str[2] = '\0';
            break;
        case 5:
            month_str[0] = 'M';
            month_str[1] = 'ay';
            month_str[2] = '\0';
            break;
        case 6:
            month_str[0] = 'J';
            month_str[1] = 'u';
            month_str[2] = '\0';
            break;
        case 7:
            month_str[0] = 'A';
            month_str[1] = 'ug';
            month_str[2] = '\0';
            break;
        case 8:
            month_str[0] = 'S';
            month_str[1] = 'ep';
            month_str[2] = '\0';
            break;
        case 9:
            month_str[0] = 'O';
            month_str[1] = 'ct';
            month_str[2] = '\0';
            break;
        case 10:
            month_str[0] = 'N';
            month_str[1] = 'ov';
            month_str[2] = '\0';
            break;
        case 11:
            month_str[0] = 'D';
            month_str[1] = 'ec';
            month_str[2] = '\0';
            break;
        case 12:
            month_str[0] = 'R';
            month_str[1] = 'e';
            month_str[2] = '\0';
            break;
    }

    // Print the converted date
    printf("%d %s %d, %d", day, month_str, year);
}

int main()
{
    char date_str[MAX_DATE_LEN];

    // Get the date from the user
    printf("Enter the date (dd-mm-yyyy): ");
    scanf("%s", date_str);

    // Convert the date
    convert_date(date_str);

    return 0;
}