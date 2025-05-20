//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATE_LEN 20
#define MAX_MONTH_LEN 10
#define MAX_DAY_LEN 10
#define MAX_YEAR_LEN 10

typedef struct {
    char month[MAX_MONTH_LEN];
    char day[MAX_DAY_LEN];
    char year[MAX_YEAR_LEN];
} Date;

Date* parseDate(char* strDate);
void printDate(Date* date);

int main() {
    char input[MAX_DATE_LEN];
    Date* date;

    printf("Enter a date in the format 'MM/DD/YYYY': ");
    fgets(input, MAX_DATE_LEN, stdin);

    date = parseDate(input);

    if (date!= NULL) {
        printf("Date: ");
        printDate(date);
    } else {
        printf("Invalid date format.\n");
    }

    return 0;
}

Date* parseDate(char* strDate) {
    char* token;
    Date* date = malloc(sizeof(Date));

    if (date == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    token = strtok(strDate, "/");
    strncpy(date->month, token, MAX_MONTH_LEN);

    token = strtok(NULL, "/");
    strncpy(date->day, token, MAX_DAY_LEN);

    token = strtok(NULL, "/");
    strncpy(date->year, token, MAX_YEAR_LEN);

    if (strlen(date->month)!= 2 || strlen(date->day)!= 2 || strlen(date->year)!= 4) {
        printf("Invalid date format.\n");
        free(date);
        return NULL;
    }

    return date;
}

void printDate(Date* date) {
    printf("%s/%s/%s\n", date->month, date->day, date->year);
}