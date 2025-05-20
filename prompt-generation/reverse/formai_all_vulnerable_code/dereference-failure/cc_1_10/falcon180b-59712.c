//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MONTH_LIST "January February March April May June July August September October November December"

char *get_month(int month)
{
    char *month_str = strtok(MONTH_LIST, " ");
    for (int i = 1; i < month; i++)
        month_str = strtok(NULL, " ");
    return month_str;
}

int get_day(char *date_str)
{
    int day = 0;
    while (isdigit(*date_str))
    {
        day = day * 10 + (*date_str - '0');
        date_str++;
    }
    return day;
}

int get_year(char *date_str)
{
    int year = 0;
    while (isdigit(*date_str))
    {
        year = year * 10 + (*date_str - '0');
        date_str++;
    }
    return year;
}

int is_valid_date(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;
    if (month == 2)
    {
        if (day > 29 &&!(year % 4 == 0 && year % 100!= 0 || year % 400 == 0))
            return 0;
    }
    return 1;
}

int main()
{
    char input[MAX_LENGTH];
    printf("Enter a date in MM/DD/YYYY format: ");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    char *date_str = strtok(input, "/");
    int month = atoi(date_str);
    date_str = strtok(NULL, "/");
    int day = get_day(date_str);
    date_str = strtok(NULL, "/");
    int year = get_year(date_str);
    if (is_valid_date(day, month, year))
        printf("Valid date: %s %d, %d\n", get_month(month), day, year);
    else
        printf("Invalid date\n");
    return 0;
}