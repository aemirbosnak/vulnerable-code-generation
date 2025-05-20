//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct
{
    int num_dice;
    int num_sides;
    int *rolls;
} dice_t;

void roll_dice(dice_t *dice)
{
    int i;
    for (i = 0; i < dice->num_dice; i++)
    {
        dice->rolls[i] = rand() % dice->num_sides + 1;
    }
}

void print_dice(dice_t *dice)
{
    int i;
    for (i = 0; i < dice->num_dice; i++)
    {
        printf("%d ", dice->rolls[i]);
    }
    printf("\n");
}

int main()
{
    dice_t dice;
    int num_dice, num_sides;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &num_dice);

    printf("Enter the number of sides for each die: ");
    scanf("%d", &num_sides);

    dice.num_dice = num_dice;
    dice.num_sides = num_sides;
    dice.rolls = malloc(num_dice * sizeof(int));

    roll_dice(&dice);
    print_dice(&dice);

    free(dice.rolls);

    return 0;
}