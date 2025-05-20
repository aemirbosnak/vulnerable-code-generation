//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define MAX_YEAR 9999
#define MIN_YEAR 1000

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

// Function to validate the date
int isValidDate(int year, int month, int day) {
    if (year < MIN_YEAR || year > MAX_YEAR || month < 1 || month > 12) {
        return 0;
    }
    int daysInMonth[] = { 31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return day > 0 && day <= daysInMonth[month - 1];
}

// Function to create a time string from Time structure
void formatTime(Time *t, char *buffer) {
    sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d", t->year, t->month, t->day, t->hour, t->minute, t->second);
}

// Function to get current time
Time getCurrentTime() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    Time timeStruct = { t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec };
    return timeStruct;
}

// Function to travel in time
Time travelTime(Time current, int years, int months, int days, int hours, int minutes, int seconds) {
    Time traveledTime = current;

    traveledTime.year += years;
    traveledTime.month += months;
    traveledTime.day += days;
    traveledTime.hour += hours;
    traveledTime.minute += minutes;
    traveledTime.second += seconds;

    // Normalize the time
    if (traveledTime.second >= 60) {
        traveledTime.minute += traveledTime.second / 60;
        traveledTime.second %= 60;
    }
    if (traveledTime.minute >= 60) {
        traveledTime.hour += traveledTime.minute / 60;
        traveledTime.minute %= 60;
    }
    if (traveledTime.hour >= 24) {
        traveledTime.day += traveledTime.hour / 24;
        traveledTime.hour %= 24;
    }
    while (!isValidDate(traveledTime.year, traveledTime.month, traveledTime.day)) {
        traveledTime.day--;
        // If day goes to zero, go to the previous month
        if (traveledTime.day < 1) {
            traveledTime.month--;
            if (traveledTime.month < 1) {
                traveledTime.month = 12;
                traveledTime.year--;
            }
            // Adjust days in the new month
            int daysInMonth[] = { 31, 28 + (traveledTime.year % 4 == 0 && (traveledTime.year % 100 != 0 || traveledTime.year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            traveledTime.day = daysInMonth[traveledTime.month - 1];
        }
    }

    return traveledTime;
}

// Main function
int main() {
    Time currentTime = getCurrentTime();
    char timeStr[BUFFER_SIZE];
    formatTime(&currentTime, timeStr);
    
    printf("Current time: %s\n", timeStr);

    int years, months, days, hours, minutes, seconds;
    printf("Enter time travel parameters (years, months, days, hours, minutes, seconds): ");
    scanf("%d %d %d %d %d %d", &years, &months, &days, &hours, &minutes, &seconds);

    Time newTime = travelTime(currentTime, years, months, days, hours, minutes, seconds);
    formatTime(&newTime, timeStr);

    printf("Traveled to: %s\n", timeStr);
    return 0;
}