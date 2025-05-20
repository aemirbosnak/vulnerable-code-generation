//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} TimeStamp;

void printCurrentTime(TimeStamp time) {
    printf("Current Time: %04d-%02d-%02d %02d:%02d\n",
           time.year, time.month, time.day, time.hour, time.minute);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

void travelTime(TimeStamp *time, int years, int months, int days, int hours, int minutes) {
    // Adjust minutes
    time->minute += minutes;
    if (time->minute >= 60) {
        time->minute -= 60;
        time->hour++;
    }

    // Adjust hours
    time->hour += hours;
    if (time->hour >= 24) {
        time->hour -= 24;
        time->day++;
    }

    // Adjust days
    time->day += days;
    while (time->day > getDaysInMonth(time->year, time->month)) {
        time->day -= getDaysInMonth(time->year, time->month);
        time->month++;
        if (time->month > 12) {
            time->month = 1;
            time->year++;
        }
    }

    // Adjust months
    time->month += months;
    while (time->month > 12) {
        time->month -= 12;
        time->year++;
    }

    // Adjust years
    time->year += years;
}

void simulateTimeTravel(TimeStamp *time, int choice) {
    int years, months, days, hours, minutes;
    switch (choice) {
        case 1: // Travel into the past
            printf("Enter number of years/months/days/hours/minutes to travel back:\n");
            printf("Years: "); scanf("%d", &years);
            printf("Months: "); scanf("%d", &months);
            printf("Days: "); scanf("%d", &days);
            printf("Hours: "); scanf("%d", &hours);
            printf("Minutes: "); scanf("%d", &minutes);
            years = -years; months = -months; days = -days; hours = -hours; minutes = -minutes;
            break;
        case 2: // Travel into the future
            printf("Enter number of years/months/days/hours/minutes to travel forward:\n");
            printf("Years: "); scanf("%d", &years);
            printf("Months: "); scanf("%d", &months);
            printf("Days: "); scanf("%d", &days);
            printf("Hours: "); scanf("%d", &hours);
            printf("Minutes: "); scanf("%d", &minutes);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    travelTime(time, years, months, days, hours, minutes);
}

int main() {
    TimeStamp currentTime;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    currentTime.year = tm->tm_year + 1900;
    currentTime.month = tm->tm_mon + 1; // tm_mon is 0-11
    currentTime.day = tm->tm_mday;
    currentTime.hour = tm->tm_hour;
    currentTime.minute = tm->tm_min;

    int option;
    do {
        printf("******** Time Travel Simulator ********\n");
        printCurrentTime(currentTime);
        printf("Choose an option:\n");
        printf("1. Travel back in time\n");
        printf("2. Travel forward in time\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        if (option == 1 || option == 2) {
            simulateTimeTravel(&currentTime, option);
        }
    } while (option != 3);

    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}