//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to check if a given year is a leap year or not
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            return 1;
        }
    }
    else {
        return 0;
    }
}

//Function to convert a given date into the number of days since January 1, 1900
int dateToDays(int day, int month, int year) {
    int monthDays[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = 0;
    
    for (int i = 1900; i < year; i++) {
        days += 365 + isLeapYear(i);
    }
    
    for (int i = 0; i < month - 1; i++) {
        days += monthDays[i];
    }
    
    days += day - 1;
    
    return days;
}

//Function to convert a given number of days since January 1, 1900 into a date
void daysToDate(int days, int* day, int* month, int* year) {
    int monthDays[] = {31, 28 + isLeapYear(*year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int y = 1900;
    
    while (days > 365 + isLeapYear(y)) {
        days -= 365 + isLeapYear(y);
        y++;
    }
    
    *year = y;
    
    for (int m = 0; m < 12; m++) {
        int monthLength = monthDays[m];
        
        if (m == 1 && isLeapYear(*year)) {
            monthLength++;
        }
        
        if (days >= monthLength) {
            days -= monthLength;
        }
        else {
            *month = m + 1;
            *day = days + 1;
            break;
        }
    }
}

//Main function to execute the program
int main() {
    char date[11];
    printf("Enter a date (in the format dd/mm/yyyy): ");
    scanf("%s", date);
    
    char* dayStr = strtok(date, "/");
    char* monthStr = strtok(NULL, "/");
    char* yearStr = strtok(NULL, "/");
    
    int day = atoi(dayStr);
    int month = atoi(monthStr);
    int year = atoi(yearStr);
    
    //Checking for invalid inputs
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year <= 0) {
        printf("Invalid input!\n");
        return 0;
    }
    
    //Checking for February 29 on a non-leap year
    if (month == 2 && day == 29 && !isLeapYear(year)) {
        printf("Invalid input!\n");
        return 0;
    }
    
    //Converting the input date to days since January 1, 1900
    int days = dateToDays(day, month, year);
    
    //Converting the days since January 1, 1900 to a date
    daysToDate(days, &day, &month, &year);
    
    //Printing the output
    printf("%02d/%02d/%04d is %d days since January 1, 1900.\n", day, month, year, days);
    
    return 0;
}