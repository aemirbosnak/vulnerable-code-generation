//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIDES 100
#define MIN_SIDES 1

struct EnchantedDice {
    int sides;
    char *name;
};

void rollDice(struct EnchantedDice *dice) {
    printf("\nYou have rolled the %s dice...", dice->name);
    int roll = rand() % dice->sides + 1;
    printf("The result is: %d\n", roll);
}

void createDice(struct EnchantedDice *dice, int num_sides, const char *name) {
    dice->sides = num_sides;
    dice->name = malloc(strlen(name) + 1);
    strcpy(dice->name, name);
}

int main() {
    srand(time(NULL));

    struct EnchantedDice *dice1 = NULL;
    createDice(dice1, 6, "Golden Sun Die");
    rollDice(dice1);

    struct EnchantedDice *dice2 = NULL;
    createDice(dice2, 20, "Celestial Star Die");
    rollDice(dice2);

    struct EnchantedDice *dice3 = NULL;
    createDice(dice3, 10, "Fiery Dragon Die");
    rollDice(dice3);

    struct EnchantedDice *dice4 = NULL;
    createDice(dice4, 100, "Mystic Crystal Die");
    rollDice(dice4);

    free(dice1->name);
    free(dice2->name);
    free(dice3->name);
    free(dice4->name);
    free(dice1);
    free(dice2);
    free(dice3);
    free(dice4);

    return 0;
}