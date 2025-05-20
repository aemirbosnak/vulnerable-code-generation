//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int convert_date(char **month, char **day, int year)
{
    char **months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i, month_num = -1;

    for (i = 0; i < 12; i++)
    {
        if (strcmp(month, months[i]) == 0)
        {
            month_num = i + 1;
            break;
        }
    }

    if (month_num == -1)
    {
        return -1;
    }

    int date_num = atoi(day);
    int days_in_month = cal_days_in_month(month_num, year);

    if (date_num > days_in_month)
    {
        return -1;
    }

    return 0;
}

int cal_days_in_month(int month_num, int year)
{
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return days_in_month[month_num - 1] + (year % 400 == 0 && month_num > 2) ? 1 : 0;
}

int main()
{
    char **month = malloc(10);
    char **day = malloc(10);
    int year = 0;

    printf("Enter the month (e.g. January): ");
    scanf("%s", month);

    printf("Enter the day (e.g. 1): ");
    scanf("%s", day);

    printf("Enter the year (e.g. 2023): ");
    scanf("%d", &year);

    int result = convert_date(month, day, year);

    if (result == 0)
    {
        printf("The date is valid.\n");
    }
    else
    {
        printf("The date is invalid.\n");
    }

    free(month);
    free(day);

    return 0;
}