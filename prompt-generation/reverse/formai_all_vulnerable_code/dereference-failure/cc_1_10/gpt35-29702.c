//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int year;
    int month;
    int day;
};

// Function to check whether a given year is a leap year or not
int isLeapYear(int year) {
    // Leap year occurs every 4 years except for year divisible by 100,
    // but is still a leap year if divisible by 400
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int days;

    switch(month) {
        case 2:
            if(isLeapYear(year))
                days = 29;
            else
                days = 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
    }

    return days;
}

// Function to convert a date string into a Date struct
struct Date convertDate(char dateStr[]) {
    struct Date date;
    char *token;
    const char delimiter[2] = "-";

    // Parse date string and store into Date struct
    token = strtok(dateStr, delimiter);
    date.year = atoi(token);
    token = strtok(NULL, delimiter);
    date.month = atoi(token);
    token = strtok(NULL, delimiter);
    date.day = atoi(token);

    return date;
}

// Function to convert a Date struct into a date string
char* formatDate(struct Date date) {
    char *dateStr = malloc(sizeof(char) * 11);

    // Format Date struct into date string
    sprintf(dateStr, "%d-%02d-%02d", date.year, date.month, date.day);

    return dateStr;
}

// Function to add or subtract days to a given Date struct
struct Date addDays(struct Date date, int days) {
    // Get number of days in given month
    int daysInMonth = getDaysInMonth(date.month, date.year);

    // Add/subtract days to date day
    date.day += days;

    // Handle edge cases
    if(date.day > daysInMonth) {
        date.month++;
        date.day -= daysInMonth;
        if(date.month > 12) {
            date.year++;
            date.month -= 12;
        }
    } else if(date.day < 1) {
        date.month--;
        if(date.month < 1) {
            date.year--;
            date.month += 12;
        }
        date.day += getDaysInMonth(date.month, date.year);
    }

    return date;
}

int main() {
    char dateStr[11];
    int offset;
    struct Date date;

    // Input date string from user
    printf("Enter a date (yyyy-mm-dd): ");
    scanf("%s", dateStr);

    // Convert date string to Date struct
    date = convertDate(dateStr);

    // Input offset from user
    printf("Enter an offset (positive or negative integer): ");
    scanf("%d", &offset);

    // Add/subtract offset days to date
    date = addDays(date, offset);

    // Print new date
    printf("New date: %s\n", formatDate(date));

    return 0;
}