//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome the user
    printf("Welcome to the Time Travel Simulator!\n");
    printf("In this simulation, you will visit important events throughout history.\n");

    // Prompt the user for the starting year
    int startYear;
    printf("What year do you want to start from?\n");
    scanf("%d", &startYear);

    // Generate a random year to visit
    srand(time(NULL));
    int randomYear = rand() % (2021 - startYear) + startYear;

    // Show the user the chosen year
    printf("You will travel to the year %d.\n", randomYear);

    // Prompt the user for their desired form for time travel
    printf("Choose the shape you want to shapeshift into for the trip:\n");
    printf("1. Eagle (for flying)\n");
    printf("2. Fish (for swimming)\n");
    printf("3. Cheetah (for speed)\n");

    int formChoice;
    char* formName;

    scanf("%d", &formChoice);

    // Set the form name based on the user's choice
    switch(formChoice) {
        case 1:
            formName = "Eagle";
            break;
        case 2:
            formName = "Fish";
            break;
        case 3:
            formName = "Cheetah";
            break;
        default:
            printf("Invalid choice, defaulting to Eagle.\n");
            formName = "Eagle";
    }

    // Display the user's chosen form
    printf("You will shapeshift into a %s for the trip.\n", formName);

    // Travel to the chosen year
    printf("You are now travelling to the year %d as a %s...\n", randomYear, formName);

    // ...and arrive!
    printf("You have arrived in the year %d as a %s!\n", randomYear, formName);

    return 0;
}