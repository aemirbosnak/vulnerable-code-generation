//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll a dice with n sides
int rollDice(int n) {
    return rand() % n + 1;
}

int main() {
    // seed the random number
    srand(time(NULL));
    
    int sides, rolls, i, j, sum;
    printf("*** Dice Roller App ***\n\n");
    
    // get number of sides for the dice
    printf("Enter the number of sides for the dice: ");
    scanf("%d", &sides);
    
    // get number of rolls
    printf("Enter the number of rolls: ");
    scanf("%d", &rolls);
 
    printf("\nRolling %d %d-sided dice...\n", rolls, sides);
    
    // initialize sum
    sum = 0;
    
    // roll the dice and display the results
    for (i = 1; i <= rolls; i++) {
        int rollResult = rollDice(sides);
        printf("Roll %d: %d\n", i, rollResult);
        
        sum += rollResult;
    }
    
    // display the sum of the rolls
    printf("\nSum of rolls: %d\n", sum);
    
    // display individual roll frequencies
    printf("\nIndividual roll frequencies:\n");
    for (j = 1; j <= sides; j++) {
        int freq = 0;
        for (i = 1; i <= rolls; i++) {
            if (rollDice(sides) == j) {
                freq++;
            }
        }
        printf("%d: %d\n", j, freq);
    }
    
    return 0;
}