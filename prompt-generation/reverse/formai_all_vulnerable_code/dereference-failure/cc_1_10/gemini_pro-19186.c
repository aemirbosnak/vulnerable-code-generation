//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct dice {
    int sides;
    int rolls;
    int values[100];
} dice;

dice* create_dice(int sides) {
    dice* new_dice = malloc(sizeof(dice));
    new_dice->sides = sides;
    new_dice->rolls = 0;
    return new_dice;
}

void roll_dice(dice* dices, int num_rolls) {
    for (int i = 0; i < num_rolls; i++) {
        dices->values[dices->rolls++] = rand() % dices->sides + 1;
    }
}

int main() {
    srand(time(NULL));

    int num_dices;
    printf("Enter the number of dices: ");
    scanf("%d", &num_dices);

    dice** dices = malloc(sizeof(dice*) * num_dices);
    for (int i = 0; i < num_dices; i++) {
        int sides;
        printf("Enter the number of sides for dice %d: ", i + 1);
        scanf("%d", &sides);
        dices[i] = create_dice(sides);
    }

    int num_rolls;
    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    for (int i = 0; i < num_dices; i++) {
        roll_dice(dices[i], num_rolls);
    }

    printf("\nDice Rolling Results:\n");
    for (int i = 0; i < num_dices; i++) {
        printf("Dice %d:\n", i + 1);
        for (int j = 0; j < dices[i]->rolls; j++) {
            printf("%d ", dices[i]->values[j]);
        }
        printf("\n");
    }

    return 0;
}