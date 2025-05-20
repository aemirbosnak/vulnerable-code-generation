//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL)); // seed the random generator

    // Creating variables for user input and current date
    int year, month, day;
    time_t currentTime;
    struct tm* timeInfo;

    // Getting current time
    currentTime = time(NULL);
    timeInfo = localtime(&currentTime);

    int currentYear = timeInfo->tm_year + 1900; // 1900 is added since tm_year starts from 1900
    int currentMonth = timeInfo->tm_mon + 1; // tm_mon starts from 0, so add 1
    int currentDay = timeInfo->tm_mday;

    printf("Welcome to Time Travel Simulator!\n");
    printf("Enter a date (yyyy mm dd) to travel to: ");
    scanf("%d %d %d", &year, &month, &day);

    if (year > currentYear) { // if the year is in the future
        printf("Sorry, time travel to the future is not possible.\n");
    } else if (year == currentYear && month > currentMonth) { // if the year is the same but the month is in the future
        printf("Sorry, time travel to the future is not possible.\n");
    } else if (year == currentYear && month == currentMonth && day > currentDay) { // if the year and month are the same but the day is in the future
        printf("Sorry, time travel to the future is not possible.\n");
    } else { // if the date is in the past or same as the current date
        printf("Preparing time travel to %d/%d/%d...\n", year, month, day);
        printf("Initiating time travel sequence...\n");
        printf("You have arrived in %d/%d/%d!\n", year, month, day);

        // Random events
        int randomEvent = rand() % 3; // generating a random number between 0-2

        switch (randomEvent) {
            case 0:
                printf("There is a parade going on! Enjoy the celebration.\n");
                break;
            case 1:
                printf("Oh no, you've stepped in mud. Try to find a place to clean your shoes.\n");
                break;
            case 2:
                printf("A group of birds just flew overhead and left a mess on your shirt. Look for a place to clean up.\n");
                break;
            default:
                printf("No random event occurred.");
                break;
        }
    }

    return 0;
}