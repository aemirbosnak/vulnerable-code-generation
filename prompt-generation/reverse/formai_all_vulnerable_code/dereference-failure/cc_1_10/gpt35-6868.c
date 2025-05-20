//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int numRolls, rollCount, diceCount, diceSize;
   int i, j, totalRolls = 0, rollSum = 0, successCount = 0;
   int* rolls = NULL;
   int** diceResults = NULL;

   // Get user inputs
   printf("How many times would you like to roll the dice? ");
   scanf("%d", &numRolls);

   printf("How many dice would you like to roll? ");
   scanf("%d", &diceCount);

   printf("What size dice would you like to roll? ");
   scanf("%d", &diceSize);

   // Allocate dynamic memory for arrays
   rolls = (int*)calloc(numRolls, sizeof(int));
   diceResults = (int**)calloc(numRolls, sizeof(int*));
   for (i = 0; i < numRolls; i++)
       diceResults[i] = (int*)calloc(diceCount, sizeof(int));

   // Seed random number generator
   srand((unsigned int)time(NULL));

   // Loop through each roll
   for (rollCount = 0; rollCount < numRolls; rollCount++) {
       // Roll each die
       for (i = 0; i < diceCount; i++){
           diceResults[rollCount][i] = rand() % diceSize + 1;

           // Add up roll results
           rolls[rollCount] += diceResults[rollCount][i];
       }

       // Keep track of sum and total rolls
       rollSum += rolls[rollCount];
       totalRolls += diceCount;

       // Check if roll was successful (assuming success if sum is greater than diceCount * (diceSize / 2))
       if (rolls[rollCount] > (diceCount * (diceSize / 2)))
           successCount++;

       // Print out individual roll results
       printf("Roll %d: [ ", rollCount + 1);
       for (j = 0; j < diceCount; j++)
           printf("%d ", diceResults[rollCount][j]);
       printf("] = %d\n", rolls[rollCount]);
   }

   // Calculate average and success rate
   float average = ((float)rollSum) / totalRolls;
   float successRate = ((float)successCount) / numRolls;

   // Print out overall results
   printf("\nTotal Rolls: %d\n", totalRolls);
   printf("Average Roll: %.2f\n", average);
   printf("Success Rate: %.2f%%\n", successRate * 100);

   // Free dynamic memory
   free(rolls);
   for (i = 0; i < numRolls; i++)
       free(diceResults[i]);
   free(diceResults);

   return 0;
}