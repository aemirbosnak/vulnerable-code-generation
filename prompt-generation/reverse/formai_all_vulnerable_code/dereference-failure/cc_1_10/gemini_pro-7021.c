//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date *parse_date(char *str) {
    Date *date = malloc(sizeof(Date));
    if (!date) {
        return NULL;
    }

    int year = atoi(strtok(str, "-"));
    int month = atoi(strtok(NULL, "-"));
    int day = atoi(strtok(NULL, "-"));

    date->year = year;
    date->month = month;
    date->day = day;

    return date;
}

char *format_date(Date *date) {
    char *str = malloc(11);
    if (!str) {
        return NULL;
    }

    sprintf(str, "%04d-%02d-%02d", date->year, date->month, date->day);

    return str;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <date>\n", argv[0]);
        return 1;
    }

    Date *date = parse_date(argv[1]);
    if (!date) {
        printf("Invalid date: %s\n", argv[1]);
        return 1;
    }

    char *formatted_date = format_date(date);
    printf("Formatted date: %s\n", formatted_date);

    free(date);
    free(formatted_date);
    return 0;
}