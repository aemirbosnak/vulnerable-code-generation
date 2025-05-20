//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRAVEL_YEAR 3000
#define MIN_TRAVEL_YEAR 1000
#define USER_NAME_LENGTH 50
#define COMMENT_LENGTH 200

typedef struct {
    char userName[USER_NAME_LENGTH];
    int currentYear;
    int travelYear;
    char comment[COMMENT_LENGTH];
} TimeTraveler;

void welcomeMessage() {
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("Experience the past and the future, one year at a time!\n\n");
}

void getUserDetails(TimeTraveler *traveler) {
    printf("Enter your name: ");
    fgets(traveler->userName, USER_NAME_LENGTH, stdin);
    traveler->userName[strcspn(traveler->userName, "\n")] = '\0'; // Remove newline character

    time_t t;
    time(&t);
    struct tm *local = localtime(&t);
    traveler->currentYear = local->tm_year + 1900; // Year offset due to struct tm representation
    traveler->travelYear = traveler->currentYear;

    printf("Hello, %s! Your current year is %d.\n", traveler->userName, traveler->currentYear);
}

void displayTravelOptions() {
    printf("\nChoose your travel destination:\n");
    printf("1. Previous year\n");
    printf("2. Next year\n");
    printf("3. Input specific year\n");
    printf("4. Exit\n");
}

int getTravelChoice() {
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

void makeTravelChoice(TimeTraveler *traveler) {
    int choice;
    int specificYear;

    while (1) {
        displayTravelOptions();
        choice = getTravelChoice();

        switch (choice) {
            case 1:
                if (traveler->travelYear > MIN_TRAVEL_YEAR) {
                    traveler->travelYear--;
                    printf("You have traveled to the year: %d\n", traveler->travelYear);
                } else {
                    printf("You cannot travel further back than %d!\n", MIN_TRAVEL_YEAR);
                }
                break;
            case 2:
                if (traveler->travelYear < MAX_TRAVEL_YEAR) {
                    traveler->travelYear++;
                    printf("You have traveled to the year: %d\n", traveler->travelYear);
                } else {
                    printf("You cannot travel further into the future than %d!\n", MAX_TRAVEL_YEAR);
                }
                break;
            case 3:
                printf("Enter the specific year you want to travel to: ");
                scanf("%d", &specificYear);
                if (specificYear >= MIN_TRAVEL_YEAR && specificYear <= MAX_TRAVEL_YEAR) {
                    traveler->travelYear = specificYear;
                    printf("You have traveled to the year: %d\n", traveler->travelYear);
                } else {
                    printf("Invalid year! Please choose between %d and %d.\n", MIN_TRAVEL_YEAR, MAX_TRAVEL_YEAR);
                }
                break;
            case 4:
                printf("Exiting the simulator... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }

        printf("What's your comment about the year %d? (max 200 characters): ", traveler->travelYear);
        getchar(); // Clear the newline character from buffer
        fgets(traveler->comment, COMMENT_LENGTH, stdin);
        traveler->comment[strcspn(traveler->comment, "\n")] = '\0'; // Remove newline character
        printf("Your comment: \"%s\" has been recorded!\n", traveler->comment);
    }
}

int main() {
    TimeTraveler traveler;
    welcomeMessage();
    getUserDetails(&traveler);
    makeTravelChoice(&traveler);
    return 0;
}