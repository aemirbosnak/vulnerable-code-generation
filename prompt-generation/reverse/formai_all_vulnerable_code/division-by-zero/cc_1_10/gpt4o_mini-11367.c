//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 20

void printInstructions() {
    printf("Welcome to the Dynamic C Dice Roller!\n");
    printf("You can roll multiple dice at once.\n");
    printf("Commands:\n");
    printf("1. Roll a single die: r [sides]\n");
    printf("2. Roll multiple dice: r [number]d[sides]\n");
    printf("3. Quit: q\n");
    printf("Note: Max number of dice is %d, max sides per die is %d.\n\n", MAX_DICE, MAX_SIDES);
}

int rollDie(int sides) {
    return (rand() % sides) + 1;
}

void rollSingleDie(int sides) {
    printf("Rolling a %d-sided die...\n", sides);
    int result = rollDie(sides);
    printf("You rolled a: %d\n\n", result);
}

void rollMultipleDice(int numDice, int sides) {
    if (numDice > MAX_DICE) {
        printf("Error: You can roll a maximum of %d dice at once.\n\n", MAX_DICE);
        return;
    }

    printf("Rolling %d d%d...\n", numDice, sides);
    int total = 0;

    for (int i = 0; i < numDice; i++) {
        int result = rollDie(sides);
        printf("Die %d: %d\n", i + 1, result);
        total += result;
    }
    
    printf("Total roll: %d\n\n", total);
}

int main() {
    srand(time(NULL));
    char command[50];
    
    printInstructions();

    while (1) {
        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);

        char action;
        int numDice = 0, sides = 0;

        if (sscanf(command, "%c %d", &action, &sides) == 2) {
            if (action == 'r') {
                rollSingleDie(sides);
            } else {
                printf("Invalid command! Please try again.\n\n");
            }
        } else if (sscanf(command, "%c %dd%d", &action, &numDice, &sides) == 3) {
            if (action == 'r') {
                rollMultipleDice(numDice, sides);
            } else {
                printf("Invalid command! Please try again.\n\n");
            }
        } else if (sscanf(command, "%c", &action) == 1 && action == 'q') {
            printf("Thank you for using the C Dice Roller! Goodbye!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n\n");
        }
    }

    return 0;
}