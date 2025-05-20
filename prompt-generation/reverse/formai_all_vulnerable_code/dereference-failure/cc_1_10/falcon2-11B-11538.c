//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE_LENGTH 100
#define MAX_MONTH_LENGTH 30
#define MAX_DAY_LENGTH 30

typedef struct {
    char* month;
    int day;
    int year;
} CalendarDate;

char* monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

CalendarDate naturalLanguageToCalendarDate(char* naturalLanguageDate) {
    CalendarDate date;
    date.month = &monthNames[0];
    date.day = 0;
    date.year = 0;

    char* monthStr = strtok(naturalLanguageDate, " ");
    if (monthStr!= NULL && strcmp(monthStr, "th")!= 0) {
        date.month = monthStr;
        monthStr = strtok(NULL, " ");
    }

    while (monthStr!= NULL && strlen(monthStr) < MAX_MONTH_LENGTH) {
        monthStr = strtok(NULL, " ");
    }

    date.month = monthStr;
    monthStr = strtok(NULL, " ");

    while (monthStr!= NULL && strlen(monthStr) < MAX_DAY_LENGTH) {
        date.day = atoi(monthStr);
        monthStr = strtok(NULL, " ");
    }

    if (monthStr!= NULL && strlen(monthStr) < MAX_DATE_LENGTH) {
        date.year = atoi(monthStr);
    }

    return date;
}

int main() {
    char* naturalLanguageDate = "April 12th, 2022";
    CalendarDate date = naturalLanguageToCalendarDate(naturalLanguageDate);

    printf("Month: %s\n", date.month);
    printf("Day: %d\n", date.day);
    printf("Year: %d\n", date.year);

    return 0;
}