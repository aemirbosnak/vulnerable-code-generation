//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORDS_PER_ROW 5

char **words;

void init_game() {
    words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = malloc(WORDS_PER_ROW * sizeof(char));
    }
    srand(time(NULL));
}

void generate_words() {
    for (int i = 0; i < MAX_WORDS; i++) {
        for (int j = 0; j < WORDS_PER_ROW; j++) {
            words[i][j] = rand() % 26 + 'a';
        }
    }
}

void play_game() {
    int guess_word_index = rand() % MAX_WORDS;
    char guess_word[WORDS_PER_ROW] = "";
    for (int i = 0; i < WORDS_PER_ROW; i++) {
        guess_word[i] = '_';
    }
    guess_word[WORDS_PER_ROW - 1] = '\0';

    printf("Guess the word: %s\n", guess_word);

    char guess_letter;
    int guess_letter_count = 0;
    while (guess_letter_count < WORDS_PER_ROW && guess_word[guess_letter_count] != guess_word[guess_word_index]) {
        guess_letter = getchar();
        guess_letter_count++;

        if (guess_letter_count > 0) {
            printf("Previous guess: %c\n", guess_word[guess_letter_count - 1]);
        }

        if (guess_letter >= 'a' && guess_letter <= 'z') {
            guess_word[guess_letter_count] = guess_letter;
            printf("Current guess: %s\n", guess_word);
        } else {
            printf("Invalid input.\n");
        }
    }

    if (guess_word[guess_word_index] == guess_word[guess_letter_count - 1]) {
        printf("Congratulations! You guessed the word: %s\n", guess_word);
    } else {
        printf("Sorry, you lost. The word was: %s\n", words[guess_word_index]);
    }
}

int main() {
    init_game();
    generate_words();
    play_game();

    return 0;
}