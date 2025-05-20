//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>

// Define the struct for holding date values
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Array to hold the month names
const char *MONTH_NAMES[] = {
    "",
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

// Function to convert a date string to a Date struct
Date stringToDate(char *dateString) {
    Date date;
    sscanf(dateString, "%d/%d/%d", &date.day, &date.month, &date.year);
    return date;
}

// Function to convert a Date struct to a string
char *dateToString(Date date) {
    char *dateString = malloc(sizeof(char) * 12);
    sprintf(dateString, "%02d/%02d/%04d", date.day, date.month, date.year);
    return dateString;
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int daysInMonth(int month, int year) {
    switch (month) {
        case 2:
            if (isLeapYear(year)) {
                return 29;
            } else {
                return 28;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

// Function to add days to a date
Date addDays(Date date, int daysToAdd) {
    // Loop through and add days one by one
    for (int i = 0; i < daysToAdd; i++) {
        // Get the number of days in the current month
        int daysInCurrentMonth = daysInMonth(date.month, date.year);
        
        // Increment the day by one
        date.day++;
        
        // If we've gone past the end of the month, reset the day to 1 and increment the month
        if (date.day > daysInCurrentMonth) {
            date.day = 1;
            date.month++;
            
            // If we've gone past December, reset the month to January and increment the year
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
    }
    
    return date;
}

int main() {
    // Get the input date
    printf("Enter date in dd/mm/yyyy format: ");
    char dateString[11];
    scanf("%s", dateString);
    Date date = stringToDate(dateString);
    
    // Get the number of days to add
    printf("Enter number of days to add: ");
    int daysToAdd;
    scanf("%d", &daysToAdd);
    
    // Add the days to the date
    Date newDate = addDays(date, daysToAdd);
    
    // Print out the original date and the new date
    printf("Starting date: %s (%s)\n", dateString, MONTH_NAMES[date.month]);
    printf("New date: %s (%s)\n", dateToString(newDate), MONTH_NAMES[newDate.month]);
    
    return 0;
}