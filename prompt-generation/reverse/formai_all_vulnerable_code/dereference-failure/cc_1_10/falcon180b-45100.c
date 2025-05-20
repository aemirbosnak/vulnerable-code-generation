//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define MAX_SIDES 20

void roll_dice(int num_dice, int sides) {
    int i;
    int *dice = malloc(num_dice * sizeof(int));
    srand(time(NULL));

    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % sides + 1;
    }

    printf("Rolling %d dice with %d sides:\n", num_dice, sides);
    for (i = 0; i < num_dice; i++) {
        printf("%d\n", dice[i]);
    }

    free(dice);
}

int main() {
    int num_dice, sides;
    char choice;
    do {
        printf("Enter the number of dice to roll (1-6): ");
        scanf("%d", &num_dice);
        if (num_dice < 1 || num_dice > NUM_DICE) {
            printf("Invalid number of dice.\n");
        }
    } while (num_dice < 1 || num_dice > NUM_DICE);

    do {
        printf("Enter the number of sides on each die (1-20): ");
        scanf("%d", &sides);
        if (sides < 1 || sides > MAX_SIDES) {
            printf("Invalid number of sides.\n");
        }
    } while (sides < 1 || sides > MAX_SIDES);

    roll_dice(num_dice, sides);

    printf("Do you want to roll again? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}