//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATE_FORMAT "%d/%m/%Y"

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date *date_create(int day, int month, int year) {
    Date *date = malloc(sizeof(Date));
    date->day = day;
    date->month = month;
    date->year = year;
    return date;
}

void date_destroy(Date *date) {
    free(date);
}

int date_compare(Date *date1, Date *date2) {
    if (date1->year != date2->year) {
        return date1->year - date2->year;
    } else if (date1->month != date2->month) {
        return date1->month - date2->month;
    } else {
        return date1->day - date2->day;
    }
}

char *date_to_string(Date *date) {
    char *str = malloc(sizeof(char) * 11);
    sprintf(str, DATE_FORMAT, date->day, date->month, date->year);
    return str;
}

Date *date_from_string(char *str) {
    int day, month, year;
    sscanf(str, DATE_FORMAT, &day, &month, &year);
    return date_create(day, month, year);
}

int main() {
    Date *date1 = date_create(1, 1, 2000);
    Date *date2 = date_create(1, 2, 2000);
    Date *date3 = date_create(1, 3, 2000);

    printf("Date 1: %s\n", date_to_string(date1));
    printf("Date 2: %s\n", date_to_string(date2));
    printf("Date 3: %s\n", date_to_string(date3));

    printf("Date 1 < Date 2: %d\n", date_compare(date1, date2) < 0);
    printf("Date 2 < Date 3: %d\n", date_compare(date2, date3) < 0);
    printf("Date 3 < Date 1: %d\n", date_compare(date3, date1) < 0);

    date_destroy(date1);
    date_destroy(date2);
    date_destroy(date3);

    return 0;
}