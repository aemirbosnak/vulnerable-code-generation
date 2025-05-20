//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SIDES 6
#define NUM_DICE 3

typedef struct {
    int sides;
    int *rolls;
    size_t capacity;
    size_t size;
} dice_t;

void dice_init(dice_t *dice) {
    dice->sides = NUM_SIDES;
    dice->capacity = 10;
    dice->size = 0;
    dice->rolls = malloc(dice->capacity * sizeof(int));
}

void dice_roll(dice_t *dice) {
    if (dice->size >= dice->capacity) {
        dice->capacity *= 2;
        dice->rolls = realloc(dice->rolls, dice->capacity * sizeof(int));
    }

    for (int i = 0; i < NUM_DICE; ++i) {
        dice->rolls[dice->size++] = rand() % (dice->sides + 1);
    }
}

void dice_print(const dice_t *dice) {
    printf("Rolled: [");
    for (int i = 0; i < dice->size; ++i) {
        printf("%d", dice->rolls[i]);
        if (i != dice->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void dice_destroy(dice_t *dice) {
    free(dice->rolls);
}

int main(void) {
    srand(time(NULL));

    dice_t my_dice;
    dice_init(&my_dice);

    for (int i = 0; i < 5; ++i) {
        dice_roll(&my_dice);
        dice_print(&my_dice);
    }

    dice_destroy(&my_dice);

    return EXIT_SUCCESS;
}