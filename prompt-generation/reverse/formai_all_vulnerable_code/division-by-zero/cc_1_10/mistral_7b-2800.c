//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 6
#define MAX_ROLLS 100

typedef struct {
    int num_dice;
    int sides;
    int rolls[MAX_ROLLS];
    int total;
} dice_roll_t;

void roll_dice(dice_roll_t *roll) {
    int i, result;

    roll->total = 0;
    for (i = 0; i < roll->num_dice; i++) {
        result = rand() % (roll->sides + 1);
        roll->rolls[roll->total] = result;
        roll->total += result;
        printf("Rolled a %d on dice %d\n", result, i + 1);
    }
}

int main() {
    dice_roll_t roll;
    int choice;

    srand(time(NULL));

    do {
        printf("\nDice Roller\n");
        printf("1. Roll dice\n");
        printf("2. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter number of dice to roll: ");
            scanf("%d", &roll.num_dice);

            if (roll.num_dice > MAX_DICE) {
                printf("Too many dice.\n");
                continue;
            }

            printf("Enter number of sides on each die: ");
            scanf("%d", &roll.sides);

            if (roll.sides > MAX_SIDES) {
                printf("Too many sides.\n");
                continue;
            }

            roll_dice(&roll);
            printf("Total roll: %d\n", roll.total);
        }
    } while (choice != 2);

    return 0;
}