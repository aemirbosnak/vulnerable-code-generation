//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define month name array
const char *monthNames[13] = {"", "January", "February", "March", "April", "May", "June", 
                              "July", "August", "September", "October", "November", "December"};

// Function to check if the year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

// Function to calculate the number of days in a month
int getDaysInMonth(int month, int year) {
    if (month == 2) {
        if (isLeapYear(year))
            return 29;
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}

// Main function
int main() {
    int day, month, year, daysInMonth, totalDays = 0, i;

    // Take input in the format Day Month, Year (e.g. 23 March, 2022)
    printf("Enter date in the format Day Month, Year: ");
    scanf("%d %*c %s %*c %d", &day, &monthNames[0], &year);

    // Convert month name to integer value
    for (i = 1; i <= 12; i++) {
        if (strcmp(monthNames[0], monthNames[i]) == 0) {
            month = i;
            break;
        }
    }

    // Calculate the number of days in the given year until the month
    for (i = 1; i < month; i++) {
        daysInMonth = getDaysInMonth(i, year);
        totalDays += daysInMonth;
    }

    // Add the number of days in the given month to the total
    daysInMonth = getDaysInMonth(month, year);
    totalDays += day;

    // Print the output in the format Day Month Year (e.g. 83 March 2022)
    printf("The date in natural language format is: %d %s %d\n", totalDays, monthNames[month], year);

    return 0;
}