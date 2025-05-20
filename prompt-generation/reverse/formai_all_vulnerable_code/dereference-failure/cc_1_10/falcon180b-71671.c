//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100
#define MONTHS 12
#define DAYS 31

enum {
    January = 0,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

char *months[MONTHS] = {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

char *weekdays[7] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};

void print_date(int day, int month, int year) {
    char date[MAX_LENGTH];

    if (day < 10) {
        sprintf(date, "0%d", day);
    } else {
        sprintf(date, "%d", day);
    }

    if (month < 10) {
        sprintf(date + strlen(date), "/0%d", month);
    } else {
        sprintf(date + strlen(date), "/%d", month);
    }

    if (year < 10) {
        sprintf(date + strlen(date), "/0%d", year);
    } else {
        sprintf(date + strlen(date), "/%d", year);
    }

    printf("%s\n", date);
}

int main(void) {
    char input[MAX_LENGTH];
    char *token;
    int day, month, year;

    printf("Enter a date in the format of dd/mm/yyyy: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove leading/trailing whitespace
    input[strcspn(input, "\n")] = '\0';

    // Tokenize input
    token = strtok(input, "/");
    day = atoi(token);

    token = strtok(NULL, "/");
    month = atoi(token);

    token = strtok(NULL, "/");
    year = atoi(token);

    // Validate input
    if (day < 1 || day > DAYS ||
        month < 1 || month > MONTHS ||
        year < 1900 || year > 9999) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert to natural language format
    print_date(day, month, year);

    return 0;
}