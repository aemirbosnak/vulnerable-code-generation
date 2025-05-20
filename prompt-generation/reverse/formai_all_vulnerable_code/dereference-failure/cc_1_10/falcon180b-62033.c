//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

int is_valid_date(int day, int month, int year) {
    struct tm date_time = {0};
    date_time.tm_year = year - 1900;
    date_time.tm_mon = month - 1;
    date_time.tm_mday = day;

    if (date_time.tm_year < 0) {
        return 0;
    }

    if (date_time.tm_mon < 0 || date_time.tm_mon > 11) {
        return 0;
    }

    if (date_time.tm_mday < 1 || date_time.tm_mday > 31) {
        return 0;
    }

    return 1;
}

int main() {
    char input_buffer[MAX_STRING_LENGTH];
    char *token;
    int day, month, year;

    printf("Enter a date in the format of DD/MM/YYYY: ");
    fgets(input_buffer, MAX_STRING_LENGTH, stdin);

    token = strtok(input_buffer, "/");
    day = atoi(token);

    token = strtok(NULL, "/");
    month = atoi(token);

    token = strtok(NULL, "/");
    year = atoi(token);

    if (is_valid_date(day, month, year)) {
        printf("Valid date: %02d/%02d/%04d\n", day, month, year);
    } else {
        printf("Invalid date\n");
    }

    return 0;
}