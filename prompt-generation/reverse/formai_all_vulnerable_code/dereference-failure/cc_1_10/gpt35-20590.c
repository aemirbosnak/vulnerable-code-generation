//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char* WORDS[] = {"computer", "keyboard", "monitor", "mouse", "printer", "scanner", "software", "hardware"};
const int NUM_WORDS = 8;

int main() {
    srand(time(NULL)); // initialize random seed

    int score = 0;
    char guess[20];
    int play_again = 1;

    printf("\nWelcome to Word Jumble! Unscramble the letters to form a word.\n");

    while (play_again) {
        // pick a random word from the list of words
        const char* chosen_word = WORDS[rand() % NUM_WORDS];

        // scramble the letters of the chosen word
        char* scrambled_word = strdup(chosen_word); // make a copy of the chosen word to scramble
        int len = strlen(scrambled_word);
        for (int i = 0; i < len; i++) {
            int j = rand() % len;
            char temp = scrambled_word[i];
            scrambled_word[i] = scrambled_word[j];
            scrambled_word[j] = temp;
        }

        // play the game
        printf("\nThe scrambled word is: %s\n", scrambled_word);
        printf("Enter your guess: ");
        fgets(guess, 20, stdin);
        guess[strcspn(guess, "\n")] = '\0'; // remove newline character from guess

        if (strcmp(guess, chosen_word) == 0) {
            printf("Correct! You scored 1 point.\n");
            score++;
        } else {
            printf("Incorrect! The word was \"%s\".\n", chosen_word);
        }

        // ask if they want to play again
        printf("Your current score is %d.\n", score);
        printf("Play again? (y/n) ");
        char answer[2];
        fgets(answer, 2, stdin);
        answer[strcspn(answer, "\n")] = '\0'; // remove newline character from answer

        if (strcmp(answer, "n") == 0) {
            play_again = 0;
        }
    }

    printf("\nThank you for playing Word Jumble! Your final score was %d.\n", score);

    return 0;
}