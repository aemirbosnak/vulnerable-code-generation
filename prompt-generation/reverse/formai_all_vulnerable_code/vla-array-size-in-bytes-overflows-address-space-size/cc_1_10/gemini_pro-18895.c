//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inquire_for_dice(void) {
    printf("How many dice would you like to roll? ");
    int num_dice = 0;
    while (scanf("%d", &num_dice) != 1 || num_dice < 1) {
        printf("Please enter a positive number: ");
        while (getchar() != '\n')
            ;  // flush input buffer
    }
    printf("Rolling %d dice...\n", num_dice);
}

void display_roll(int num_dice, int *rolls) {
    printf("Your roll: ");
    for (int i = 0; i < num_dice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
}

void inquire_for_reroll(void) {
    printf("Do you want to reroll any dice? (y/n) ");
    char response = '\0';
    while (response != 'y' && response != 'n') {
        if (scanf(" %c", &response) != 1) {
            printf("Invalid input. Please enter 'y' or 'n': ");
            while (getchar() != '\n')
                ;  // flush input buffer
            response = '\0';
        }
    }
    printf("\n");
    if (response == 'y') {
        printf("Which dice would you like to reroll? (enter their indices, starting with 1) ");
    }
}

void reroll_dice(int num_dice, int *rolls, int *indices, int num_indices) {
    for (int i = 0; i < num_indices; i++) {
        if (indices[i] < 1 || indices[i] > num_dice) {
            printf("Invalid index %d. Please enter a valid index between 1 and %d: ", indices[i], num_dice);
            while (scanf("%d", &indices[i]) != 1 || indices[i] < 1 || indices[i] > num_dice)
                ;
        }
    }
    printf("Rerolling dice at indices: ");
    for (int i = 0; i < num_indices; i++) {
        printf("%d ", indices[i]);
        rolls[indices[i] - 1] = rand() % 6 + 1;
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    inquire_for_dice();
    int num_dice = 0;
    scanf("%d", &num_dice);
    int rolls[num_dice];
    for (int i = 0; i < num_dice; i++) {
        rolls[i] = rand() % 6 + 1;
    }
    display_roll(num_dice, rolls);
    inquire_for_reroll();
    char response = '\0';
    scanf(" %c", &response);
    if (response == 'y') {
        int num_indices = 0;
        printf("How many dice would you like to reroll? ");
        scanf("%d", &num_indices);
        int indices[num_indices];
        for (int i = 0; i < num_indices; i++) {
            printf("Enter the index of the %dth die to reroll: ", i + 1);
            scanf("%d", &indices[i]);
        }
        reroll_dice(num_dice, rolls, indices, num_indices);
        display_roll(num_dice, rolls);
    }
    return 0;
}