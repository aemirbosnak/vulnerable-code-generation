//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 1000
#define MAX_DICE 1000

typedef struct {
    int num_sides;
    int num_dice;
    int *rolls;
} dice_t;

void roll_dice(dice_t *d) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < d->num_dice; i++) {
        d->rolls[i] = rand() % d->num_sides + 1;
    }
}

void print_rolls(dice_t *d) {
    int i;
    printf("Rolls: ");
    for (i = 0; i < d->num_dice; i++) {
        printf("%d ", d->rolls[i]);
    }
    printf("\n");
}

int main() {
    int num_dice, num_sides;
    dice_t *d;

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides for each die: ");
    scanf("%d", &num_sides);

    d = malloc(sizeof(dice_t));
    d->num_dice = num_dice;
    d->num_sides = num_sides;
    d->rolls = malloc(sizeof(int) * num_dice);

    roll_dice(d);
    print_rolls(d);

    free(d->rolls);
    free(d);

    return 0;
}