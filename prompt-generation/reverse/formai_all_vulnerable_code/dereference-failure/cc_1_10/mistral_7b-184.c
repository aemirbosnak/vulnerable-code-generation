//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS_IN_YEAR 12
#define LEAP_YEAR(year) ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))

void string_to_date(const char *input, int *day, int *month, int *year) {
    *day = 0;
    *month = 0;
    *year = 0;

    int pos = 0;

    while (isspace(input[pos])) pos++;

    if (pos >= strlen(input)) {
        fprintf(stderr, "Invalid date format\n");
        exit(EXIT_FAILURE);
    }

    *day = atoi(input + pos);
    pos += strlen_of_number(*day);

    if (pos >= strlen(input) || input[pos++] != '-') {
        fprintf(stderr, "Invalid date format\n");
        exit(EXIT_FAILURE);
    }

    *month = atoi(input + pos);
    pos += strlen_of_number(*month);

    if (pos >= strlen(input) || input[pos++] != '-') {
        fprintf(stderr, "Invalid date format\n");
        exit(EXIT_FAILURE);
    }

    *year = atoi(input + pos);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s DD-MM-YYYY\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int day, month, year;
    string_to_date(argv[1], &day, &month, &year);

    int days_in_month[] = {31, LEAP_YEAR(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_days = day - 1;

    for (int i = month - 1; i >= 0; i--) total_days += days_in_month[i];

    time_t unix_timestamp = timegm(asctime(localtime(&total_days)));

    printf("Date: %d-%02d-%04d\n", day, month, year);
    printf("Unix timestamp: %ld\n", (long)unix_timestamp);

    return EXIT_SUCCESS;
}

int strlen_of_number(int number) {
    int len = 1;
    while (number >= 10) {
        number /= 10;
        len++;
    }
    return len;
}