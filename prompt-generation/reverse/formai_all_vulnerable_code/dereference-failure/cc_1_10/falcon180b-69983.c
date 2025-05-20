//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main() {
    Date date;
    char input[100];
    char* token;
    int i = 0;
    int day = 0, month = 0, year = 0;

    // Prompt user to enter a date
    printf("Enter a date in the format 'DD/MM/YYYY': ");
    fgets(input, sizeof(input), stdin);

    // Parse input into day, month and year
    token = strtok(input, "/");
    day = atoi(token);
    token = strtok(NULL, "/");
    month = atoi(token);
    token = strtok(NULL, "/");
    year = atoi(token);

    // Validate input
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2099) {
        printf("Invalid date.\n");
        return 1;
    }

    // Convert day, month and year to a Date struct
    date.day = day;
    date.month = month;
    date.year = year;

    // Convert Date struct to a string in the format 'DD/MM/YYYY'
    printf("The entered date is: %d/%d/%d\n", date.day, date.month, date.year);

    // Convert Date struct to a string in the format 'DD-MM-YYYY'
    printf("The entered date is: %d-%d-%d\n", date.day, date.month, date.year);

    // Convert Date struct to a string in the format 'DD MMM YYYY'
    printf("The entered date is: %d %s %d\n", date.day, months[date.month-1], date.year);

    // Convert Date struct to a string in the format 'MMM DD, YYYY'
    printf("The entered date is: %s %d, %d\n", months[date.month-1], date.day, date.year);

    // Convert Date struct to a string in the format 'DD/MM/YYYY HH:MM:SS'
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    printf("The entered date and time is: %d/%d/%d %d:%d:%d\n", date.day, date.month, date.year, t->tm_hour, t->tm_min, t->tm_sec);

    return 0;
}