//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date* create_date(int year, int month, int day) {
    Date* date = malloc(sizeof(Date));
    date->year = year;
    date->month = month;
    date->day = day;
    return date;
}

void destroy_date(Date* date) {
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

Date* string_to_date(char* string) {
    int year, month, day;
    sscanf(string, "%04d-%02d-%02d", &year, &month, &day);
    return create_date(year, month, day);
}

int main() {
    Date* date1 = create_date(2020, 12, 31);
    Date* date2 = create_date(2021, 1, 1);
    printf("Date1: %s\n", date_to_string(date1));
    printf("Date2: %s\n", date_to_string(date2));
    int comparison = date_compare(date1, date2);
    printf("Comparison: %d\n", comparison);
    destroy_date(date1);
    destroy_date(date2);
    return 0;
}