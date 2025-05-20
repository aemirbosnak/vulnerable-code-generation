//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME_TRAVEL_YEARS 100
#define TIME_TRAVEL_SPEED 88 // miles per hour

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

int main() {
    int year, destinationYear;
    double distance;
    char input[100];

    // Get current year
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    year = t->tm_year + 1900;

    // Prompt user for destination year
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d.\n", year);
    printf("Where would you like to travel to? ");
    scanf("%s", input);

    // Convert input to integer
    destinationYear = atoi(input);

    // Check if destination year is valid
    if (destinationYear < 1900 || destinationYear > year + MAX_TIME_TRAVEL_YEARS) {
        printf("Invalid destination year.\n");
        return 0;
    }

    // Calculate distance between current year and destination year
    distance = fabs(destinationYear - year);

    // Calculate time it would take to travel at 88 miles per hour
    double time = distance / TIME_TRAVEL_SPEED;

    // Check if destination year is a leap year
    if (isLeapYear(destinationYear)) {
        printf("You have traveled %.2f years into the future to the year %.0f!\n", time, destinationYear);
    } else {
        printf("You have traveled %.2f years into the past to the year %.0f!\n", time, destinationYear);
    }

    return 0;
}