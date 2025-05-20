//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 100

typedef struct {
    int num_sides;
    int num_dice;
    int *rolls;
} Dice;

void init_dice(Dice *d, int num_sides, int num_dice) {
    d->num_sides = num_sides;
    d->num_dice = num_dice;
    d->rolls = malloc(num_dice * sizeof(int));
}

void roll_dice(Dice *d) {
    srand(time(NULL));
    for (int i = 0; i < d->num_dice; i++) {
        d->rolls[i] = rand() % d->num_sides + 1;
    }
}

void print_dice(Dice *d) {
    for (int i = 0; i < d->num_dice; i++) {
        printf("%d ", d->rolls[i]);
    }
    printf("\n");
}

int main() {
    Dice d;
    int num_sides, num_dice;

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);

    if (num_sides <= 0 || num_sides > MAX_SIDES || num_dice <= 0 || num_dice > MAX_DICE) {
        printf("Invalid input.\n");
        return 1;
    }

    init_dice(&d, num_sides, num_dice);
    roll_dice(&d);
    print_dice(&d);

    return 0;
}