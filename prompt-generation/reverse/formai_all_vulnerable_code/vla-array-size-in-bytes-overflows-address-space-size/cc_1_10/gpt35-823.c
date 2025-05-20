//FormAI DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rollCount, diceSides, i, j;
    int *rolls;
    char choice;

    srand(time(NULL)); // initialize random seed

    printf("Welcome to Dice Roller!\n");

    do {
        printf("\nHow many times would you like to roll the dice? ");
        scanf("%d", &rollCount);

        printf("How many sides do your dice have? ");
        scanf("%d", &diceSides);

        rolls = (int*)calloc(rollCount, sizeof(int)); // allocate memory for storing rolls

        printf("\nRolling the dice...\n");

        for (i = 0; i < rollCount; i++) {
            rolls[i] = (rand() % diceSides) + 1; // generate random number between 1 and diceSides
            printf("Roll %d: %d\n", i+1, rolls[i]);
        }

        printf("\nWould you like to view the statistics of the rolls? (y/n) ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice == 'y') {

            printf("\nRolls statistics:\n");
            printf("-----------------\n");

            // calculate frequency of each dice roll
            int frequency[diceSides];
            for (i = 0; i < diceSides; i++) {
                frequency[i] = 0;
            }
            for (i = 0; i < rollCount; i++) {
                frequency[rolls[i]-1]++;
            }

            // display frequency table
            printf("| Dice Roll | Frequency |\n");
            for (i = 0; i < diceSides; i++) {
                printf("|     %d     |     %d     |\n", i+1, frequency[i]);
            }

            // calculate and display other statistics
            int sum = 0;
            int highest = rolls[0];
            int lowest = rolls[0];
            for (i = 0; i < rollCount; i++) {
                sum += rolls[i];
                if (rolls[i] > highest) {
                    highest = rolls[i];
                }
                if (rolls[i] < lowest) {
                    lowest = rolls[i];
                }
            }
            float average = (float)sum / rollCount;

            printf("\nSum of rolls: %d\n", sum);
            printf("Average roll: %.2f\n", average);
            printf("Highest roll: %d\n", highest);
            printf("Lowest roll: %d\n", lowest);

        }

        free(rolls); // free allocated memory

        printf("\nWould you like to roll the dice again? (y/n) ");
        scanf(" %c", &choice);
        choice = tolower(choice);

    } while (choice == 'y');

    return 0;
}