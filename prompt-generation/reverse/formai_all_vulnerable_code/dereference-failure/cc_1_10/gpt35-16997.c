//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int day, month, year;
};

// Check if a given year is leap or not
int isLeapYear(int year) {
    if (year % 100 == 0) {
        if (year % 400 == 0)
            return 1;
        else
            return 0;
    }
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

// Get the number of days in a given month for a given year
int getNumDaysInMonth(int month, int year) {
    switch (month) {
        case 2:
            if (isLeapYear(year))
                return 29;
            else
                return 28;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        default:
            return 31;
    }
}

// Convert a date string to a Date struct
struct Date convertDate(char* dateStr) {
    struct Date date;
    char* token = strtok(dateStr, "-");

    date.day = atoi(token);
    token = strtok(NULL, "-");
    date.month = atoi(token);
    token = strtok(NULL, "-");
    date.year = atoi(token);

    return date;
}

// Convert a Date struct to a date string
char* convertDateToStr(struct Date date) {
    char* dateStr = (char*) malloc(sizeof(char) * 11);

    sprintf(dateStr, "%02d-%02d-%04d", date.day, date.month, date.year);

    return dateStr;
}

// Add a number of days to a Date struct
struct Date addDays(struct Date date, int numDays) {
    int daysInMonth;

    while (numDays > 0) {
        daysInMonth = getNumDaysInMonth(date.month, date.year);

        if (numDays >= daysInMonth - date.day + 1) {
            numDays -= daysInMonth - date.day + 1;
            date.day = 1;
            date.month++;

            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
        else {
            date.day += numDays;
            numDays = 0;
        }
    }

    return date;
}

int main() {
    char dateStr[11];
    int numDays;

    printf("Enter a date in the format dd-mm-yyyy: ");
    scanf("%s", dateStr);

    struct Date date = convertDate(dateStr);

    printf("Enter a number of days to add: ");
    scanf("%d", &numDays);

    date = addDays(date, numDays);

    char* newDateStr = convertDateToStr(date);

    printf("The new date is %s\n", newDateStr);

    free(newDateStr);

    return 0;
}