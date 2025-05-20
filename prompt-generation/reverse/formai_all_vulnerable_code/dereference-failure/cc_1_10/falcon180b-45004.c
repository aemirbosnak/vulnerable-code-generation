//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char* month;
    char* day;
    char* year;
} Date;

void convert_date(Date* date) {
    setlocale(LC_ALL, "en_US.UTF-8");
    strftime(date->month, MAX_LENGTH, "%B", date->day);
    strftime(date->day, MAX_LENGTH, "%d", date->year);
    strftime(date->year, MAX_LENGTH, "%Y", date->year);
}

int main() {
    Date date;
    char input[MAX_LENGTH];
    char* month;
    char* day;
    char* year;

    printf("Enter a date in the format 'Month Day, Year': ");
    fgets(input, MAX_LENGTH, stdin);

    // Extract month, day, and year from input
    month = strtok(input, ",");
    day = strtok(NULL, ",");
    year = strtok(NULL, ",");

    // Validate input
    if (month == NULL || day == NULL || year == NULL) {
        printf("Invalid input format\n");
        return 1;
    }

    // Convert input to Date struct
    strcpy(date.month, month);
    strcpy(date.day, day);
    strcpy(date.year, year);

    // Convert month to abbreviated form
    char* month_abbr = strtok(date.month, " ");

    // Validate month
    if (month_abbr == NULL || strlen(month_abbr)!= 3) {
        printf("Invalid month\n");
        return 1;
    }

    // Convert day and year to integers
    int day_int = atoi(date.day);
    int year_int = atoi(date.year);

    // Validate day and year
    if (day_int < 1 || day_int > 31 || year_int < 1000 || year_int > 9999) {
        printf("Invalid date\n");
        return 1;
    }

    // Convert date to natural language format
    convert_date(&date);

    printf("Natural language date: %s %s, %s\n", date.month, date.day, date.year);

    return 0;
}