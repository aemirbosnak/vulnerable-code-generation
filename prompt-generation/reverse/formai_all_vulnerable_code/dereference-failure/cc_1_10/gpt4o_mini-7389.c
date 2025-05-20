//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_DICE 10

void print_banner() {
    printf("===================================\n");
    printf("   Welcome to the Cyber Dice Roller  \n");
    printf("===================================\n");
}

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
}

void print_instructions() {
    printf("Instructions:\n");
    printf("1. Enter the number of dice you want to roll (1-%d).\n", MAX_DICE);
    printf("2. Choose the type of dice: 4, 6, 8, 10, 12, or 20 sides.\n");
    printf("3. Your rolls will be displayed in true cyberpunk fashion!\n");
    printf("4. Type 'exit' to leave the dice roller.\n");
}

int roll_dice(int sides) {
    return (rand() % sides) + 1; // Generates a random number between 1 and 'sides'
}

void display_results(int rolls[], int count) {
    printf("\n--- Roll Results ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll %d: %d\n", i + 1, rolls[i]);
    }
}

void handle_input(char *input) {
    int num_dice, dice_type;
    char *token = strtok(input, " ");
    
    if (strcmp(token, "exit") == 0) {
        printf("Exiting the Cyber Dice Roller. Stay safe in the neon shadows!\n");
        exit(0);
    }
    
    num_dice = atoi(token);
    
    token = strtok(NULL, " ");
    if (token != NULL) {
        dice_type = atoi(token);
        if (num_dice < 1 || num_dice > MAX_DICE || (dice_type != 4 && dice_type != 6 && dice_type != 8 && dice_type != 10 && dice_type != 12 && dice_type != 20)) {
            printf("Error: Invalid input. Please try again.\n");
            return;
        }

        int rolls[MAX_DICE] = {0};

        printf("Rolling %d d%d...\n", num_dice, dice_type);
        for (int i = 0; i < num_dice; i++) {
            rolls[i] = roll_dice(dice_type);
        }

        display_results(rolls, num_dice);
    } else {
        printf("Error: Please specify the type of dice!\n");
    }
}

int main() {
    char input[50];

    srand(time(0)); // Seed for random number generator
    clear_screen();
    print_banner();
    print_instructions();

    while (1) {
        printf("\nEnter your command (e.g. '3 6' to roll 3 six-sided dice): ");
        fgets(input, sizeof(input), stdin);
        strtok(input, "\n"); // Remove newline character
        handle_input(input);
    }

    return 0;
}