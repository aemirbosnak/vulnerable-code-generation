//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

void convert(char *inputDate) {
    Date date;
    int day, month, year, leapYear;
    char monthName[13][3] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

    // Parse day
    day = atoi(strtok(inputDate, " "));

    // Parse month
    month = -1;
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(monthName[i], strtok(NULL, " ")) == 0) {
            month = i + 1;
            break;
        }
    }

    // Parse year
    year = atoi(strtok(NULL, " "));

    // Check for leap year
    if (year % 4 == 0) {
        leapYear = 1;

        if (year % 100 == 0) {
            if (year % 400 == 0) {
                leapYear = 1;
            } else {
                leapYear = 0;
            }
        } else {
            leapYear = 1;
        }
    } else {
        leapYear = 0;
    }

    // Calculate day of the year
    int daysInMonth[] = {31, (leapYear ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOfYear = day;

    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];
    }

    // Set date fields
    date.day = day;
    date.month = month;
    date.year = year;

    // Print result
    printf("Date: %d/%d/%d\n", date.day, date.month, date.year);
    printf("Day of the year: %d\n", dayOfYear);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <date in MM DD YYYY>\n", argv[0]);
        return 1;
    }

    convert(argv[1]);

    return 0;
}