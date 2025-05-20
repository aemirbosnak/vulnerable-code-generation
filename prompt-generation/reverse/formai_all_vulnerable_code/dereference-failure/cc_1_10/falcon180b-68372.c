//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_YEAR 9999
#define MAX_MONTH 12
#define MAX_DAY 31

typedef struct {
    int year;
    int month;
    int day;
} Date;

Date currentDate;

void setCurrentDate() {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    currentDate.year = tm->tm_year + 1900;
    currentDate.month = tm->tm_mon + 1;
    currentDate.day = tm->tm_mday;
}

int isValidDate(int year, int month, int day) {
    if (year < 1 || year > MAX_YEAR) {
        return false;
    }

    if (month < 1 || month > MAX_MONTH) {
        return false;
    }

    if (day < 1 || day > MAX_DAY) {
        return false;
    }

    return true;
}

void printDate(Date date) {
    printf("%d-%d-%d\n", date.year, date.month, date.day);
}

int main() {
    setCurrentDate();
    printf("Current date: ");
    printDate(currentDate);

    int targetYear, targetMonth, targetDay;
    printf("Enter target date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &targetYear, &targetMonth, &targetDay);

    if (!isValidDate(targetYear, targetMonth, targetDay)) {
        printf("Invalid date.\n");
        return 1;
    }

    int deltaYear = targetYear - currentDate.year;
    int deltaMonth = targetMonth - currentDate.month;
    int deltaDay = targetDay - currentDate.day;

    if (deltaYear < 0) {
        printf("You cannot travel back in time.\n");
        return 1;
    }

    if (deltaMonth < 0) {
        deltaYear--;
        deltaMonth += 12;
    }

    if (deltaDay < 0) {
        deltaMonth--;
        deltaDay += (deltaMonth == 0? 12 : (deltaMonth - 1) * 31);
    }

    int totalDays = (deltaYear * 365) + ((deltaYear / 4) * 366) - ((deltaYear / 100) * 365) + ((deltaYear / 400) * 366);
    totalDays += (deltaMonth * 30) + deltaDay;

    printf("Traveling forward in time...\n");
    for (int i = 1; i <= totalDays; i++) {
        setCurrentDate();
        if (currentDate.year == targetYear && currentDate.month == targetMonth && currentDate.day == targetDay) {
            printf("You have arrived at your destination.\n");
            return 0;
        }
    }

    return 1;
}