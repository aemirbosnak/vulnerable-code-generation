//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define MAX_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int total;
} Roll;

void roll_dice(Roll *roll) {
    int i;
    for (i = 0; i < roll->num_dice; i++) {
        roll->total += rand() % roll->num_sides + 1;
    }
}

int main() {
    Roll roll;
    int choice;
    int i;
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &roll.num_dice);
    printf("How many sides would you like on each die? ");
    scanf("%d", &roll.num_sides);

    printf("Rolling %d %d-sided dice...\n", roll.num_dice, roll.num_sides);
    roll_dice(&roll);
    printf("Total: %d\n", roll.total);

    printf("Would you like to roll again? (y/n) ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        printf("How many dice would you like to roll? ");
        scanf("%d", &roll.num_dice);
        printf("How many sides would you like on each die? ");
        scanf("%d", &roll.num_sides);

        printf("Rolling %d %d-sided dice...\n", roll.num_dice, roll.num_sides);
        roll_dice(&roll);
        printf("Total: %d\n", roll.total);

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);
    }

    return 0;
}