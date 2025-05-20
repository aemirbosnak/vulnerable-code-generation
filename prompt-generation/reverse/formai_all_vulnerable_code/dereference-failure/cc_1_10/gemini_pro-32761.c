//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LENGTH 11

typedef struct {
    int day;
    int month;
    int year;
} Date;

Date *parseDate(char *dateString) {
    Date *date = malloc(sizeof(Date));
    if (date == NULL) {
        return NULL;
    }

    char *dayString = strtok(dateString, "/");
    if (dayString == NULL) {
        free(date);
        return NULL;
    }

    date->day = atoi(dayString);

    char *monthString = strtok(NULL, "/");
    if (monthString == NULL) {
        free(date);
        return NULL;
    }

    date->month = atoi(monthString);

    char *yearString = strtok(NULL, "/");
    if (yearString == NULL) {
        free(date);
        return NULL;
    }

    date->year = atoi(yearString);

    return date;
}

void printDate(Date *date) {
    printf("%d/%d/%d\n", date->day, date->month, date->year);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    Date *date = parseDate(argv[1]);
    if (date == NULL) {
        printf("Invalid date format\n");
        return 1;
    }

    printDate(date);

    free(date);

    return 0;
}