//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

char* words[MAX_WORDS];
int num_words;

int read_words_from_file(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    // Read words from file into array 'words'
    char buf[MAX_WORD_LENGTH];
    while (fgets(buf, MAX_WORD_LENGTH, fp) != NULL) {
        // Strip newline character from end of word
        buf[strcspn(buf, "\n")] = 0;
        words[num_words] = malloc(strlen(buf) + 1);
        strcpy(words[num_words], buf);
        num_words++;
    }

    fclose(fp);
    return 1;
}

char get_letter_guess() {
    char guess;
    printf("Guess a letter: ");
    guess = getchar();
    while (getchar() != '\n'); // Flush stdin
    return tolower(guess);
}

int play_hangman(char* word) {
    char* blanks = malloc(strlen(word) + 1);
    memset(blanks, '_', strlen(word));
    blanks[strlen(word)] = 0;
    int num_misses = 0;

    printf("Welcome to Hangman!\n");
    printf("The word is %s\n", blanks);

    while (1) {
        char guess = get_letter_guess();
        int correct_guess = 0;
        for (int i = 0; i < strlen(word); i++) {
            if (tolower(word[i]) == guess) {
                blanks[i] = word[i];
                correct_guess = 1;
            }
        }
        if (!correct_guess) {
            num_misses++;
        }
        printf("You have %d guesses left\n", 6 - num_misses);
        printf("The word is now %s\n", blanks);

        if (strcmp(word, blanks) == 0) {
            printf("Congratulations! You have won!\n");
            return 1;
        } else if (num_misses == 6) {
            printf("Sorry, you have lost! The word was %s\n", word);
            return 0;
        }
    }
}

int main() {
    char filename[] = "words.txt";
    if (!read_words_from_file(filename)) {
        return -1;
    }
    srand(time(NULL));
    int index = rand() % num_words;
    char* word = words[index];

    play_hangman(word);

    // Free dynamically allocated memory
    for (int i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}