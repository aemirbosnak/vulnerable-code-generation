//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 10
#define MAX_SIDES 1000

int main() {
    int dice[MAX_DICE];
    int sides[MAX_DICE];
    int num_dice;
    int num_sides;
    int i;
    int j;
    int sum;
    int min;
    int max;
    int range;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides for each die: ");
    scanf("%d", &num_sides);

    for (i = 0; i < num_dice; i++) {
        dice[i] = rand() % num_sides + 1;
        sides[i] = num_sides;
    }

    sum = 0;
    min = dice[0];
    max = dice[0];
    for (i = 0; i < num_dice; i++) {
        sum += dice[i];
        if (dice[i] < min) {
            min = dice[i];
        }
        if (dice[i] > max) {
            max = dice[i];
        }
    }

    range = max - min + 1;

    printf("The dice rolled: ");
    for (i = 0; i < num_dice; i++) {
        printf("%d ", dice[i]);
    }
    printf("\n");

    printf("The sum of the dice is: %d\n", sum);
    printf("The minimum value rolled was: %d\n", min);
    printf("The maximum value rolled was: %d\n", max);
    printf("The range of the values rolled was: %d\n", range);

    return 0;
}