//Gemma-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LEN 20

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

int main() {
    char date_str[MAX_DATE_LEN];
    Date date;

    printf("Enter a date in the format YYYY-MM-DD: ");
    scanf("%s", date_str);

    if (parse_date(date_str, &date) == 0) {
        printf("Date parsed successfully: %d-%d-%d\n", date.year, date.month, date.day);
    } else {
        printf("Error parsing date.\n");
    }

    return 0;
}

int parse_date(char *date_str, Date *date) {
    char *year_str, *month_str, *day_str;
    int year, month, day;

    // Extract the year, month, and day from the input string
    year_str = strchr(date_str, '-') + 1;
    month_str = strchr(year_str, '-') + 1;
    day_str = strchr(month_str, '-') + 1;

    // Convert the extracted strings to integers
    year = atoi(year_str);
    month = atoi(month_str);
    day = atoi(day_str);

    // Initialize the Date structure
    date->year = year;
    date->month = month;
    date->day = day;

    return 0;
}