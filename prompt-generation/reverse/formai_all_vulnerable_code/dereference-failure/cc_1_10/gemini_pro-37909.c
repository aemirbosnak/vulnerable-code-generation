//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICE_SIZE 6
#define DICE_MAX  (DICE_SIZE - 1)

struct Dice {
    int sides;
    char *name;
    int (*roll)(struct Dice *);
};

int roll_simple(struct Dice *d) {
    return random() % d->sides;
}

int roll_weighted(struct Dice *d) {
    int x = random() % (d->sides + d->sides);
    return x % d->sides;
}

int roll_explode(struct Dice *d) {
    int result = roll_simple(d);
    while (result == DICE_MAX) {
        result += roll_simple(d);
    }
    return result;
}

int roll_disadvantage(struct Dice *d) {
    return (roll_simple(d) < roll_simple(d)) ? roll_simple(d) : 0;
}

int roll_advantage(struct Dice *d) {
    return (roll_simple(d) > roll_simple(d)) ? roll_simple(d) : 0;
}

struct Dice *create_dice(int sides, char *name, int (*roll)(struct Dice *)) {
    struct Dice *d = malloc(sizeof(struct Dice));
    d->sides = sides;
    d->name = strdup(name);
    d->roll = roll;
    return d;
}

void destroy_dice(struct Dice *d) {
    free(d->name);
    free(d);
}

int main(int argc, char **argv) {
    struct Dice *d1 = create_dice(DICE_SIZE, "d6", roll_simple);
    struct Dice *d2 = create_dice(4, "d4", roll_weighted);
    struct Dice *d3 = create_dice(DICE_SIZE, "d6", roll_explode);
    struct Dice *d4 = create_dice(DICE_SIZE, "d6", roll_disadvantage);
    struct Dice *d5 = create_dice(DICE_SIZE, "d6", roll_advantage);

    printf("%s: %d\n", d1->name, d1->roll(d1));
    printf("%s: %d\n", d2->name, d2->roll(d2));
    printf("%s: %d\n", d3->name, d3->roll(d3));
    printf("%s: %d\n", d4->name, d4->roll(d4));
    printf("%s: %d\n", d5->name, d5->roll(d5));

    destroy_dice(d1);
    destroy_dice(d2);
    destroy_dice(d3);
    destroy_dice(d4);
    destroy_dice(d5);

    return 0;
}