//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS_NUM 12
#define MAX_LEN 100
#define DATE_FORMAT "%%%dm%%%b%%%d%%%Y"
#define LEAP_YEAR(y) ((y) % 4 == 0 && ((y) % 100 != 0 || (y) % 400 == 0))

typedef struct {
    int day;
    int month;
    int year;
} Date;

int get_day(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (LEAP_YEAR(year)) days[1] = 29;
    return days[month - 1];
}

int check_date(const char *date_str) {
    int day, month, year, len;
    sscanf(date_str, "%d/%d/%d", &day, &month, &year);
    if (strlen(date_str) != MAX_LEN || day < 1 || month < 1 || month > MONTHS_NUM || year < 0)
        return 0;
    if (day > get_day(month, year)) return 0;
    return 1;
}

Date string_to_date(const char *date_str) {
    int day, month, year;
    sscanf(date_str, "%d/%d/%d", &day, &month, &year);
    Date date = {day, month, year};
    if (check_date(date_str) == 0) {
        fprintf(stderr, "Invalid date: %s\n", date_str);
        exit(EXIT_FAILURE);
    }
    return date;
}

char *date_to_string(const Date *date) {
    int month = date->month;
    int day = date->day;
    int year = date->year;
    char month_name[4][4] = {"Jan", "Feb", "Mar", "Apr"};
    char *str;

    asprintf(&str, "%d %s %d", day, month_name[month - 1], year);
    return str;
}

void print_date(const Date *date) {
    printf("%s\n", date_to_string(date));
}

int main(int argc, char *argv[]) {
    Date input_date;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s DATE_STRING\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_date = string_to_date(argv[1]);
    print_date(&input_date);
    return EXIT_SUCCESS;
}