//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_SIDE 4
#define MAX_SIDE 20

typedef struct {
    int sides;
    int *numbers;
} Die;

void generate_numbers(Die *dice, int num_dice, int num_sides) {
    int i, j;
    for (i = 0; i < num_dice; i++) {
        dice[i].sides = num_sides;
        dice[i].numbers = (int *)calloc(sizeof(int), num_sides);
        for (j = 0; j < num_sides; j++) {
            dice[i].numbers[j] = j + 1;
        }
    }
}

void roll_dice(Die *dice, int num_dice, int rolls) {
    int i, j, roll;
    srand(time(NULL));
    for (i = 0; i < rolls; i++) {
        for (j = 0; j < num_dice; j++) {
            roll = rand() % dice[j].sides + 1;
            printf("Die %d rolled a %d\n", j + 1, roll);
        }
        printf("\n");
    }
}

int main() {
    int num_dice = 3;
    int num_rolls = 10;
    Die *my_dice;

    my_dice = (Die *)calloc(sizeof(Die), num_dice);

    generate_numbers(my_dice, num_dice, MIN_SIDE);
    roll_dice(my_dice, num_dice, num_rolls);

    free(my_dice);
    return 0;
}

// A cheerful C Dice Roller program! Roll some happy dice!