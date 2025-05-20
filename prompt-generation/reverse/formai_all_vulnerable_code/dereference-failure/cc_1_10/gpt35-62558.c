//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: realistic
#include<stdio.h>
#include<string.h>

// Function to check if the given year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to convert month name to its corresponding integer value
int getMonthNumber(char* monthName) {
    // List of all months along with their corresponding integer values
    char* months[] = {"january", "february", "march", "april", "may", "june",
                      "july", "august", "september", "october", "november", "december"};
    int monthNumber;
    for (int i = 0; i < 12; i++) {
        if (strcmp(monthName, months[i]) == 0) {
            monthNumber = i + 1;
            break;
        }
    }
    return monthNumber;
}

// Function to convert date in natural language to its corresponding integer value
void convertNaturalDate(char* inputDate) {
    // Extracting day, month and year from input date string
    char* day = strtok(inputDate, " ");
    char* month = strtok(NULL, " ");
    char* year = strtok(NULL, " ");

    // Converting month name to its corresponding integer value
    int monthNumber = getMonthNumber(month);

    // Converting day, month and year strings to integers
    int dayNumber = atoi(day);
    int yearNumber = atoi(year);

    // Checking if the given year is a leap year
    int isLeap = isLeapYear(yearNumber);

    // Initializing the days in each month
    int daysInMonth[] = {31, isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Calculating the total number of days from 1st January to the given date
    int totalDays = 0;
    for (int i = 0; i < monthNumber - 1; i++) {
        totalDays += daysInMonth[i];
    }
    totalDays += dayNumber;

    // Printing the output
    printf("%d-%02d-%02d", yearNumber, monthNumber, dayNumber);
}

int main() {
    // Taking input in natural language
    char inputDate[50];
    fgets(inputDate, 50, stdin);

    // Calling the function to convert natural language date to its integer value
    convertNaturalDate(inputDate);

    return 0;
}