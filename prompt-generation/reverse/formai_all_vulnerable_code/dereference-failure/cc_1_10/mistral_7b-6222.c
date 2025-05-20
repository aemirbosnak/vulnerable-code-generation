//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MONTHS_CYBERPUNK "January:31,February:28,March:31,April:30,May:31,June:30,July:31,August:31,September:30,October:31,November:30,December:31"

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

int get_days_in_month(int year, int month) {
    if (is_leap_year(year) && month == 2) {
        return 29;
    } else if (month < 7) {
        return (1 + (month % 2 == 0 ? 30 : 31) + (is_leap_year(year) && month == 2));
    } else {
        return (31 - (int)(month % 2));
    }
}

int parse_date(char *str, int *year, int *month, int *day) {
    char *token;
    char month_str[10], day_str[10];
    int month_index;

    strcpy(month_str, strtok(str, ":"));
    strcpy(day_str, strtok(NULL, ":"));

    *year = atoi(strtok(NULL, ":"));

    month_index = strspn(MONTHS_CYBERPUNK, month_str);
    if (month_index >= strlen(MONTHS_CYBERPUNK) || month_index < 0) {
        return 1;
    }

    *month = month_index / (sizeof(int) * 2) + 1;
    *day = atoi(day_str);

    if (*day > get_days_in_month(*year, *month) || *month < 1 || *month > 12 || *year < 1) {
        return 1;
    }

    return 0;
}

void print_date(int year, int month, int day) {
    printf("%d-%02d-%02d\n", year, month, day);
}

int main(int argc, char **argv) {
    int year, month, day;
    char input[100];

    if (argc != 2) {
        printf("Usage: %s <date in format 'month:day:year'>\n", argv[0]);
        return 1;
    }

    if (parse_date(argv[1], &year, &month, &day) != 0) {
        printf("Invalid date format.\n");
        return 1;
    }

    print_date(year, month, day);
    return 0;
}