//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime;
    struct tm *localTime;

    time( &currentTime );
    localTime = localtime( &currentTime );

    int year = localTime->tm_year + 1900;

    int currentYear = year;
    int simulatedYear;

    printf("Welcome to the Time Travel Simulator\n\n");
    printf("What year would you like to travel to? (e.g. 1985): ");
    scanf("%d", &simulatedYear);

    if (simulatedYear > currentYear) {
        printf("\nSorry, time machines can only travel back in time.\n");
        return 0;
    } else if (simulatedYear == currentYear) {
        printf("\nYou're already in the present!\n");
        return 0;
    } else {
        printf("\nTravelling back to %d...\n\n", simulatedYear);
    }

    int currentAge, simulatedAge;

    printf("What is your current age? ");
    scanf("%d", &currentAge);
    
    if (currentAge <= 0) {
        printf("\nSorry, invalid age.\n");
        return 0;
    } else if (currentAge >= (currentYear - simulatedYear)) {
        printf("\nSorry, you would not exist in %d.\n", simulatedYear);
        return 0;
    }

    simulatedAge = currentAge - (currentYear - simulatedYear);

    printf("\nWelcome to %d!\n\n", simulatedYear);
    printf("You are now %d years old.\n", simulatedAge);
    printf("Enjoy your time travel experience!\n");

    return 0;
}