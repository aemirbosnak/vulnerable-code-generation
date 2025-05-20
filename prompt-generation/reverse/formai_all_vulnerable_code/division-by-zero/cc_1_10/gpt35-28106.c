//FormAI DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int diceSide;
    int diceRoll;
    int rollAgain;
    int i;
    srand(time(0)); //Setting seed for random number generation
    
    printf("\nWelcome to the Dice Roller!\n");
    printf("Enter the number of sides for the dice you want to roll: ");
    scanf("%d", &diceSide);
    printf("\n");
    
    do
    {
        diceRoll = rand() % diceSide + 1; //Generating random number between 1 and the number of sides
        printf("You rolled a %d!\n\n", diceRoll);
        
        printf("Do you want to roll again? (1 for YES, 0 for NO)\n");
        scanf("%d", &rollAgain);
        printf("\n");
        
        if(rollAgain != 0 && rollAgain != 1) //Checking for invalid input
        {
            printf("Invalid input! Please enter 1 to roll again or 0 to exit.\n\n");
            continue;
        }
        else if(rollAgain == 1) //Printing out an enthusiastic message each time the user chooses to roll again
        {
            printf("Awesome, let's roll again!\n\n");
            for(i = 0; i < 3; i++)
            {
                printf("Rolling");
                fflush(stdout);
                printf(".");
                fflush(stdout);
                printf(".");
                fflush(stdout);
                printf(".");
                fflush(stdout);
                printf("\n");
                sleep(1);
            }
            printf("\n");
        }
        else //Printing a parting message
        {
            printf("Thanks for rolling with us! Come back again soon.\n");
        }
    } while(rollAgain == 1); //Looping as long as the user wants to roll again
    
    return 0;
}