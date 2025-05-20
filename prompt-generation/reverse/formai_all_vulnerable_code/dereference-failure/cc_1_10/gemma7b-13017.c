//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 20

char **convert_date(char *date_str)
{
    char **date_parts = malloc(sizeof(char *) * 3);
    char *date_year = malloc(MAX_DATE_LEN);
    char *date_month = malloc(MAX_DATE_LEN);
    char *date_day = malloc(MAX_DATE_LEN);

    int year_pos = -1;
    int month_pos = -1;
    int day_pos = -1;

    for (int i = 0; i < MAX_DATE_LEN && date_str[i] != '\0'; i++)
    {
        if (date_str[i] >= 'a' && date_str[i] <= 'z')
        {
            date_str[i] -= 32;
        }

        if (date_str[i] == '-')
        {
            if (year_pos == -1)
            {
                year_pos = i;
            }
            else if (month_pos == -1)
            {
                month_pos = i;
            }
            else if (day_pos == -1)
            {
                day_pos = i;
            }
        }
    }

    date_parts[0] = date_year;
    date_parts[1] = date_month;
    date_parts[2] = date_day;

    strcpy(date_year, date_str);
    date_year[year_pos] = '\0';
    strcpy(date_month, date_str + year_pos + 1);
    date_month[month_pos] = '\0';
    strcpy(date_day, date_str + month_pos + 1);
    date_day[day_pos] = '\0';

    return date_parts;
}

int main()
{
    char *date_str = "January 22, 2023";
    char **date_parts = convert_date(date_str);

    printf("Year: %s\n", date_parts[0]);
    printf("Month: %s\n", date_parts[1]);
    printf("Day: %s\n", date_parts[2]);

    free(date_parts[0]);
    free(date_parts[1]);
    free(date_parts[2]);
    free(date_parts);

    return 0;
}