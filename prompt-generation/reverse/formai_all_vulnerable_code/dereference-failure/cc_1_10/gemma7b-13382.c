//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define MAX_GUESSES 5

char **words = NULL;
char **guesses = NULL;
int current_word_index = 0;
int current_guess_index = 0;
int game_state = 0;

void initialize_game() {
    words = malloc(MAX_WORDS * sizeof(char *));
    guesses = malloc(MAX_GUESSES * sizeof(char *));

    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = malloc(20 * sizeof(char));
    }

    for (int i = 0; i < MAX_GUESSES; i++) {
        guesses[i] = malloc(20 * sizeof(char));
    }

    srand(time(NULL));
    current_word_index = rand() % MAX_WORDS;
    current_guess_index = 0;
    game_state = 1;
}

void play_game() {
    printf("Current word: %s\n", words[current_word_index]);

    for (int i = 0; i < MAX_GUESSES; i++) {
        guesses[current_guess_index][0] = '\0';
        printf("Guess word: ");
        scanf("%s", guesses[current_guess_index]);

        if (strcmp(guesses[current_guess_index], words[current_word_index]) == 0) {
            game_state = 2;
            break;
        } else if (guesses[current_guess_index][0] != '\0') {
            printf("Incorrect guess.\n");
        }

        current_guess_index++;
    }

    if (game_state == 2) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lose. The answer was: %s\n", words[current_word_index]);
    }
}

int main() {
    initialize_game();
    play_game();

    return 0;
}