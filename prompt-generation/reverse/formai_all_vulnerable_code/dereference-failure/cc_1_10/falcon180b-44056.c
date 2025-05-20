//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number_of_dice;
    int sides_per_die;
    int roll_count;
    int i, j, k;
    int *dice_rolls;
    int sum = 0;
    double average;
    char play_again;

    srand(time(NULL));

    // Prompt the user for the number of dice and sides per die
    printf("Enter the number of dice: ");
    scanf("%d", &number_of_dice);
    printf("Enter the number of sides per die: ");
    scanf("%d", &sides_per_die);

    // Allocate memory for the dice rolls
    dice_rolls = (int*) malloc(number_of_dice * sizeof(int));

    // Roll the dice and calculate the sum
    for (i = 0; i < number_of_dice; i++) {
        dice_rolls[i] = rand() % sides_per_die + 1;
        sum += dice_rolls[i];
    }

    // Print the results
    printf("You rolled %d dice with %d sides each.\n", number_of_dice, sides_per_die);
    printf("The dice rolls are: ");
    for (i = 0; i < number_of_dice; i++) {
        printf("%d ", dice_rolls[i]);
    }
    printf("\nThe total is %d.\n", sum);

    // Calculate the average
    average = (double) sum / number_of_dice;
    printf("The average is %.2f.\n", average);

    // Ask the user if they want to play again
    printf("Do you want to play again? (y/n) ");
    scanf(" %c", &play_again);

    // Free the memory allocated for the dice rolls
    free(dice_rolls);

    if (play_again == 'y' || play_again == 'Y') {
        main();
    } else {
        return 0;
    }
}