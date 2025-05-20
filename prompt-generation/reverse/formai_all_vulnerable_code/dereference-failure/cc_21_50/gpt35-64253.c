//FormAI DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int numDice, numFaces;
    int *diceResults; // pointer to int array for storing individual die roll results
    int i, j, totalRoll = 0;
    char reroll;

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Dice Roller.\n\n");

    // Input Validation for Number of Dice
    do
    {
        printf("Enter number of dice to roll (1-10): ");
        scanf("%d", &numDice);
        fflush(stdin); // clear input buffer

        if (numDice < 1 || numDice > 10)
        {
            printf("Invalid input. Please enter a number between 1 and 10.\n\n");
        }
    } while (numDice < 1 || numDice > 10);
  
    // Input Validation for Number of Faces
    do
    {
        printf("Enter number of faces per die (2-100): ");
        scanf("%d", &numFaces);
        fflush(stdin); // clear input buffer

        if (numFaces < 2 || numFaces > 100)
        {
            printf("Invalid input. Please enter a number between 2 and 100.\n\n");
        }
    } while (numFaces < 2 || numFaces > 100);

    diceResults = (int *) malloc(numDice * sizeof(int)); // allocate memory for the die results array

    printf("\n");

    // Roll each die and display results
    for (i = 0; i < numDice; i++)
    {
        diceResults[i] = rand() % numFaces + 1;
        printf("Die %d: %d\n", i+1, diceResults[i]);
        totalRoll += diceResults[i];
    }

    printf("\nTotal: %d\n", totalRoll);

    // Allow user to re-roll a specific die
    do
    {
        printf("\nWould you like to re-roll any dice? (y/n): ");
        scanf(" %c", &reroll);
        fflush(stdin); // clear input buffer

        if (reroll == 'y' || reroll == 'Y')
        {
            // Input Validation for Re-Roll Selection
            do
            {
                printf("\nEnter the number of the die to re-roll (1-%d): ", numDice);
                scanf("%d", &j);
                fflush(stdin); // clear input buffer
  
                if (j < 1 || j > numDice)
                {
                    printf("Invalid input. Please enter a number between 1 and %d.\n\n", numDice);
                }
            } while (j < 1 || j > numDice);

            diceResults[j-1] = rand() % numFaces + 1;
            printf("\nNew Result for Die %d: %d\n", j, diceResults[j-1]);

            totalRoll = 0;
            for (i = 0; i < numDice; i++)
            {
                totalRoll += diceResults[i];
            }
            printf("New Total: %d\n", totalRoll);
        }
        else if (reroll != 'n' && reroll != 'N')
        {
            printf("Invalid input. Please enter y or n.\n\n");
        }
    } while (reroll != 'n' && reroll != 'N');


    free(diceResults); // free memory used by die results array
    printf("\nThank you for using the Dice Roller!\n");

    return 0;
}