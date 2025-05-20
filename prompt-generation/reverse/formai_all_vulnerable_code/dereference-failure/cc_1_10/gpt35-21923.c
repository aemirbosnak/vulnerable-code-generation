//FormAI DATASET v1.0 Category: Date and time ; Style: recursive
#include <stdio.h>
#include <time.h>

void printTime(int hour, int minute, int second) {
    printf("The time is %02d:%02d:%02d\n", hour, minute, second);
    if (hour == 23 && minute == 59 && second == 59) {
        printf("Happy New Year!\n");
        return;
    }
    if (second == 59) {
        if (minute == 59) {
            printTime(hour + 1, 0, 0);
        } else {
            printTime(hour, minute + 1, 0);
        }
    } else {
        printTime(hour, minute, second + 1);
    }
}

void printDate(int year, int month, int day) {
    printf("The date is %04d/%02d/%02d\n", year, month, day);
    if (year == 9999 && month == 12 && day == 31) {
        printf("The calendar ends here :(\n");
        return;
    }
    int daysInMonth;
    switch (month) {
        case 2:
            daysInMonth = (year % 4) == 0 ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            daysInMonth = 30;
            break;
        default:
            daysInMonth = 31;
    }
    if (day == daysInMonth) {
        if (month == 12) {
            printDate(year + 1, 1, 1);
        } else {
            printDate(year, month + 1, 1);
        }
    } else {
        printDate(year, month, day + 1);
    }
}

int main() {
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);
    int currentHour = currentTime->tm_hour;
    int currentMinute = currentTime->tm_min;
    int currentSecond = currentTime->tm_sec;
    int currentYear = currentTime->tm_year + 1900;
    int currentMonth = currentTime->tm_mon + 1;
    int currentDay = currentTime->tm_mday;

    printf("Starting recursive clock/date:\n");
    printTime(currentHour, currentMinute, currentSecond);
    printDate(currentYear, currentMonth, currentDay);

    return 0;
}