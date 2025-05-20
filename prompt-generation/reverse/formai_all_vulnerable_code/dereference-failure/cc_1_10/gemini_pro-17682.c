//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int value;
    char *name;
} Die;

typedef struct {
    int num_dice;
    int *dice;
} Roll;

Roll *roll_dice(int num_dice) {
    Roll *roll = malloc(sizeof(Roll));
    roll->num_dice = num_dice;
    roll->dice = malloc(sizeof(int) * num_dice);

    for (int i = 0; i < num_dice; i++) {
        roll->dice[i] = rand() % 6 + 1;
    }

    return roll;
}

void print_roll(Roll *roll) {
    printf("You rolled a %d:", roll->num_dice);
    for (int i = 0; i < roll->num_dice; i++) {
        printf(" %d", roll->dice[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    srand(time(NULL));

    if (argc < 2) {
        printf("Usage: %s <number of dice>\n", argv[0]);
        return 1;
    }

    int num_dice = atoi(argv[1]);
    Roll *roll = roll_dice(num_dice);
    print_roll(roll);

    free(roll->dice);
    free(roll);

    return 0;
}