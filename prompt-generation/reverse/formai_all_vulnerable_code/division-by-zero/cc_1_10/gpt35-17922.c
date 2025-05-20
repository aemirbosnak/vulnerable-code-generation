//FormAI DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides = 4;
    int rolls = 1;
    char shape = '*';

    printf("Welcome to the Dice Roller!\n\n");

    printf("What shape would you like the dice to be? Enter 'S' for square or '*' for star: ");
    scanf("%c", &shape);

    if (shape == 'S') {
        printf("\nWhat size dice would you like? Enter the number of sides: ");
        scanf("%d", &sides);
    }
    else if (shape == '*') {
        printf("\nWhat size dice would you like? Enter the number of points: ");
        scanf("%d", &sides);
    }
    else {
        printf("\nInvalid shape. The dice will default to a square.\n");
    }

    printf("\nHow many rolls would you like to make? ");
    scanf("%d", &rolls);

    srand(time(NULL));

    printf("\nRolling %d %c-shaped dice with %d sides...\n\n", rolls, shape, sides);

    int total = 0;

    for (int i = 1; i <= rolls; i++) {
        int roll = (rand() % sides) + 1;
        printf("Roll %d: [", i);

        if (shape == 'S') {
            for (int j = 0; j < sides; j++) {
                if (j == (sides/2)) {
                    printf("%d", roll);
                }
                else {
                    printf(" ");
                }
            }
        }
        else if (shape == '*') {
            for (int j = 0; j < sides; j++) {
                if (j == ((sides - 1)/2)) {
                    printf("%d", roll);
                }
                else {
                    printf("%c", shape);
                }
            }
        }

        printf("]\n");
        total += roll;
    }

    printf("\nTotal: %d\n", total);

    return 0;
}