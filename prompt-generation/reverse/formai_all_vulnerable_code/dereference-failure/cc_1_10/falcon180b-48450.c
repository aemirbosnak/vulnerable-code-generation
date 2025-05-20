//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
    int *dice_values;
} Roll;

void roll_dice(Roll *roll) {
    srand(time(NULL));
    roll->dice_values = malloc(roll->num_dice * sizeof(int));
    for (int i = 0; i < roll->num_dice; i++) {
        roll->dice_values[i] = rand() % roll->num_sides + 1;
    }
}

void print_roll(Roll *roll) {
    printf("Rolling %d %d-sided dice:\n", roll->num_dice, roll->num_sides);
    for (int i = 0; i < roll->num_dice; i++) {
        printf("%d ", roll->dice_values[i]);
    }
    printf("\n");
}

void free_roll(Roll *roll) {
    free(roll->dice_values);
}

int main() {
    Roll roll;
    printf("Enter number of dice: ");
    scanf("%d", &roll.num_dice);
    printf("Enter number of sides: ");
    scanf("%d", &roll.num_sides);

    if (roll.num_dice > MAX_DICE || roll.num_sides > MAX_SIDES) {
        printf("Invalid input.\n");
        return 1;
    }

    roll_dice(&roll);
    print_roll(&roll);
    free_roll(&roll);

    return 0;
}