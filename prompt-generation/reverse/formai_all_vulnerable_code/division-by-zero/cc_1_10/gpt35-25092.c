//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
int generateRandomNumber(int min, int max);
void playGame(int level);

int main(void) {
    int level;
    printf("Welcome to the Procedural Space Adventure game!\n\n");

    printf("Instructions: You will be given a series of challenges to complete in different levels as you travel through space.\n");
    printf("Each level gets progressively harder. Good luck!\n\n");

    printf("Choose your starting level (1-5): ");
    scanf("%d", &level);

    playGame(level);

    printf("\nCongratulations! You have completed all levels of the Procedural Space Adventure game.\n");
    printf("Thanks for playing!\n");

    return 0;
}

// function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// function to play the game at a given level
void playGame(int level) {
    int randomNumber, guess, chances;

    // set number of chances based on level
    if (level == 1) {
        chances = 5;
    } else if (level == 2) {
        chances = 4;
    } else if (level == 3) {
        chances = 3;
    } else if (level == 4) {
        chances = 2;
    } else {
        chances = 1;
    }

    printf("\nYou are now in Level %d.\n", level);

    // generate a random number for the user to guess
    randomNumber = generateRandomNumber(1, level * 10);

    printf("You have %d chances to guess the number between 1 and %d.\n", chances, level * 10);

    while (chances > 0) {
        printf("Guess the number: ");
        scanf("%d", &guess);

        if (guess == randomNumber) {
            printf("Congratulation! You have successfully guessed the number and have completed the level.\n");
            break;
        } else {
            printf("Incorrect, try again. You have %d chances left.\n", chances-1);
            chances--;
        }
    }

    if (chances == 0) {
        printf("Sorry, you have run out of chances. Game over.\n");
    }

    // ask user if they want to play again
    char choice;
    printf("Do you want to play again? (Y/N) ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        printf("\nNew game beginning.\n");
        playGame(level + 1);
    } else {
        printf("\nEnding game.\n");
    }
}