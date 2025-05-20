//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date *date_create(int year, int month, int day) {
    Date *date = malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

void date_destroy(Date *date) {
    free(date);
}

int date_compare(const Date *date1, const Date *date2) {
    if (date1->year != date2->year) {
        return date1->year - date2->year;
    } else if (date1->month != date2->month) {
        return date1->month - date2->month;
    } else {
        return date1->day - date2->day;
    }
}

char *date_to_string(const Date *date) {
    char *string = malloc(11);
    sprintf(string, "%04d-%02d-%02d", date->year, date->month, date->day);
    return string;
}

Date *string_to_date(const char *string) {
    int year, month, day;
    sscanf(string, "%04d-%02d-%02d", &year, &month, &day);
    return date_create(year, month, day);
}

int main() {
    Date *date1 = date_create(2020, 1, 1);
    Date *date2 = date_create(2020, 2, 1);
    Date *date3 = date_create(2020, 3, 1);

    printf("Date1: %s\n", date_to_string(date1));
    printf("Date2: %s\n", date_to_string(date2));
    printf("Date3: %s\n", date_to_string(date3));

    int comparison1 = date_compare(date1, date2);
    int comparison2 = date_compare(date2, date3);
    int comparison3 = date_compare(date1, date3);

    printf("Comparison1: %d\n", comparison1);
    printf("Comparison2: %d\n", comparison2);
    printf("Comparison3: %d\n", comparison3);

    date_destroy(date1);
    date_destroy(date2);
    date_destroy(date3);

    return 0;
}