//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
    int day;
    int month;
    int year;
};

void convertDate(struct date *d) {
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d->year % 4 == 0) {
        daysInMonth[1] = 29;
    }

    int dayOfYear = 0;

    for (int i = 0; i < d->month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    dayOfYear += d->day;

    printf("The day of the year is %d\n", dayOfYear);
}

int main() {
    struct date d;

    printf("Welcome to the DateConverter game!\n");

    while (1) {
        printf("Enter a date in the following format: DD.MM.YYYY or type q to quit: ");
        char input[11];
        fgets(input, 11, stdin);

        if (strcmp(input, "q\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        char *pEnd;
        d.day = strtol(input, &pEnd, 10);
        d.month = strtol(pEnd + 1, &pEnd, 10);
        d.year = strtol(pEnd + 1, NULL, 10);

        if (d.day < 1 || d.day > 31 || d.month < 1 || d.month > 12 || d.year < 0) {
            printf("Invalid input, please try again.\n");
            continue;
        }

        convertDate(&d);
    }

    return 0;
}