//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 100

struct tm get_tm(char *date_str) {
    struct tm tm = {0};
    int day, month, year;

    // Parse the day
    char *day_str = strtok(date_str, " ");
    if (day_str == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }
    if (sscanf(day_str, "%d", &day)!= 1) {
        printf("Invalid date format.\n");
        exit(1);
    }
    tm.tm_mday = day;

    // Parse the month
    char *month_str = strtok(NULL, " ");
    if (month_str == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }
    if (sscanf(month_str, "%d", &month)!= 1) {
        printf("Invalid date format.\n");
        exit(1);
    }
    tm.tm_mon = month - 1;

    // Parse the year
    char *year_str = strtok(NULL, " ");
    if (year_str == NULL) {
        printf("Invalid date format.\n");
        exit(1);
    }
    if (sscanf(year_str, "%d", &year)!= 1) {
        printf("Invalid date format.\n");
        exit(1);
    }
    tm.tm_year = year - 1900;
    tm.tm_isdst = -1;

    return tm;
}

char *format_date(struct tm tm) {
    char *date_str = malloc(MAX_DATE_LENGTH);
    strftime(date_str, MAX_DATE_LENGTH, "%A, %B %d, %Y", &tm);
    return date_str;
}

int main() {
    char *input_date;
    struct tm tm;

    printf("Enter a date (format: day month year): ");
    scanf("%s", input_date);

    tm = get_tm(input_date);
    char *formatted_date = format_date(tm);

    printf("Formatted date: %s\n", formatted_date);

    free(formatted_date);
    return 0;
}