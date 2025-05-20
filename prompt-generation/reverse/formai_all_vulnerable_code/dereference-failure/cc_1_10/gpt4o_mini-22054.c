//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a time traveler
typedef struct {
    int year;
    int month;
    int day;
    char name[50];
} TimeTraveler;

// Function declarations
void travelInTime(TimeTraveler *traveler, int year, int month, int day);
void displayCurrentTime(const TimeTraveler *traveler);
void showMenu();
void executeTimeTravel(TimeTraveler *traveler);

// Main function
int main() {
    TimeTraveler traveler;
    printf("Enter your name: ");
    fgets(traveler.name, sizeof(traveler.name), stdin);
    traveler.name[strcspn(traveler.name, "\n")] = 0; // Remove newline character

    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    traveler.year = tm_info->tm_year + 1900;
    traveler.month = tm_info->tm_mon + 1;
    traveler.day = tm_info->tm_mday;

    printf("Welcome, %s! You are currently in year %d, month %d, day %d.\n",
           traveler.name, traveler.year, traveler.month, traveler.day);

    executeTimeTravel(&traveler);

    return 0;
}

// Function to allow the time traveler to move to a new date
void travelInTime(TimeTraveler *traveler, int year, int month, int day) {
    // Update the traveler's date
    traveler->year = year;
    traveler->month = month;
    traveler->day = day;

    printf("Time travel successful! You've arrived on %04d-%02d-%02d.\n",
           traveler->year, traveler->month, traveler->day);
}

// Function to display the current time the traveler is in
void displayCurrentTime(const TimeTraveler *traveler) {
    printf("You are currently in the year %04d, month %02d, day %02d.\n",
           traveler->year, traveler->month, traveler->day);
}

// Function to display the menu and handle user choices
void showMenu() {
    printf("\nTime Travel Simulator Menu:\n");
    printf("1. Travel to a specific date\n");
    printf("2. Display current time\n");
    printf("3. Exit\n");
}

// Function to execute the time travel based on user's choice
void executeTimeTravel(TimeTraveler *traveler) {
    int choice;
    while (1) {
        showMenu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int year, month, day;

                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                printf("Enter the month you want to travel to (1-12): ");
                scanf("%d", &month);
                printf("Enter the day you want to travel to (1-31): ");
                scanf("%d", &day);

                // Validate the date
                if (month < 1 || month > 12 || day < 1 || day > 31) {
                    printf("Invalid date. Please try again.\n");
                    break;
                }

                travelInTime(traveler, year, month, day);
                break;
            }
            case 2:
                displayCurrentTime(traveler);
                break;
            case 3:
                printf("Exiting the Time Travel Simulator. Safe travels, %s!\n", traveler->name);
                return; // Exit the loop and program
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }
}