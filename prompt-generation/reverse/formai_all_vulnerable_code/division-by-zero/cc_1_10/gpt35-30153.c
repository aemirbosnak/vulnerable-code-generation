//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    int numRolls = 0;
    int sides = 0;
    int totalRolls = 0;
    int i = 0;
    char quit = 'n';
    
    printf("Welcome to Retro Dice Roller!\n\n");
    
    while (quit != 'y') {
        printf("How many dice rolls would you like to make? (max 5): ");
        scanf("%d", &numRolls);
        
        while (numRolls > 5) {
            printf("You cannot make more than 5 rolls at a time.\n");
            printf("How many dice rolls would you like to make? (max 5): ");
            scanf("%d", &numRolls);
        }
        
        printf("How many sides does the dice have? (max 20): ");
        scanf("%d", &sides);
        
        while (sides > 20) {
            printf("You cannot have dice with more than 20 sides.\n");
            printf("How many sides does the dice have? (max 20): ");
            scanf("%d", &sides);
        }
        
        printf("\nRolling...\n");
        for (i = 1; i <= numRolls; i++) {
            int roll = rand() % sides + 1;
            printf("Roll %d: %d\n", i, roll);
            totalRolls += roll;
        }
        
        printf("Total: %d\n", totalRolls);
        totalRolls = 0;
        
        printf("\nDo you want to quit? (y/n): ");
        scanf(" %c", &quit); // space before the %c to clear any input buffer issues
        printf("\n");
    }
    
    printf("Thanks for using Retro Dice Roller!\n");
    return 0;
}