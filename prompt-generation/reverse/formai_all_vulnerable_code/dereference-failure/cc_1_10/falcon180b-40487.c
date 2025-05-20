//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_STRING_SIZE 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char* weekday;
    char* month;
    char* day;
    char* year;
} DateString;

DateString* dateToString(Date date) {
    DateString* result = malloc(sizeof(DateString));
    result->weekday = malloc(MAX_STRING_SIZE);
    result->month = malloc(MAX_STRING_SIZE);
    result->day = malloc(MAX_STRING_SIZE);
    result->year = malloc(MAX_STRING_SIZE);

    strftime(result->weekday, MAX_STRING_SIZE, "%A", localtime(&date.day));
    strftime(result->month, MAX_STRING_SIZE, "%B", localtime(&date.day));
    strftime(result->day, MAX_STRING_SIZE, "%d", localtime(&date.day));
    strftime(result->year, MAX_STRING_SIZE, "%Y", localtime(&date.day));

    return result;
}

Date* stringToDate(char* input) {
    Date* result = malloc(sizeof(Date));
    char* token = strtok(input, " ");

    if (token == NULL) {
        printf("Invalid format\n");
        exit(1);
    }

    result->day = atoi(token);
    result->month = atoi(strtok(NULL, " "));
    result->year = atoi(strtok(NULL, " "));

    if (result->month < 1 || result->month > 12) {
        printf("Invalid month\n");
        exit(1);
    }

    if (result->day < 1 || result->day > 31) {
        printf("Invalid day\n");
        exit(1);
    }

    if (result->year < 1000 || result->year > 9999) {
        printf("Invalid year\n");
        exit(1);
    }

    return result;
}

int main() {
    Date date;
    DateString* stringDate;

    printf("Enter a date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    stringDate = dateToString(date);
    printf("Date: %s, %s %d, %d\n", stringDate->weekday, stringDate->month, stringDate->day, stringDate->year);

    free(stringDate->weekday);
    free(stringDate->month);
    free(stringDate->day);
    free(stringDate->year);
    free(stringDate);

    return 0;
}