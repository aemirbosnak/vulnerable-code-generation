//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int days_in_month(int year, int month);
int is_leap_year(int year);
int convert_to_days(int year, int month, int day);
void convert_to_date(int days, int *year, int *month, int *day);

int main() {
    char date[11];
    int year, month, day;
    
    printf("Enter a date in format dd-mm-yyyy: ");
    scanf("%s", date);
    
    char *token = strtok(date, "-");
    day = atoi(token);
    token = strtok(NULL, "-");
    month = atoi(token);
    token = strtok(NULL, "-");
    year = atoi(token);
    
    int days = convert_to_days(year, month, day);
    
    printf("Number of days since Jan 1, 0001: %d\n", days);
    
    int new_year, new_month, new_day;
    
    convert_to_date(days, &new_year, &new_month, &new_day);
    
    printf("Converted date: %d-%02d-%02d\n", new_day, new_month, new_year);
    
    return 0;
}

int days_in_month(int year, int month) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int is_leap_year(int year) {
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

int convert_to_days(int year, int month, int day) {
    int total_days = 0;
    
    for (int i = 1; i < year; i++) {
        if (is_leap_year(i)) {
            total_days += 366;
        }
        else {
            total_days += 365;
        }
    }
    
    for (int i = 1; i < month; i++) {
        total_days += days_in_month(year, i);
    }
    
    total_days += day;
    
    return total_days;
}

void convert_to_date(int days, int *year, int *month, int *day) {
    int current_year = 1;
    int days_in_current_year;
    
    while (days > 0) {
        if (is_leap_year(current_year)) {
            days_in_current_year = 366;
        }
        else {
            days_in_current_year = 365;
        }
        
        if (days > days_in_current_year) {
            days -= days_in_current_year;
            current_year++;
        }
        else {
            break;
        }
    }
    
    *year = current_year;
    
    int current_month = 1;
    
    while (days > days_in_month(current_year, current_month)) {
        days -= days_in_month(current_year, current_month);
        current_month++;
    }
    
    *month = current_month;
    *day = days;
}