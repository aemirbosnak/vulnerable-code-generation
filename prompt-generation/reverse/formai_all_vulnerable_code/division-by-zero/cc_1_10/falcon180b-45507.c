//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

typedef struct {
    int num_sides;
    int dice_count;
    int *dice;
} DiceRoller;

void init_diceroller(DiceRoller *dr, int num_sides, int dice_count) {
    dr->num_sides = num_sides;
    dr->dice_count = dice_count;
    dr->dice = malloc(dice_count * sizeof(int));
    for (int i = 0; i < dice_count; i++) {
        dr->dice[i] = rand() % num_sides + 1;
    }
}

void roll_dice(DiceRoller *dr) {
    for (int i = 0; i < dr->dice_count; i++) {
        dr->dice[i] = rand() % dr->num_sides + 1;
    }
}

void print_dice(DiceRoller *dr) {
    for (int i = 0; i < dr->dice_count; i++) {
        printf("%d ", dr->dice[i]);
    }
    printf("\n");
}

void free_diceroller(DiceRoller *dr) {
    free(dr->dice);
}

int main() {
    srand(time(NULL));
    int num_dice, num_sides, dice_count;
    printf("Enter number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter number of sides: ");
    scanf("%d", &num_sides);
    printf("Enter number of dice to roll: ");
    scanf("%d", &dice_count);
    DiceRoller dr;
    init_diceroller(&dr, num_sides, dice_count);
    for (int i = 0; i < num_dice; i++) {
        roll_dice(&dr);
        print_dice(&dr);
    }
    free_diceroller(&dr);
    return 0;
}