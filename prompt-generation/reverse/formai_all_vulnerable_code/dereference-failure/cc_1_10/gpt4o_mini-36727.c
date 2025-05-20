//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void showCurrentTime();
void timeTravel(int years);
void displayMenu();

int main() {
    int choice, years;

    // Seed random number generator for quirky time effects
    srand(time(NULL));
    
    printf("Welcome to the Time Travel Simulator!\n");
    showCurrentTime();

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        choice = getchar();
        getchar(); // consume newline

        switch (choice) {
            case '1':
                showCurrentTime();
                break;
            case '2':
                printf("Enter number of years to travel (positive for future, negative for past): ");
                scanf("%d", &years);
                getchar(); // consume newline
                timeTravel(years);
                break;
            case '3':
                printf("Exiting the Time Travel Simulator. Safe travels!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void showCurrentTime() {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    printf("Current date and time: %s", asctime(tm_info));
}

void timeTravel(int years) {
    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    tm_info->tm_year += years; // Update year
    mktime(tm_info); // Normalize the time structure

    printf("You have time traveled %d years.\n", years);
    printf("New date and time: %s", asctime(tm_info));

    // Adding a quirky time distortion effect
    if (years > 0) {
        printf("Future prediction: Be prepared for flying cars and robot assistants!\n");
    } else {
        printf("Past prediction: Dinosaurs might not be thrilled to see you!\n");
    }
}

void displayMenu() {
    printf("\n=== Time Travel Menu ===\n");
    printf("1. Show current time\n");
    printf("2. Time travel\n");
    printf("3. Exit\n");
}