//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int hour;
    int minute;
    int second;
} Time;

typedef struct {
    Date date;
    Time time;
} Timestamp;

void displayMenu() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to a specific date and time\n");
    printf("2. Travel to the past\n");
    printf("3. Travel to the future\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int validateDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return 0;
    }
    int daysInMonth;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            daysInMonth = 31; break;
        case 4: case 6: case 9: case 11:
            daysInMonth = 30; break;
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                daysInMonth = 29; // Leap year
            } else {
                daysInMonth = 28;
            }
            break;
        default:
            return 0;
    }
    return day <= daysInMonth;
}

void captureTimestamp(Timestamp *timestamp) {
    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &timestamp->date.day, &timestamp->date.month, &timestamp->date.year);
    printf("Enter time (hh mm ss): ");
    scanf("%d %d %d", &timestamp->time.hour, &timestamp->time.minute, &timestamp->time.second);
}

void travelToTimestamp(Timestamp timestamp) {
    if (!validateDate(timestamp.date.day, timestamp.date.month, timestamp.date.year)) {
        printf("Invalid date!\n");
        return;
    }
    printf("Traveling to %02d/%02d/%d at %02d:%02d:%02d...\n",
           timestamp.date.day, timestamp.date.month, timestamp.date.year,
           timestamp.time.hour, timestamp.time.minute, timestamp.time.second);
    printf("You have arrived!\n");
}

void travelToPast() {
    int years;
    printf("How many years in the past would you like to travel? ");
    scanf("%d", &years);
    time_t now;
    time(&now);
    struct tm *tm = localtime(&now);
    tm->tm_year -= years;
    mktime(tm);
    printf("Traveling to %s...\n", asctime(tm));
    printf("You have arrived in the past!\n");
}

void travelToFuture() {
    int years;
    printf("How many years into the future would you like to travel? ");
    scanf("%d", &years);
    time_t now;
    time(&now);
    struct tm *tm = localtime(&now);
    tm->tm_year += years;
    mktime(tm);
    printf("Traveling to %s...\n", asctime(tm));
    printf("You have arrived in the future!\n");
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Timestamp timestamp;
                captureTimestamp(&timestamp);
                travelToTimestamp(timestamp);
                break;
            }
            case 2:
                travelToPast();
                break;
            case 3:
                travelToFuture();
                break;
            case 4:
                printf("Exiting Time Travel Simulator. Safe travels!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}