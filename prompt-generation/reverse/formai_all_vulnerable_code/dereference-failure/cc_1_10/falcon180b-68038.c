//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_DATE_LENGTH 50
#define MAX_MONTH_LENGTH 50
#define MAX_YEAR_LENGTH 50
#define MAX_DAY_LENGTH 50

typedef struct {
    char day[MAX_DAY_LENGTH];
    char month[MAX_MONTH_LENGTH];
    char year[MAX_YEAR_LENGTH];
} Date;

void date_to_string(Date* date, char* str) {
    strcpy(str, date->month);
    strcat(str, " ");
    strcat(str, date->day);
    strcat(str, ", ");
    strcat(str, date->year);
}

int string_to_date(char* str, Date* date) {
    char* token = strtok(str, ", ");
    strcpy(date->month, token);
    token = strtok(NULL, ", ");
    strcpy(date->day, token);
    token = strtok(NULL, ", ");
    strcpy(date->year, token);
    return 0;
}

int is_valid_date(Date* date) {
    int month, day, year;
    if (sscanf(date->month, "%d", &month)!= 1 ||
        sscanf(date->day, "%d", &day)!= 1 ||
        sscanf(date->year, "%d", &year)!= 1) {
        return 0;
    }
    if (month < 1 || month > 12) {
        return 0;
    }
    if (day < 1 || day > 31) {
        return 0;
    }
    if (year < 1000 || year > 9999) {
        return 0;
    }
    return 1;
}

int main() {
    Date date;
    char input[MAX_DATE_LENGTH];
    printf("Enter a date in the format 'Month Day, Year':\n");
    scanf("%s", input);
    string_to_date(input, &date);
    if (!is_valid_date(&date)) {
        printf("Invalid date\n");
        return 1;
    }
    printf("Your date in words:\n");
    date_to_string(&date, input);
    printf("%s\n", input);
    return 0;
}