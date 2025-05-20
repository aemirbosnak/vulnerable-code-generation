//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: visionary
#include <stdio.h>
#include <string.h>

const char *MONTHS[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

const int DAYS_IN_MONTH[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

struct Date {
    int day;
    int month;
    int year;
};

// Function to check if a given year is a leap year
int isLeapYear(int year) {
    if (year % 4 != 0) {
        return 0;
    } else if (year % 100 != 0) {
        return 1;
    } else if (year % 400 != 0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to calculate the number of days in a given month of a given year
int daysInMonth(int month, int year) {
    if (isLeapYear(year) && month == 2) {
        return 29;
    } else {
        return DAYS_IN_MONTH[month - 1];
    }
}

// Function to calculate the number of days between two dates
int daysBetweenDates(struct Date date1, struct Date date2) {
    int numDays = 0;
    int i;

    if (date1.year > date2.year || (date1.year == date2.year && date1.month > date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day > date2.day)) {
        struct Date temp = date1;
        date1 = date2;
        date2 = temp;
    }

    // Add up the days for all years between the two dates
    for (i = date1.year; i < date2.year; i++) {
        if (isLeapYear(i)) {
            numDays += 366;
        } else {
            numDays += 365;
        }
    }

    // Add up the days for all months between the two dates
    for (i = date1.month; i <= 12; i++) {
        numDays += daysInMonth(i, date1.year) - date1.day;
        date1.day = 0;
    }

    for (i = 1; i < date2.month; i++) {
        numDays += daysInMonth(i, date2.year);
    }

    // Add up the days for the final month
    numDays += date2.day;

    return numDays;
}

// Function to convert a date from natural language to a struct Date
struct Date convertDate(char *dateString) {
    struct Date date;
    char *monthString;
    char *dayString;
    char *yearString;
    int i;

    // Extract the day, month, and year from the date string
    monthString = strtok(dateString, " ");
    dayString = strtok(NULL, " ,");
    yearString = strtok(NULL, "");

    // Determine the month from the month string
    for (i = 0; i < 12; i++) {
        if (strcmp(monthString, MONTHS[i]) == 0) {
            date.month = i + 1;
            break;
        }
    }

    // Convert the day and year strings to integers
    date.day = atoi(dayString);
    date.year = atoi(yearString);

    return date;
}

int main() {
    struct Date date1;
    struct Date date2;
    char date1String[20];
    char date2String[20];
    int numDays;

    // Get the two dates from the user
    printf("Enter the first date in natural language format (e.g. January 1, 2022): ");
    fgets(date1String, 20, stdin);

    printf("Enter the second date in natural language format (e.g. January 1, 2022): ");
    fgets(date2String, 20, stdin);

    // Convert the dates to structs and calculate the number of days between them
    date1 = convertDate(date1String);
    date2 = convertDate(date2String);
    numDays = daysBetweenDates(date1, date2);

    // Print the number of days between the two dates
    printf("The number of days between %02d/%02d/%04d and %02d/%02d/%04d is %d.\n", date1.month, date1.day, date1.year, date2.month, date2.day, date2.year, numDays);

    return 0;
}