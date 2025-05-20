//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travelToThePast(int years) {
    time_t currentTime = time(NULL); // Get current time
    struct tm *currentTimeStruct = localtime(&currentTime); // Convert to struct tm
    int currentYear = currentTimeStruct->tm_year + 1900; // Extract current year
    int targetYear = currentYear - years; // Calculate target year

    if (targetYear < 1900) {
        printf("Sorry, time travel not possible. You're going back too far.\n");
    }
    else {
        system("clear"); // Clear screen
        printf("Traveling %d years to the past...\n", years);
        sleep(2); // Wait for 2 seconds
        printf("You have arrived in %d.\n", targetYear);
    }
}

void travelToTheFuture(int years) {
    time_t currentTime = time(NULL); // Get current time
    struct tm *currentTimeStruct = localtime(&currentTime); // Convert to struct tm
    int currentYear = currentTimeStruct->tm_year + 1900; // Extract current year
    int targetYear = currentYear + years; // Calculate target year

    if (targetYear > 2200) {
        printf("Sorry, time travel not possible. You're going too far into the future.\n");
    }
    else {
        system("clear"); // Clear screen
        printf("Traveling %d years to the future...\n", years);
        sleep(2); // Wait for 2 seconds
        printf("You have arrived in %d.\n", targetYear);
    }
}

int main() {
    int choice, years;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Choose your destination:\n");
    printf("1. Travel to the past\n");
    printf("2. Travel to the future\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("How many years do you want to travel to the past? ");
            scanf("%d", &years);
            travelToThePast(years);
            break;
        case 2:
            printf("How many years do you want to travel to the future? ");
            scanf("%d", &years);
            travelToTheFuture(years);
            break;
        default:
            printf("Invalid choice. Goodbye!\n");
    }

    return 0;
}