//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice_sides, num_dice, i, j;
    int dice_rolls[100];

    printf("Welcome to the Dice Roller!\n");
    printf("How many sides do your dice have? ");
    scanf("%d", &dice_sides);
    printf("How many dice do you want to roll? ");
    scanf("%d", &num_dice);

    srand(time(NULL));
    for (i = 0; i < num_dice; i++)
    {
        dice_rolls[i] = rand() % dice_sides + 1;
    }

    printf("Your dice rolls are:\n");
    for (i = 0; i < num_dice; i++)
    {
        printf("%d ", dice_rolls[i]);
    }
    printf("\n");

    int sum = 0;
    for (i = 0; i < num_dice; i++)
    {
        sum += dice_rolls[i];
    }

    printf("The sum of your dice rolls is: %d\n", sum);

    int max = dice_rolls[0];
    int min = dice_rolls[0];
    for (i = 1; i < num_dice; i++)
    {
        if (dice_rolls[i] > max)
        {
            max = dice_rolls[i];
        }
        if (dice_rolls[i] < min)
        {
            min = dice_rolls[i];
        }
    }

    printf("The maximum value rolled was: %d\n", max);
    printf("The minimum value rolled was: %d\n", min);

    int mode_count = 0;
    int mode_value = 0;
    for (i = 0; i < dice_sides; i++)
    {
        int current_count = 0;
        for (j = 0; j < num_dice; j++)
        {
            if (dice_rolls[j] == i + 1)
            {
                current_count++;
            }
        }
        if (current_count > mode_count)
        {
            mode_count = current_count;
            mode_value = i + 1;
        }
    }

    if (mode_count == 1)
    {
        printf("There is no mode value.\n");
    }
    else
    {
        printf("The mode value is: %d\n", mode_value);
    }

    return 0;
}