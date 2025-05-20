//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
int parseMonth(char *);
int parseDay(char *);
int parseYear(char *);

// main function
int main()
{
    char inputDate[20];

    // prompt user for input
    printf("Enter a date in the format of MM/DD/YYYY: ");
    fgets(inputDate, sizeof(inputDate), stdin);

    // remove newline character from input
    inputDate[strcspn(inputDate, "\n")] = '\0';

    // split input string into month, day, and year
    char *token = strtok(inputDate, "/");
    int month = parseMonth(token);

    token = strtok(NULL, "/");
    int day = parseDay(token);

    token = strtok(NULL, "/");
    int year = parseYear(token);

    printf("Date in natural language: ");

    switch (month)
    {
        case 1:
            printf("January %d", day);
            break;
        case 2:
            printf("February %d", day);
            break;
        case 3:
            printf("March %d", day);
            break;
        case 4:
            printf("April %d", day);
            break;
        case 5:
            printf("May %d", day);
            break;
        case 6:
            printf("June %d", day);
            break;
        case 7:
            printf("July %d", day);
            break;
        case 8:
            printf("August %d", day);
            break;
        case 9:
            printf("September %d", day);
            break;
        case 10:
            printf("October %d", day);
            break;
        case 11:
            printf("November %d", day);
            break;
        case 12:
            printf("December %d", day);
            break;
        default:
            printf("Invalid month");
            exit(EXIT_FAILURE);
    }

    if (day == 1 || day == 21 || day == 31)
        printf("st, ");
    else if (day == 2 || day == 22)
        printf("nd, ");
    else if (day == 3 || day == 23)
        printf("rd, ");
    else
        printf("th, ");

    printf("%d", year);

    return 0;
}

// function to parse month from input string
int parseMonth(char *str)
{
    int month = atoi(str);

    if (month < 1 || month > 12)
    {
        printf("Invalid month");
        exit(EXIT_FAILURE);
    }

    return month;
}

// function to parse day from input string
int parseDay(char *str)
{
    int day = atoi(str);

    if (day < 1 || day > 31)
    {
        printf("Invalid day");
        exit(EXIT_FAILURE);
    }

    return day;
}

// function to parse year from input string
int parseYear(char *str)
{
    int year = atoi(str);

    if (year < 0)
    {
        printf("Invalid year");
        exit(EXIT_FAILURE);
    }

    return year;
}