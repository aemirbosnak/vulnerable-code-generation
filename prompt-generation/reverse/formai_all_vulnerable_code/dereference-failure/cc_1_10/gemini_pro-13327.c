//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 11

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* date_create(int year, int month, int day) {
    Date* date = (Date*)malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

void date_destroy(Date* date) {
    free(date);
}

int date_compare(Date* date1, Date* date2) {
    if (date1->year != date2->year) {
        return date1->year - date2->year;
    } else if (date1->month != date2->month) {
        return date1->month - date2->month;
    } else {
        return date1->day - date2->day;
    }
}

char* date_to_string(Date* date) {
    char* date_str = (char*)malloc(MAX_DATE_LEN);
    sprintf(date_str, "%04d-%02d-%02d", date->year, date->month, date->day);
    return date_str;
}

Date* date_from_string(char* date_str) {
    int year, month, day;
    sscanf(date_str, "%04d-%02d-%02d", &year, &month, &day);
    return date_create(year, month, day);
}

int main() {
    Date* date1 = date_create(2023, 4, 25);
    Date* date2 = date_create(2023, 5, 1);

    printf("Date 1: %s\n", date_to_string(date1));
    printf("Date 2: %s\n", date_to_string(date2));

    int comparison = date_compare(date1, date2);
    if (comparison < 0) {
        printf("Date 1 is earlier than Date 2\n");
    } else if (comparison > 0) {
        printf("Date 1 is later than Date 2\n");
    } else {
        printf("Date 1 is the same as Date 2\n");
    }

    date_destroy(date1);
    date_destroy(date2);

    return 0;
}