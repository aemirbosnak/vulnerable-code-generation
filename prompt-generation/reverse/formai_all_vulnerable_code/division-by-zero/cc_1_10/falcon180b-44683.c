//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000
#define MAX_ROLLS 1000000

typedef struct {
    int num_dice;
    int num_sides;
    int num_rolls;
} dice_t;

void roll_dice(dice_t *dice) {
    int i, j, k;
    int *rolls = malloc(dice->num_rolls * sizeof(int));

    srand(time(NULL));

    for (i = 0; i < dice->num_rolls; i++) {
        for (j = 0; j < dice->num_dice; j++) {
            rolls[i] += rand() % dice->num_sides + 1;
        }
    }

    printf("Rolling %d %d-sided dice %d times:\n", dice->num_dice, dice->num_sides, dice->num_rolls);

    for (k = 0; k < dice->num_rolls; k++) {
        printf("%d ", rolls[k]);
    }

    free(rolls);
}

int main() {
    dice_t dice;

    printf("Enter the number of dice: ");
    scanf("%d", &dice.num_dice);

    printf("Enter the number of sides per die: ");
    scanf("%d", &dice.num_sides);

    printf("Enter the number of rolls: ");
    scanf("%d", &dice.num_rolls);

    if (dice.num_dice > MAX_DICE || dice.num_sides > MAX_SIDES || dice.num_rolls > MAX_ROLLS) {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    roll_dice(&dice);

    return 0;
}