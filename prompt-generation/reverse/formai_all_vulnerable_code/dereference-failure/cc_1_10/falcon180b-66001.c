//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

typedef struct {
    int num_sides;
    int *sides;
} Die;

typedef struct {
    int num_dice;
    Die *dice;
} Roll;

void init_die(Die *die, int num_sides) {
    die->num_sides = num_sides;
    die->sides = malloc(num_sides * sizeof(int));
    for (int i = 0; i < num_sides; i++) {
        die->sides[i] = i + 1;
    }
}

void free_die(Die *die) {
    free(die->sides);
}

void init_roll(Roll *roll, int num_dice, int num_sides) {
    roll->num_dice = num_dice;
    roll->dice = malloc(num_dice * sizeof(Die));
    for (int i = 0; i < num_dice; i++) {
        init_die(&roll->dice[i], num_sides);
    }
}

void free_roll(Roll *roll) {
    for (int i = 0; i < roll->num_dice; i++) {
        free_die(&roll->dice[i]);
    }
    free(roll->dice);
}

int roll_dice(Roll *roll) {
    int result = 0;
    for (int i = 0; i < roll->num_dice; i++) {
        result += roll->dice[i].sides[rand() % roll->dice[i].num_sides];
    }
    return result;
}

int main() {
    srand(time(NULL));

    int num_dice, num_sides;
    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides: ");
    scanf("%d", &num_sides);

    Roll roll;
    init_roll(&roll, num_dice, num_sides);

    int total = 0;
    for (int i = 0; i < 10; i++) {
        int roll_result = roll_dice(&roll);
        printf("Roll %d: %d\n", i + 1, roll_result);
        total += roll_result;
    }

    printf("Total: %d\n", total);

    free_roll(&roll);

    return 0;
}