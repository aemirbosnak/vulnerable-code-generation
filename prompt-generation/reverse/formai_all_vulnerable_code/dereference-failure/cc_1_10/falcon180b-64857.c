//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char* month;
    int day;
    int year;
} Date;

Date* parseDate(const char* input) {
    Date* date = malloc(sizeof(Date));
    date->month = NULL;
    date->day = 0;
    date->year = 0;

    const char* monthStart = input;
    const char* dayStart = NULL;
    const char* yearStart = NULL;

    for (int i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            if (date->month == NULL) {
                date->month = malloc(MAX_STRING_LENGTH);
                strcpy(date->month, "");
                dayStart = &input[i];
            }
            strcat(date->month, tolower(input[i]));
        } else if (isdigit(input[i])) {
            if (date->day == 0 && dayStart!= NULL) {
                date->day = input[i] - '0';
                dayStart = NULL;
            } else if (date->year == 0 && yearStart!= NULL) {
                date->year = input[i] - '0';
                yearStart = NULL;
            }
        }
    }

    if (date->month == NULL || date->day == 0 || date->year == 0) {
        free(date->month);
        free(date);
        return NULL;
    }

    return date;
}

void printDate(const Date* date) {
    printf("%s %d, %d\n", date->month, date->day, date->year);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [date]\n", argv[0]);
        return 1;
    }

    Date* date = parseDate(argv[1]);
    if (date!= NULL) {
        printDate(date);
        free(date->month);
        free(date);
    }

    return 0;
}