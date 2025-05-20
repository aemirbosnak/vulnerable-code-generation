//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 100

typedef struct {
    int num_dice;
    int num_sides;
    int *rolls;
} roll_t;

void roll_dice(roll_t *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        roll->rolls[i] = rand() % roll->num_sides + 1;
    }
}

void print_rolls(roll_t *roll) {
    printf("Rolling %d dice with %d sides:\n", roll->num_dice, roll->num_sides);
    for (int i = 0; i < roll->num_dice; i++) {
        printf("%d ", roll->rolls[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    roll_t roll;
    printf("Enter number of dice: ");
    scanf("%d", &roll.num_dice);
    printf("Enter number of sides: ");
    scanf("%d", &roll.num_sides);

    if (roll.num_dice > MAX_DICE || roll.num_sides > MAX_SIDES) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    roll.rolls = malloc(roll.num_dice * sizeof(int));
    if (roll.rolls == NULL) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    roll_dice(&roll);
    print_rolls(&roll);

    free(roll.rolls);
    return 0;
}