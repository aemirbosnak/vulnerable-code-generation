//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool inCyberspace = true;
int strength = 0;
int agility = 0;
int stamina = 0;
int caloriesBurned = 0;

int main() {
    printf("Welcome to the CyberFitness Tracker!\n");
    printf("Initializing tracker...\n");

    while (inCyberspace) {
        time_t currentTime = time(NULL);
        struct tm *localTime = localtime(&currentTime);
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;

        printf("\nIt is %02d:%02d in the virtual world.\n", hour, minute);
        printf("What would you like to do?\n");
        printf("1. Lift weights\n");
        printf("2. Sprint\n");
        printf("3. Rest\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou start lifting weights...");
                strength += 5;
                stamina -= 5;
                caloriesBurned += 50;
                break;
            case 2:
                printf("\nYou start sprinting...");
                agility += 5;
                stamina -= 10;
                caloriesBurned += 75;
                break;
            case 3:
                printf("\nYou take a break and catch your breath...");
                stamina += 10;
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                continue;
        }

        if (stamina < 0) {
            printf("\nYou're too tired! Go rest.\n");
            stamina = 0;
        } else {
            printf("\nYour current stats:\n");
            printf("Strength: %d\n", strength);
            printf("Agility: %d\n", agility);
            printf("Stamina: %d\n", stamina);
            printf("Calories burned: %d\n", caloriesBurned);
        }

        if (caloriesBurned >= 500) {
            inCyberspace = false;
            printf("\nCongrats! You've burned 500 calories and exited the virtual world.\n");
        }
    }

    printf("\nExiting CyberFitness Tracker.\n");
    return 0;
}