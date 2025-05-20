//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LINUS_DAYS_IN_YEAR 365
#define LINUS_DAYS_IN_MONTHS 30
#define LINUS_MONTHS_IN_YEAR 12

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <day> <month>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int day = atoi(argv[1]);
    int month = atoi(argv[2]);

    if (day < 1 || day > LINUS_DAYS_IN_MONTHS) {
        fprintf(stderr, "Invalid day: %d\n", day);
        return EXIT_FAILURE;
    }

    if (month < 1 || month > LINUS_MONTHS_IN_YEAR) {
        fprintf(stderr, "Invalid month: %d\n", month);
        return EXIT_FAILURE;
    }

    // Convert day and month to the Linus calendar
    int linus_day = day;
    int linus_month = month;

    // Calculate the number of days since the start of the year
    int days_since_start_of_year = (linus_month - 1) * LINUS_DAYS_IN_MONTHS + linus_day;

    // Calculate the number of days left in the year
    int days_left_in_year = LINUS_DAYS_IN_YEAR - days_since_start_of_year;

    // Convert the number of days since the start of the year to a date in the Linus calendar
    int linus_year = 1;
    while (days_since_start_of_year > LINUS_DAYS_IN_YEAR) {
        days_since_start_of_year -= LINUS_DAYS_IN_YEAR;
        linus_year++;
    }

    // Convert the number of days left in the year to a date in the Linus calendar
    int linus_days_left = days_left_in_year;
    int linus_months_left = 0;
    while (linus_days_left > LINUS_DAYS_IN_MONTHS) {
        linus_days_left -= LINUS_DAYS_IN_MONTHS;
        linus_months_left++;
    }

    // Print the date in the Linus calendar
    printf("Linus date: %d-%d-%d\n", linus_year, linus_months_left, linus_days_left);

    return EXIT_SUCCESS;
}