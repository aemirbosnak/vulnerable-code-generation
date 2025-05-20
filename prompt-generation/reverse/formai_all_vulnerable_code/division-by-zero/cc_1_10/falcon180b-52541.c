//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

int main() {
    int num_dice, num_sides, total_rolls, i, j;
    int roll[MAX_DICE];
    char choice;
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n\n");

    printf("How many dice would you like to roll? (1-100) ");
    scanf("%d", &num_dice);

    printf("How many sides should each dice have? (1-1000) ");
    scanf("%d", &num_sides);

    printf("How many times would you like to roll the dice? ");
    scanf("%d", &total_rolls);

    printf("\n");

    for (i = 0; i < num_dice; i++) {
        printf("Dice %d: ", i+1);
        for (j = 0; j < total_rolls; j++) {
            roll[i*total_rolls+j] = rand() % num_sides + 1;
            printf("%d ", roll[i*total_rolls+j]);
        }
        printf("\n");
    }

    printf("\nWould you like to save the results to a file? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        FILE *fp;
        int k = 0;
        char filename[50];

        printf("\nEnter the filename: ");
        scanf("%s", filename);

        fp = fopen(filename, "w");

        if (fp == NULL) {
            printf("\nError opening file!");
        } else {
            for (i = 0; i < num_dice; i++) {
                for (j = 0; j < total_rolls; j++) {
                    fprintf(fp, "%d ", roll[i*total_rolls+j]);
                }
                fprintf(fp, "\n");
            }
            fclose(fp);
            printf("\nResults saved to file: %s", filename);
        }
    }

    return 0;
}