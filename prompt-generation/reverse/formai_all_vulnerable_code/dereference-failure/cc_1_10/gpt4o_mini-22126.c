//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[50];
    Date birthDate;
    Date travelDate;
} Traveler;

void printDate(Date date) {
    printf("%02d/%02d/%04d", date.day, date.month, date.year);
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

int travelToYear(Traveler *traveler, int targetYear) {
    if (targetYear < 1900 || targetYear > 3000) {
        printf("Travel year must be between 1900 and 3000.\n");
        return -1;
    }

    traveler->travelDate.year = targetYear;
    traveler->travelDate.month = 1; // Start from January
    traveler->travelDate.day = 1;    // Start from the first day

    printf("%s travels to ", traveler->name);
    printDate(traveler->travelDate);
    printf("\n");
    return 0;
}

void showTravelerInfo(Traveler traveler) {
    printf("Traveler Name: %s\n", traveler.name);
    printf("Birth Date: ");
    printDate(traveler.birthDate);
    printf("\n");
    printf("Current Travel Date: ");
    printDate(traveler.travelDate);
    printf("\n");
}

int main() {
    Traveler traveler;
    char targetYearStr[10];

    printf("Enter your name: ");
    fgets(traveler.name, sizeof(traveler.name), stdin);
    traveler.name[strcspn(traveler.name, "\n")] = 0; // Remove newline

    printf("Enter your birth date (YYYY-MM-DD): ");
    char birthDateInput[11]; // Format YYYY-MM-DD
    fgets(birthDateInput, sizeof(birthDateInput), stdin);
    sscanf(birthDateInput, "%d-%d-%d", &traveler.birthDate.year, &traveler.birthDate.month, &traveler.birthDate.day);

    // Setting initial travel date to current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    traveler.travelDate.year = tm.tm_year + 1900; // Adjust since tm_year is years since 1900
    traveler.travelDate.month = tm.tm_mon + 1;    // tm_mon is months since January
    traveler.travelDate.day = tm.tm_mday;          // Current day

    while (1) {
        printf("\nCurrent Time Machine Date: ");
        printDate(traveler.travelDate);
        printf("\nEnter a year to travel to (or 'exit' to quit): ");
        fgets(targetYearStr, sizeof(targetYearStr), stdin);

        if (strncmp(targetYearStr, "exit", 4) == 0) {
            printf("Exiting Time Travel Simulator.\n");
            break;
        }

        int targetYear;
        sscanf(targetYearStr, "%d", &targetYear);
        
        if (travelToYear(&traveler, targetYear) == 0) {
            showTravelerInfo(traveler);
        }
    }

    return 0;
}