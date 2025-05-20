//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Setting up the time travel simulator
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    int currentYear = t->tm_year + 1900;
    int userYear, addYears, newYear;
    char answer;

    // Asking user if they want to time travel
    printf("Welcome to the Happy Time Travel Simulator!\n");
    printf("Do you want to time travel? (y/n)\n");
    scanf(" %c", &answer);
    printf("\n");

    // Loop to continue asking user to time travel
    while (answer == 'y') {

        // Asking user to choose year to travel to
        printf("What year do you want to travel to?\n");
        scanf("%d", &userYear);

        // Checking if user can time travel to that year
        if (userYear >= currentYear) {
            printf("Sorry, you cannot time travel to the future!\n\n");
        } else {

            // Calculating how many years user has to go back in time and displaying result
            addYears = currentYear - userYear;
            printf("Traveling back %d years...\n", addYears);

            // Adding years to current time to simulate time travel
            t->tm_year -= addYears;
            mktime(t);

            // Displaying new time and asking if user wants to time travel again
            newYear = t->tm_year + 1900;
            printf("Welcome to %d!\n", newYear);
            printf("Do you want to time travel again? (y/n)\n");
            scanf(" %c", &answer);
            printf("\n");
        }
    }

    // If user chooses not to time travel
    printf("Thanks for checking out the Happy Time Travel Simulator!\n");
    printf("Come back soon!\n");

    return 0;
}