//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIDES 100
#define MAX_DICE 100

int main()
{
    int num_dice, num_sides, i, j, roll_count = 0;
    int *dice_values = NULL;
    double avg_roll;
    char play_again;

    srand(time(NULL));

    //Initialize the number of dice and sides
    num_dice = 1;
    num_sides = 6;

    //Allocate memory for dice values
    dice_values = (int*)malloc(num_dice * sizeof(int));

    do
    {
        //Roll the dice
        for (i = 0; i < num_dice; i++)
        {
            dice_values[i] = rand() % num_sides + 1;
        }

        //Print the results
        printf("Rolling %d %d-sided dice:\n", num_dice, num_sides);
        for (i = 0; i < num_dice; i++)
        {
            printf("%d ", dice_values[i]);
        }
        printf("\n");

        //Calculate the average roll
        avg_roll = (double)roll_count / num_dice;
        printf("Average roll: %.2f\n", avg_roll);

        //Ask the user if they want to play again
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    //Free the memory allocated for dice values
    free(dice_values);

    return 0;
}