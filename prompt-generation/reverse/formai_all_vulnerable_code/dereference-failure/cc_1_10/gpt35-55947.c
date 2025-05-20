//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int daysInMonth(int month, int year) {
    switch(month) {
        case 2:
            if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                return 29;
            else
                return 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Current date: %02d/%02d/%04d\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
    
    int month, day, year;
    printf("Enter a date (MM/DD/YYYY): ");
    scanf("%d/%d/%d", &month, &day, &year);
    
    if(month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }
    
    if(day < 1 || day > daysInMonth(month, year)) {
        printf("Invalid day.\n");
        return 1;
    }
    
    if(year < 1) {
        printf("Invalid year.\n");
        return 1;
    }
    
    int days = 0;
    
    for(int i = 1; i < month; i++)
        days += daysInMonth(i, year);
    
    days = days + day;
    
    for(int i = 1; i < year; i++)
        if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            days += 366;
        else
            days += 365;
    
    printf("The date %02d/%02d/%04d is the %dth day of the year.\n", month, day, year, days);
    
    return 0;
}