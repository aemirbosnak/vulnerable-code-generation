//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 1000
#define MAX_SIDES 1000

struct dice {
    int num_sides;
    int value;
};

struct dice *roll_dice(int num_dice, int min_sides, int max_sides) {
    struct dice *dice = malloc(num_dice * sizeof(struct dice));
    for (int i = 0; i < num_dice; i++) {
        dice[i].num_sides = rand() % (max_sides - min_sides + 1) + min_sides;
        dice[i].value = rand() % dice[i].num_sides + 1;
    }
    return dice;
}

void print_dice(struct dice *dice, int num_dice) {
    for (int i = 0; i < num_dice; i++) {
        printf("Dice %d has %d sides and rolled a %d\n", i+1, dice[i].num_sides, dice[i].value);
    }
}

int main() {
    srand(time(NULL));
    int num_dice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);
    if (num_dice > MAX_DICE || num_dice < 1) {
        printf("Invalid number of dice.\n");
        return 1;
    }
    int min_sides, max_sides;
    printf("Enter the minimum number of sides for each die: ");
    scanf("%d", &min_sides);
    if (min_sides > MAX_SIDES || min_sides < 1) {
        printf("Invalid minimum number of sides.\n");
        return 1;
    }
    printf("Enter the maximum number of sides for each die: ");
    scanf("%d", &max_sides);
    if (max_sides > MAX_SIDES || max_sides < min_sides) {
        printf("Invalid maximum number of sides.\n");
        return 1;
    }
    struct dice *dice_array = roll_dice(num_dice, min_sides, max_sides);
    print_dice(dice_array, num_dice);
    free(dice_array);
    return 0;
}