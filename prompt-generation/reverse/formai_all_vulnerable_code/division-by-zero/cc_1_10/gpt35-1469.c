//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// function declarations
int check_word(char *word, char letter, char *hidden_word);
int generate_random(int upper_bound);

int main() {
    char word[50], hidden_word[50], guess[2];
    int word_length, remaining_guesses = 7, i, revealed = 0, game_end = 0, num_guesses = 0;
    char letters_guessed[26];
    srand(time(NULL));

    printf("Welcome to the Love Hangman game!\n");
    
    // get a random word from file and store in 'word'
    FILE *f = fopen("romantic_words.txt", "r");
    int lines = 0;
    for (char c = getc(f); c != EOF; c = getc(f)) {
        if (c == '\n') lines++;
    }
    int random_line = generate_random(lines);
    rewind(f);
    for (i = 0; i <= random_line; i++) {
        fgets(word, 50, f);
    }
    fclose(f);

    // remove '\n' from the end of the word
    word_length = strlen(word);
    if (word[word_length-1] == '\n') {
        word_length--;
        word[word_length] = '\0';
    }

    // replace letters in 'word' with underscores and store in 'hidden_word'
    for (i = 0; i < word_length; i++) {
        if (word[i] == ' ') {
            hidden_word[i] = ' ';
        } else {
            hidden_word[i] = '_';
        }
    }
    hidden_word[word_length] = '\0';

    // game loop
    while (remaining_guesses > 0 && game_end == 0) {
        // display status
        printf("Word: %s\n", hidden_word);
        printf("Guesses remaining: %d\n", remaining_guesses);
        printf("Letters guessed: ");
        for (i = 0; i < num_guesses; i++) {
            printf("%c ", letters_guessed[i]);
        }
        printf("\n");

        // prompt for guess and validate input
        printf("Guess a letter: ");
        fgets(guess, 2, stdin);
        while (isspace(guess[0]) || isdigit(guess[0]) || strchr(letters_guessed, guess[0]) != NULL) {
            printf("Invalid guess. Please guess a letter that you have not yet guessed: ");
            fgets(guess, 2, stdin);
        }

        // update letters guessed and check guess against word
        letters_guessed[num_guesses] = guess[0];
        num_guesses++;
        letters_guessed[num_guesses] = '\0';
        if (check_word(word, guess[0], hidden_word) == 0) {
            remaining_guesses--;
        }

        // check if the word has been fully revealed or the player has run out of guesses
        revealed = 1;
        for (i = 0; i < word_length; i++) {
            if (hidden_word[i] == '_') {
                revealed = 0;
                break;
            }
        }
        if (revealed == 1) {
            printf("Congratulations, you revealed the word!\n");
            printf("The word was: %s\n", word);
            game_end = 1;
        } else if (remaining_guesses == 0) {
            printf("I'm sorry, you have run out of guesses.\n");
            printf("The word was: %s\n", word);
            game_end = 1;
        }
    }

    printf("Thank you for playing the Love Hangman game!\n");

    return 0;
}

// check if the guess letter is in the word and update 'hidden_word' if so
int check_word(char *word, char letter, char *hidden_word) {
    int i, found_letter = 0;
    for (i = 0; i < strlen(word); i++) {
        if (word[i] == letter) {
            hidden_word[i] = letter;
            found_letter = 1;
        }
    }
    return found_letter;
}

// generate a random number between 0 and 'upper_bound'
int generate_random(int upper_bound) {
    return rand() % upper_bound;
}