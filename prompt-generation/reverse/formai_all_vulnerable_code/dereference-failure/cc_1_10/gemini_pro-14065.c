//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date *
create_date(int year, int month, int day)
{
    Date *date = malloc(sizeof(Date));
    if (date == NULL) {
        return NULL;
    }

    date->year = year;
    date->month = month;
    date->day = day;

    return date;
}

void
destroy_date(Date *date)
{
    free(date);
}

int
date_to_days(Date *date)
{
    int days = 0;

    days += date->year * 365;
    days += date->month * 30;
    days += date->day;

    return days;
}

Date *
days_to_date(int days)
{
    Date *date = malloc(sizeof(Date));
    if (date == NULL) {
        return NULL;
    }

    date->year = days / 365;
    date->month = (days % 365) / 30;
    date->day = days % 30;

    return date;
}

char *
date_to_string(Date *date)
{
    char *string = malloc(sizeof(char) * 11);
    if (string == NULL) {
        return NULL;
    }

    snprintf(string, 11, "%d-%d-%d", date->year, date->month, date->day);

    return string;
}

int
main(void)
{
    Date *date = create_date(2022, 12, 31);
    int days = date_to_days(date);
    Date *new_date = days_to_date(days);
    char *string = date_to_string(new_date);

    printf("Date: %s\n", string);

    destroy_date(date);
    destroy_date(new_date);
    free(string);

    return 0;
}