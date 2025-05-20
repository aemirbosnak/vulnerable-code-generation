//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

// Function to roll a single die
int roll_die(int sides) {
    return rand() % sides + 1;
}

// Function to roll multiple dice
void roll_dice(int num_dice, int sides, int *results) {
    srand(time(NULL));
    for (int i = 0; i < num_dice; i++) {
        results[i] = roll_die(sides);
    }
}

// Function to determine the total result of a roll
int get_total(int num_dice, int sides, int *results) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += results[i];
    }
    return total;
}

int main() {
    int num_dice, sides;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);
    
    if (num_dice > MAX_DICE) {
        printf("Error: Too many dice.\n");
        return 1;
    }
    
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);
    
    if (sides > MAX_SIDES) {
        printf("Error: Too many sides.\n");
        return 1;
    }
    
    int results[num_dice];
    roll_dice(num_dice, sides, results);
    
    int total = get_total(num_dice, sides, results);
    
    printf("You rolled %d dice with %d sides each.\n", num_dice, sides);
    printf("The result of the roll is %d.\n", total);
    
    return 0;
}