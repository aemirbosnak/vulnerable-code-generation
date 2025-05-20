//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_DATE_LENGTH 20
#define MAX_MONTH_LENGTH 10
#define MAX_YEAR_LENGTH 5

typedef struct {
    char month[MAX_MONTH_LENGTH];
    char day[MAX_DATE_LENGTH];
    char year[MAX_YEAR_LENGTH];
} Date;

void normalize_date(Date *date) {
    char *month_str = strdup(date->month);
    char *day_str = strdup(date->day);
    char *year_str = strdup(date->year);

    for (int i = 0; i < strlen(month_str); i++) {
        month_str[i] = tolower(month_str[i]);
    }

    for (int i = 0; i < strlen(day_str); i++) {
        if (!isdigit(day_str[i])) {
            day_str[i] = '0';
        }
    }

    for (int i = 0; i < strlen(year_str); i++) {
        year_str[i] = tolower(year_str[i]);
    }

    strcpy(date->month, month_str);
    strcpy(date->day, day_str);
    strcpy(date->year, year_str);

    free(month_str);
    free(day_str);
    free(year_str);
}

int is_valid_date(Date *date) {
    int month, day, year;
    struct tm tm;

    if (strlen(date->month)!= 3) {
        return 0;
    }

    if (strlen(date->day)!= 2) {
        return 0;
    }

    if (strlen(date->year)!= 4) {
        return 0;
    }

    month = atoi(date->month);
    day = atoi(date->day);
    year = atoi(date->year);

    if (month < 1 || month > 12) {
        return 0;
    }

    if (day < 1 || day > 31) {
        return 0;
    }

    if (year < 1900 || year > 2100) {
        return 0;
    }

    memset(&tm, 0, sizeof(struct tm));
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

    if (mktime(&tm) == -1) {
        return 0;
    }

    return 1;
}

int main() {
    Date date;

    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%s/%s/%s", date.month, date.day, date.year);

    normalize_date(&date);

    if (is_valid_date(&date)) {
        struct tm tm;
        time_t timestamp;

        memset(&tm, 0, sizeof(struct tm));
        tm.tm_year = atoi(date.year) - 1900;
        tm.tm_mon = atoi(date.month) - 1;
        tm.tm_mday = atoi(date.day);

        timestamp = mktime(&tm);

        printf("The date is valid and the Unix timestamp is: %ld\n", timestamp);
    } else {
        printf("Invalid date\n");
    }

    return 0;
}