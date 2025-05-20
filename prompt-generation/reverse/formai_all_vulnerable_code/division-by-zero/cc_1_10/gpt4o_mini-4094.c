//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int sides, int rolls) {
    int total = 0;
    printf("You rolled a %d-sided dice %d times:\n", sides, rolls);
    for (int i = 0; i < rolls; i++) {
        int roll = (rand() % sides) + 1;  // Generate a roll between 1 and 'sides'
        total += roll;
        printf("Roll #%d: %d\n", i + 1, roll);
    }
    printf("Total of Rolls: %d\n", total);
}

void displayMenu() {
    printf("\n***** DICE ROLLER *****\n");
    printf("1. Roll a D4\n");
    printf("2. Roll a D6\n");
    printf("3. Roll an 8-sided die (D8)\n");
    printf("4. Roll a D10\n");
    printf("5. Roll a D12\n");
    printf("6. Roll a D20\n");
    printf("7. Roll a Custom Die\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

int main() {
    srand((unsigned)time(NULL));  // Seed the random number generator
    
    int choice, sides, rolls;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                rolls = 1;
                rollDice(4, rolls);
                break;
            case 2:
                rolls = 1;
                rollDice(6, rolls);
                break;
            case 3:
                rolls = 1;
                rollDice(8, rolls);
                break;
            case 4:
                rolls = 1;
                rollDice(10, rolls);
                break;
            case 5:
                rolls = 1;
                rollDice(12, rolls);
                break;
            case 6:
                rolls = 1;
                rollDice(20, rolls);
                break;
            case 7:
                printf("Enter the number of sides for the custom die: ");
                scanf("%d", &sides);
                printf("Enter the number of times to roll the die: ");
                scanf("%d", &rolls);
                rollDice(sides, rolls);
                break;
            case 8:
                printf("Exiting the Dice Roller... May the odds be ever in your favor!\n");
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 8);

    // Fun statistical recap of the experience
    printf("\nYou embarked on a mystical journey through the realms of chance!\n");
    printf("Each roll was a step in the dance of fate, swirling through the cosmos...\n");
    printf("Truth unveiled, for every number holds a magic of its own!\n");
    printf("Thank you for participating in this journey of discovery and luck!\n");

    return 0;
}