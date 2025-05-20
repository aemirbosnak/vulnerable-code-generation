//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DICE 6
#define SIDES_PER_DICE 6
#define RANGE (SIDES_PER_DICE * NUM_DICE)

typedef struct {
    int sides;
    int *roll;
} Die;

void initialize_die(Die *dice);
void roll_dice(Die *dice);
void print_results(const Die *dice, int num_rolls);

int main() {
    srand(time(NULL));
    Die dice[NUM_DICE];

    printf("Welcome to Ada's Dice Roller!\n");
    initialize_die(dice);

    int num_rolls;
    printf("Enter the number of dice rolls you'd like to make: ");
    scanf("%d", &num_rolls);

    printf("\nRolling the dice...\n");
    for (int i = 0; i < num_rolls; i++) {
        roll_dice(dice);
    }

    printf("\nResults of your dice rolls:\n");
    print_results(dice, num_rolls);

    return 0;
}

void initialize_die(Die *dice) {
    for (int i = 0; i < NUM_DICE; i++) {
        dice[i].sides = SIDES_PER_DICE;
        dice[i].roll = (int*) malloc(sizeof(int) * dice[i].sides);
    }
}

void roll_dice(Die *dice) {
    for (int i = 0; i < dice->sides; i++) {
        dice->roll[i] = 1 + (rand() % dice->sides);
    }
}

void print_results(const Die *dice, int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        printf("\nDice %d results:", i + 1);
        for (int j = 0; j < dice[0].sides; j++) {
            printf(" %d", dice[i % NUM_DICE].roll[j]);
        }
    }
}