//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* date_create(int year, int month, int day) {
    Date* date = malloc(sizeof(Date));
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
    char* buffer = malloc(11);
    sprintf(buffer, "%04d-%02d-%02d", date->year, date->month, date->day);
    return buffer;
}

Date* date_from_string(char* string) {
    int year, month, day;
    sscanf(string, "%04d-%02d-%02d", &year, &month, &day);
    return date_create(year, month, day);
}

int main() {
    Date* date1 = date_create(2020, 1, 1);
    Date* date2 = date_create(2020, 2, 1);

    int comparison = date_compare(date1, date2);
    printf("Comparison: %d\n", comparison);

    char* string = date_to_string(date1);
    printf("String: %s\n", string);

    Date* date3 = date_from_string(string);
    printf("Date from string: %s\n", date_to_string(date3));

    date_destroy(date1);
    date_destroy(date2);
    date_destroy(date3);

    free(string);

    return 0;
}