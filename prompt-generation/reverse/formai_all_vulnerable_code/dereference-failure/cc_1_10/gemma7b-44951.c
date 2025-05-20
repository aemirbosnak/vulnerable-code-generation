//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: ultraprecise
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define YEAR_LEN 4
#define MONTH_LEN 2
#define DAY_LEN 2

#define MAX_DATE_LEN 10

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

Date parse_date(char *date_str) {
    Date date;

    char *year_str = strtok(date_str, "-");
    date.year = atoi(year_str);

    char *month_str = strtok(NULL, "-");
    date.month = atoi(month_str);

    char *day_str = strtok(NULL, "-");
    date.day = atoi(day_str);

    return date;
}

char *format_date(Date date) {
    char *date_str = malloc(MAX_DATE_LEN);

    sprintf(date_str, "%04d-%02d-%02d", date.year, date.month, date.day);

    return date_str;
}

int main() {
    char *date_str = "2023-04-01";

    Date date = parse_date(date_str);
    char *formatted_date = format_date(date);

    printf("%s\n", formatted_date);

    free(formatted_date);

    return 0;
}