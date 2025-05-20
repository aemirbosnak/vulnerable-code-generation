//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 20

typedef struct {
    char *month;
    char *day;
    char *year;
} Date;

Date* createDate(char *dateString);
void printDate(Date *date);

int main() {
    char input[MAX_DATE_LENGTH];

    printf("Enter a date in 'MM/DD/YYYY' format: ");
    scanf("%s", input);

    Date *date = createDate(input);

    printf("Original date: ");
    printDate(date);

    free(date->month);
    free(date->day);
    free(date->year);
    free(date);

    return 0;
}

Date* createDate(char *dateString) {
    Date *date = malloc(sizeof(Date));

    char *month = strtok(dateString, "/");
    char *day = strtok(NULL, "/");
    char *year = strtok(NULL, "/");

    date->month = strdup(month);
    date->day = strdup(day);
    date->year = strdup(year);

    return date;
}

void printDate(Date *date) {
    printf("%s %s, %s\n", date->month, date->day, date->year);
}